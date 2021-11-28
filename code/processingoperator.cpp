#include "processing.h"

Processing::Processing() // default constructor
{
    
}
Processing::Processing(const char *name) // constructor 2
{
    
    data_file_.open(name, std::ios_base::app);
    if (!data_file_.is_open()) // if file somehow doesn't open properly then exit
    {
        exit(EXIT_FAILURE);
    }
    else
    {
        int count{0};
        std::string value;
        std::string time;

      while(getline(data_file_, time, ',') && getline(data_file_, value, '\n'))
        {
            if (count != 0)
            {
                times_.push_back(stoi(time));
                gsr_values_.push_back(stoi(value));
            }
            count++;
        }    
    }

    data_file_.close();
    convert_to_eda();
    signal_filtration();
    signal_normalization();
}
Processing::~Processing() // destructor
{
    
}
void Processing::convert_to_eda()
{
    float temp;
    float ten_power = pow(10.0, 5.0);

    for (int i = 0; i < gsr_values_.size(); i++)
    {
        temp = ten_power/gsr_values_[i];
        eda_values_.push_back(temp);
    }
}
void Processing::signal_filtration()
{
    //filtration by moving average, because of time series 
    float k{10};//step
    float tmp_1;
    float tmp_2;
    int j{0};
    for (int i = 0; i < (eda_values_.size() - k); i++)
    {
        tmp_2 = 0;
        tmp_1 = 0;
        for (int i = 0; i < k ; i++)
        {
            tmp_2 += eda_values_[j];
            j += 1;
        }
        j = j - (k - 1);
        tmp_1 = (tmp_2/k)/eda_values_.size();
        eda_values_filtered_.push_back(tmp_1);
    }
}
void Processing::signal_normalization()
{

    std:: vector<float>::iterator min_value;
    std:: vector<float>::iterator max_value;

    min_value = std::min_element(eda_values_filtered_.begin(),eda_values_filtered_.end());
    max_value = std::max_element(eda_values_filtered_.begin(),eda_values_filtered_.end());

    float tmp{0};

    for (int i = 0; i < eda_values_filtered_.size(); i++)
    {   
        tmp = (eda_values_filtered_[i] - min_value[0])/(max_value[0] - min_value[0]);
        eda_values_normalized_.push_back(tmp);
    }
    trough_to_peak();
}
double Processing::mean()
{

    return 0;
}
void Processing::trough_to_peak()
{
    std::vector<float> frame_1;
    std::vector<float> frame_2;

    std:: vector<float>::iterator max_value_frame_1;
    std:: vector<float>::iterator max_value_frame_2;

    float tmp{0};

    for (int j = 0; j < eda_values_normalized_.size(); j+=10)
    {
        for (int i = 0; i < 20; i++) 
        {
            if ((j + 40) < eda_values_normalized_.size())
            {
                frame_1.push_back(eda_values_normalized_[j + i]);
                frame_2.push_back(eda_values_normalized_[j + i + 20]);
            }
        }
        if (j % 10 == 0)
        {
            max_value_frame_1 = std::max_element(frame_1.begin(),frame_1.end());
            max_value_frame_2 = std::max_element(frame_2.begin(),frame_2.end());
            diff_frame_.push_back(max_value_frame_2[0] - max_value_frame_1[0]);
            frame_1.clear();
            frame_2.clear();
        }
    }
    for (int i = 0; i < diff_frame_.size(); i++)
    {
        if (diff_frame_[i] > 0.2) 
        {
            trough_to_peak_values_.push_back(diff_frame_[i]);
            trough_to_peak_indices_.push_back(i * 10);
        }
    }
    std:: ofstream outFile;
    outFile.open("trough_to_peak.csv", std::ios_base::app);
    for (int i = 0; i < trough_to_peak_values_.size(); i++)
    {
        outFile << trough_to_peak_values_[i] <<"," << trough_to_peak_indices_[i] << std::endl;
    }
    outFile.close();
}
void Processing::save_to_csv()
{
    std:: ofstream outFile;
    outFile.open("eda_signal_filtered_k.csv", std::ios_base::app);
    for (int i = 0; i < eda_values_normalized_.size(); i++)
    {
        outFile << eda_values_normalized_[i] << "," << times_[i] << std::endl;
    }
    outFile.close();
}
std::ostream &operator<<(std::ostream &os, const std::vector<double> &values)
{
    for (auto const &i: values) {
        os << i << " ";
    }
    return os;
}
void Processing::print()
{

std:: cout << eda_values_[0] << std::endl;
}
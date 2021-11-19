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
        std::cout << tmp_1 << std::endl;
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
    
}
double Processing::mean()
{

    return 0;
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
void Processing::trough_to_peak()
{
    
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
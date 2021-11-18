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
}
Processing::~Processing() // destructor
{
    
}
void Processing::convert_to_eda()
{
    int temp;
    int ten_power = pow(10.0, 5.0);

    for (int i = 0; i < gsr_values_.size(); i++)
    {
        temp = ten_power/gsr_values_[i];
        std:: cout << temp << std::endl;
        eda_values_.push_back(temp);
    }

}
void Processing::signal_filtration()
{



}
void Processing::signal_normalization()
{

}
double Processing::mean()
{

    return 0;
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
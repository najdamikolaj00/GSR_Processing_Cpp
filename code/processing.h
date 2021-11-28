#ifndef PROCESSING_H_
#define PROCESSING_H_
#include <fstream>
#include <iostream>
#include <cstring>
#include <conio.h>
#include <vector>
#include<cmath>
#include<algorithm>

class Processing
{
    private:
        std:: vector<float> gsr_values_;
        std:: vector<int> times_;
        std:: ifstream data_file_;

        std:: vector<float> eda_values_;
        std:: vector<float> eda_values_filtered_; 
        std:: vector<float> eda_values_normalized_;

        std:: vector<float> diff_frame_;
        std:: vector<float> trough_to_peak_values_; 
        std:: vector<float> trough_to_peak_indices_;
    public:
        Processing();
        explicit Processing(const char *name);
        ~Processing();
        void convert_to_eda();
        void signal_filtration();
        void signal_normalization();
        static double mean();
        void save_to_csv();
        void trough_to_peak();
        void print();
};
#endif
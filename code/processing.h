#ifndef PROCESSING_H_
#define PROCESSING_H_
#include <fstream>
#include <iostream>
#include <cstring>
#include <conio.h>
#include <vector>
#include<cmath>

class Processing
{
    private:
        std:: vector<int> gsr_values_;
        std:: vector<int> times_;
        std:: ifstream data_file_;

        std:: vector<int> eda_values_;  
    public:
        Processing();
        explicit Processing(const char *name);
        ~Processing();
        void convert_to_eda();
        void signal_filtration();
        void signal_normalization();
        static double mean();
        void trough_to_peak();
        void print();
};
#endif
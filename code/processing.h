#ifndef PROCESSING_H_
#define PROCESSING_H_
#include <fstream>
#include <iostream>
#include <cstring>
#include <conio.h>
#include <vector>

class Processing
{
    private:
        std:: vector<int> values_;
        std:: vector<int> times_;
        std:: ifstream data_file_;  
    public:
        Processing();
        explicit Processing(const char *name);
        ~Processing();
        void convert_gsr();
        void signal_filtration();
        void signal_normalization();
        static double mean();
        void trough_to_peak();
        void print();
};
#endif
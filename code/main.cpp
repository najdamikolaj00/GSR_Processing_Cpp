// Main program is used to create an object of 
// the specified data structure of the given GSR dataset
#include "processingoperator.cpp"
//#include "plotoperator.cpp"

int main()
{
    Processing object("gsr_samples.csv");
    object.save_to_csv();

    return 0;
}
#ifndef PLOT_H_
#define PLOT_H_
#include "processing.h"

class Plot: public virtual Processing
{
    private:
    
    public:
        Plot();
        explicit Plot();
        ~Plot();
        void request();
};
#endif
/*
Author: Ben Wilichowski
Purpose: 
Date: 1/24/2023
Class: BIEN4290
*/
#ifndef VARNAME
#define VARNAME

#include "bwilichowski_dataset.hpp"

#include <math.h>
#include <vector>
#include <iostream>
#include <fstream>

namespace SignalUtils{ //namespace
    class mySignalUtils{//class name (constructor matches namespace)
        public: 
            mySignalUtils();//constructor

            static int peak_value(std::unordered_map<std::string, std::vector<float>>){
                return 0;
            } 
            
    };
}


#endif
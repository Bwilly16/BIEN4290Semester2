/*
Author: Ben Wilichowski
Purpose: The purpose of this lab is to
Date: 2/7/2023
Class: BIEN4290
*/

#ifndef VARNAME
#define VARNAME

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>

namespace vectorops{ //namespace
    //class name (constructor matches namespace)
    class myvectorops{
        public:
           myvectorops(); //constructor def. 
           void sumstuff(std::vector<float>*, std::vector<float>*, std::vector<float>*);
           void substuff(std::vector<float>*, std::vector<float>*, std::vector<float>*, uint);
           void multstuff(int, std::vector<float>*, std::vector<float>*);
           float Means(std::vector<float>*, uint);
           void norms(std::vector<float>*, float, std::vector<float>*, uint);
           void logintensity(std::vector<float>*, std::vector<float>*, std::vector<float>*, uint); //also write intensity to arg5 file specified
    };
}

#endif
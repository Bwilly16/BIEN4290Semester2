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
#include <vector>

namespace vectorops{ //namespace
    //class name (constructor matches namespace)
    class myvectorops{
        public:
           myvectorops(); //constructor def. 
           std::vector<float> sumstuff(std::vector<float>);
           std::vector<float> substuff(std::vector<float>, std::vector<float>);
           std::vector<float> multstuff(int, std::vector<float>);
  
    };
}

#endif
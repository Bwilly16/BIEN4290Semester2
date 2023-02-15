/*
Author: Ben Wilichowski
Purpose: The purpose of this lab is to
Date: 2/7/2023
Class: BIEN4290
*/

#ifndef VARNAME1
#define VARNAME1

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <math.h>

namespace preproc{ //namespace
    //class name (constructor matches namespace)
    class mypreproc{
        public:
           mypreproc(std::string, std::string, std::string, std::string, std::string, uint); //constructor def. 
           void readfiles(std::vector<float>*, std::vector<float>*, std::vector<float>*, std::vector<float>*);
           
        private:
            std::string arg1, arg2, arg3, arg4, arg5;
            uint arg6;


    };
}

#endif
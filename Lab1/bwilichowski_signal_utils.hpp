/*
Author: Ben Wilichowski
Purpose: 
Date: 1/24/2023
Class: BIEN4290
*/
#ifndef VARNAME
#define VARNAME

//#include "bwilichowski_dataset.hpp"

#include <math.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include <algorithm>

namespace SignalUtils{ //namespace
    class mySignalUtils{//class name (constructor matches namespace)
        public: 
            mySignalUtils();//constructor

            static int peak_value(std::unordered_map<std::string, std::vector<float>> mymap){
                if(IsEmpty(mymap))
                {
                    
                }
                std::cout << mymap[0][15] << std::endl;
                return 0;
            } 
            
    };
}


#endif
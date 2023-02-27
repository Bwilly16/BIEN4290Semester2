/*
Author: Ben Wilichowski
Purpose: The purpose of this lab is to
Date: 2/21/2023
Class: BIEN4290
*/

#ifndef VARNAME2
#define VARNAME2

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

namespace cluster{ //namespace
    //class name (constructor matches namespace)
    class mycluster{
        public:
           mycluster(); //constructor def. 
           float distfunc(float); //function to find distance from data point to cluster mean
           void setname(std::string);
           void setmean(float);
           float getmean();
           void put_mean(std::vector<float>*);
           float get_newmean();
           std::string getname();
           std::vector<float> cluster_data;//vector of data points associated with cluster
    

        private:
            std::string objname; //holds name of object
            float objmean; //holds mean of object
            float newmean;
            
    };
}

#endif
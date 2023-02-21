/*
Author: Ben Wilichowski
Purpose: The purpose of this lab is to
Date: 2/21/2023
Class: BIEN4290
*/

#ifndef VARNAME2
#define VARNAME2

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>

namespace cluster{ //namespace
    //class name (constructor matches namespace)
    class mycluster{
        public:
           mycluster(); //constructor def. 
           void distfunc(); //function to find distance from data point to cluster mean
           void setname();
           void getname();

        private:
            std::string objname; //holds name of object
            float objmean; //holds mean of object
            std::vector<float> datapcluster; //vector to hold dps associated with cluster
    };
}

#endif
/*
Author: Ben Wilichowski
Purpose: 
Date: 1/24/2023
Class: BIEN4290
*/

#include <math.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

namespace Dataset{ //namespace
    //class name (constructor matches namespace)
    class myDataset{
        public:
            myDataset(std::string file); //constructor def. 
            void load_dataset();  
            std::unordered_map<std::string, std::vector<float>> GetMap();
           

        private:
            std::string file_name; //do i set the file location here?
            std::unordered_map<std::string, std::vector<float>> cols;
    };
}
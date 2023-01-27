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

namespace Dataset{ //namespace
    //class name (constructor matches namespace)
    class myDataset{
        public:
            myDataset(std::string file); //constructor def. 
            void load_dataset();  
            void set_name();
            void get_name();


        private:
            std::string file_name;
            std::unordered_map<std::string, std::vector<float>> umap;
    };
}
/*
Author: Ben Wilichowski
Purpose:
Date: 1/24/2023
Class: BIEN 4290
*/
#include "bwilichowski_dataset.hpp"

Dataset::myDataset::myDataset(std::string filestats){
    this->file_name = filestats;
}


void Dataset::myDataset::load_dataset(){
    std::ifstream listStream;//could call the file here
    std::string red, orange, yellow, green, blue;//strings to hold columns
    std::string header, line; //identifiers to hold what is being read
    std::array<std::string, 5> HeaderList; //holds all header names in an array
    std::vector<float> col, hold1, hold2, hold3, hold4; //holds column values into these vectors
    std::vector<float> headhold1, headhold2, headhold3, headhold4, headhold5, colhold1, colhold2, colhold3, colhold4, colhold5; //if used, holding keys for header names
    std::numeric_limits<double>::quiet_NaN(); 
    int i = 0;

    //load in the file
	listStream.open(this->file_name); //gotta figure out what files to open, probably a file path??
    // if (listStream.is_open()){
    //     std::cout << "FileOpen"<< std::endl;
    // }
    // else{
    //     std::cout << "File Not open" << std::endl;
    // }

    //loads headers in to HeaderList[] array
    getline(listStream, header);
    std::stringstream sstream(header);
    
    for(i=0;i<5;i++){
        getline(sstream, header, ',');
        HeaderList[i] = header;
        //std::cout << HeaderList[i] << std::endl; //this worked
    }
        

        //loads columns into col vector
             while(getline(listStream, line)){
                std::stringstream sstream1(line);
                getline(sstream1, line, ',');
                // if(line.length() != 0){
                //     col.push_back(line);
                // }
                // else{
                //     //col.push_back(isnan(NAN));
                // }

                getline(sstream1, red, ',');
                // if(red.length() == 0){
                //     //hold1.push_back(std::numeric_limits<double>::quiet_NaN());
                // }
                // else{
                //      hold1.push_back(red);
                // }

                getline(sstream1, orange, ',');
                // if(orange.length() == 0){
                //     //hold2.push_back(std::numeric_limits<double>::quiet_NaN());
                // }
                // else{
                //      hold2.push_back(orange);
                // }
                
                getline(sstream1, yellow, ',');
                // if(yellow.length() == 0){
                //     //hold3.push_back(std::numeric_limits<double>::quiet_NaN());
                // }
                // else{
                //      hold3.push_back(yellow);
                // }
                
                getline(sstream1, green, ',');
                // if(green.length() == 0){
                //     //hold4.push_back(std::numeric_limits<double>::quiet_NaN());
                // }
                // else{
                //      hold4.push_back(green);
                // }          
            }
            

            // for loops to check if the arrays got printed properly
            for(int j = 0; j<col.size(); j++){
                //std::cout << col.at(j) << std::endl;
            }

            for(int z = 0; z<hold1.size(); z++){
                //std::cout << hold1.at(z) << std::endl;
            }

            for(int k = 0; k<hold2.size(); k++){
                //std::cout << hold2.at(k) << std::endl;
            }

            for(int m = 0; m<hold3.size(); m++){
                //std::cout << hold3.at(m) << std::endl;
            }

            for(int n = 0; n<hold4.size(); n++){
                //std::cout << hold4.at(n) << std::endl;
            }
            
            std::unordered_map<std::string, std::vector<float>> temp = 
            {
                {HeaderList[0], col},
                {HeaderList[1], hold1},
                {HeaderList[2], hold2},
                {HeaderList[3], hold3},
                {HeaderList[4], hold4}
                
            };

            temp = this->cols;
       
            
        //    cols[HeaderList[0]] = headhold1; //first header (date)
        //    cols[HeaderList[1]] = headhold2; //second header ()
        //    cols[HeaderList[2]] = headhold3; //third header ()
        //    cols[HeaderList[3]] = headhold4; //fourth header ()
        //    cols[HeaderList[4]] = headhold5; //fifth header ()
                            
}
            


             




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
    //std::cout << "Testing if entering function." << std::endl;
    std::ifstream listStream;//could call the file here
    std::string header, red, orange, yellow, green, blue;
    std::string line;
    std::array<std::string, 5> HeaderList;
    std::vector<std::string> col, hold1, hold2, hold3, hold4, hold5;
    std::numeric_limits<double>::quiet_NaN();
    //std::vector<float> 
    int i = 0;

    //load in the file
    //std::cout << this->file_name << std::endl;
	listStream.open(this->file_name); //gotta figure out what files to open, probably a file path??
    // if (listStream.is_open()){
    //     std::cout << "FileOpen"<< std::endl;
    // }
    // else{
    //     std::cout << "File Not open" << std::endl;
    // }

    //loads headers in to HeaderList[] array
    getline(listStream, header);
    //std::cout << "this is the header: " << header << std::endl;
    std::stringstream sstream(header);
    
    for(i=0;i<5;i++){
        getline(sstream, header, ',');
        HeaderList[i] = header;
        //std::cout << HeaderList[i] << std::endl;
    }
        
    

        //loads columns into col vector
             while(getline(listStream, line)){
                std::stringstream sstream1(line);
                getline(sstream1, line, ',');
                if(line.length() != 0){
                    col.push_back(line);
                }
                else{
                    col.push_back(isnan(NAN));
                }

                getline(sstream1, red, ',');
                if(red.length() == 0){
                    hold1.push_back(std::numeric_limits<double>::quiet_NaN());
                }
                else{
                     hold1.push_back(red);
                }

                getline(sstream1, orange, ',');
                if(orange.length() == 0){
                    hold2.push_back(std::numeric_limits<double>::quiet_NaN());
                }
                else{
                     hold2.push_back(orange);
                }
                
                getline(sstream1, yellow, ',');
                if(yellow.length() == 0){
                    hold3.push_back(std::numeric_limits<double>::quiet_NaN());
                }
                else{
                     hold3.push_back(yellow);
                }
                
                getline(sstream1, green, ',');
                if(green.length() == 0){
                    hold4.push_back(std::numeric_limits<double>::quiet_NaN());
                }
                else{
                     hold4.push_back(green);
                }          
            }

            // for loop to get dates into a vector
            for(int j = 0; j<col.size(); j++){
                //std::cout << col.at(j) << std::endl;
            }

            // for loop to get dates into a vector
            for(int z = 0; z<hold1.size(); z++){
                //std::cout << hold1.at(z) << std::endl;
            }

            // for loop to get dates into a vector
            for(int k = 0; k<hold2.size(); k++){
                //std::cout << hold2.at(k) << std::endl;
            }

            // for loop to get dates into a vector
            for(int m = 0; m<hold3.size(); m++){
                //std::cout << hold3.at(m) << std::endl;
            }

            for(int n = 0; n<hold4.size(); n++){
                //std::cout << hold4.at(n) << std::endl;
            }

            
            std::unordered_map<int, std::string> temp = 
            { 
                {HeaderList, "headers"},
                {}
            };

                   
}
            


             




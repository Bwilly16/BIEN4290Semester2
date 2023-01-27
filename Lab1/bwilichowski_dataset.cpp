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
    std::ifstream listStream;

    //load in the file
	listStream.open("~/"); //gotta figure out what files to open, probably a file path??

    //load each column into umap I created in the header using the below loop
    //for (data_type  variable_name : container_type) {
        //operations using variable_name
    //}
    
}

void Dataset::myDataset::get_name(){

}

void Dataset::myDataset::set_name(){

}

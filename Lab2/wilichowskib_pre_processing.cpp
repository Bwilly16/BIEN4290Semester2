/*
Author: Ben Wilichowski
Purpose: The purpose of this lab is to
Date: 2/7/2023
Class: BIEN4290
*/

#include "wilichowskib_pre_processing.hpp"

preproc::mypreproc::mypreproc(std::string a1, std::string a2, std::string a3, std::string a4){ //, std::string a5, int a6){
    this->arg1 = a1;
    this->arg2 = a2;
    this->arg3 = a3;
    this->arg4 = a4;
    // this->arg5 = a5;
    // this->arg6 = a6;
}

void preproc::mypreproc::readfiles(){

    //streams for files being read, 6th argument is a integer
    std::ifstream file1(this->arg1); //red file
    std::ifstream file2(this->arg2); //red background
    std::ifstream file3(this->arg3); //green file
    std::ifstream file4(this->arg4); //green background
    std::ifstream file5(this->arg5); // file write to

    int genenum = this->arg6;//sets genenum equal to the requested amount

    std::string REDhold, GREENhold, RBACKhold, GBACKhold; //holds values while files get read as STRINGS
    std::vector<float> REDcol, GREENcol, RBACKcol, GBACKcol; // vectors to hold entire contents of each file

//check if each file exists
    //file1
    if(file1){
      std::cout<< "Red file exists" << std::endl;
    } 
    else {
      std::cout<< "ERROR: red file doesn't exist. EXITING PROGRAM" << std::endl;
      exit(1);
    }

    //file2
    if(file2){
      std::cout<< "Red background file exists" << std::endl;
    } 
    else {
      std::cout<< "ERROR: red background file doesn't exist. EXITING PROGRAM" << std::endl;
      exit(1);
    }

    //file3
    if(file3){
      std::cout<< "Green file exists" << std::endl;
    } 
    else {
      std::cout<< "ERROR: green file doesn't exist. EXITING PROGRAM" << std::endl;
      exit(1);
    }

    //file4
    if(file4){
      std::cout<< "Green background file exists" << std::endl;
    } 
    else {
      std::cout<< "ERROR: file doesn't exist. EXITING PROGRAM" << std::endl;
      exit(1);
    }

    //file5
    if(file5){
      std::cout<< "File being written to exists" << std::endl;
    } 
    else {
      std::cout<< "ERROR: written file doesn't exist. EXITING PROGRAM" << std::endl;
      exit(1);
    }

    

    //read red file 
    while(getline(file1, REDhold))
    {
      if(REDhold.length() != 0)
      {
        REDcol.push_back(std::stof(REDhold));
      }
      else
      {
        REDcol.push_back(isnan(NAN));
      }

    }

    // printing out file into vector based on gene number
    for(uint i=0; i<genenum; i++)
    {
      if(REDcol.size() <= genenum){
        std::cout << REDcol[i] << std::endl;
      }
      else{
        std::cout << "ERROR: requested amount of genes is larger than # of genes in file" << std::endl;
      }
    }


    //read red background file 
    while(getline(file2, RBACKhold))
    {
      //if(RBACKhold.length() != 0) had this originally
      if(RBACKhold.length() != 0) // if the genenum is larger than the length of file, throw error
      {
        RBACKcol.push_back(std::stof(RBACKhold));
      }
      else
      {
        RBACKcol.push_back(isnan(NAN));
      }

    }

    // printing out file into vector based on gene number
    for(uint i=0; i<genenum; i++)
    {
      if(RBACKcol.size() <= genenum){
        std::cout << RBACKcol[i] << std::endl;
      }
      else{
        std::cout << "ERROR: requested amount of genes is larger than # of genes in file" << std::endl;
      }
    }

    //read green file 
    while(getline(file3, GREENhold))
    {
      if(GREENhold.length() != 0)
      {
        GREENcol.push_back(std::stof(GREENhold));
      }
      else
      {
        GREENcol.push_back(isnan(NAN));
      }

    }
    for(uint i=0; i<GREENcol.size(); i++)
    {
      std::cout << GREENcol[i] << std::endl;
    }


    //read green background file 
    while(getline(file4, GBACKhold))
    {
      if(GBACKhold.length() != 0)
      {
        GBACKcol.push_back(std::stof(GBACKhold));
      }
      else
      {
        GBACKcol.push_back(isnan(NAN));
      }

    }
    for(uint i=0; i<GBACKcol.size(); i++)
    {
      std::cout << GBACKcol[i] << std::endl;
    }


    //check if gene # is greater than number of data points in file
    // do this eventually 

}

int main(int argc, char *argv[]){

    //storing arguments into strings and ints
    std::string argument1 = argv[1]; //name of red file
    std::string argument2 = argv[2]; //name of red background file
    std::string argument3 = argv[3]; //name of green file
    std::string argument4 = argv[4]; //name of green background file
    // std::string argument5 = argv[5]; //name of file being wrote too
    // //int argument6 = std::stoi(argv[6]); //number of genes being analyzed

    preproc::mypreproc callconst(argument1, argument2, argument3, argument4);//, argument5, argument6);
    callconst.readfiles();


    // std::cout << "These are your arguments: " << std::endl;
    // std::cout << argument1 << std::endl;
    // std::cout << argument2 << std::endl;
    // std::cout << argument3 << std::endl;
    // std::cout << argument4 << std::endl;
    // std::cout << argument5 << std::endl;
    // std::cout << argument6 << std::endl;
    return 0;

}
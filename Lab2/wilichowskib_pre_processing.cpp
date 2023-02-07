/*
Author: Ben Wilichowski
Purpose: The purpose of this lab is to
Date: 2/7/2023
Class: BIEN4290
*/

#include "wilichowskib_pre_processing.hpp"

preproc::mypreproc::mypreproc(std::string a1, std::string a2, std::string a3, std::string a4, std::string a5, int a6){
    this->arg1 = a1;
    this->arg2 = a2;
    this->arg3 = a3;
    this->arg4 = a4;
    this->arg5 = a5;
    this->arg6 = a6;
}

void preproc::mypreproc::readfiles(){

    //streams for files being read, 6th argument is a integer
    std::ifstream file1(this->arg1);
    std::ifstream file2(this->arg2);
    std::ifstream file3(this->arg3);
    std::ifstream file4(this->arg4);
    std::ifstream file5(this->arg5);

//check if each file exists
    //file1
    if(file1){
      std::cout<<"Red file exists" << std::endl;
    } 
    else {
      std::cout<< "ERROR: file doesn't exist. EXITING PROGRAM" << std::endl;
      exit(1);
    }

    //file2
    if(file2){
      std::cout<<"Red background file exists" << std::endl;
    } 
    else {
      std::cout<< "ERROR: file doesn't exist. EXITING PROGRAM" << std::endl;
      exit(1);
    }

    //file3
    if(file3){
      std::cout<<"green file exists" << std::endl;
    } 
    else {
      std::cout<< "ERROR: file doesn't exist. EXITING PROGRAM" << std::endl;
      exit(1);
    }

    //file4
    if(file4){
      std::cout<<"green background file exists" << std::endl;
    } 
    else {
      std::cout<< "ERROR: file doesn't exist. EXITING PROGRAM" << std::endl;
      exit(1);
    }

    //file5
    if(file5){
      std::cout<<"file being wrote to exists" << std::endl;
    } 
    else {
      std::cout<< "ERROR: file doesn't exist. EXITING PROGRAM" << std::endl;
      exit(1);
    }

}

int main(int argc, char *argv[]){

    //storing arguments into strings and ints
    std::string argument1 = argv[1]; //name of red file
    std::string argument2 = argv[2]; //name of red background file
    std::string argument3 = argv[3]; //name of green file
    std::string argument4 = argv[4]; //name of green background file
    std::string argument5 = argv[5]; //name of file being wrote too
    int argument6 = std::stoi(argv[6]); //number of genes being analyzed

    preproc::mypreproc callconst(argument1, argument2, argument3, argument4, argument5, argument6);
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
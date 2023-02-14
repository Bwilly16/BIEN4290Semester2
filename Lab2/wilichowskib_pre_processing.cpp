/*
Author: Ben Wilichowski
Purpose: The purpose of this lab is to
Date: 2/7/2023
Class: BIEN4290
*/

#include "wilichowskib_pre_processing.hpp"
#include "wilichowskib_vector_ops.hpp"

preproc::mypreproc::mypreproc(std::string a1, std::string a2, std::string a3, std::string a4, std::string a5, uint a6){
    this->arg1 = a1; //red file
    this->arg2 = a2; //red background file
    this->arg3 = a3; //green file
    this->arg4 = a4; //green background file
    this->arg5 = a5; //file being written to
    this->arg6 = a6; //number of genes being analyzed
}

void preproc::mypreproc::readfiles(std::vector<float> *REDcol, std::vector<float> *RBACKcol, std::vector<float> *GREENcol, std::vector<float> *GBACKcol){

    //streams for files being read, 6th argument is a integer
    std::ifstream file1(this->arg1); //red file
    std::ifstream file2(this->arg2); //red background
    std::ifstream file3(this->arg3); //green file
    std::ifstream file4(this->arg4); //green background
    std::ifstream file5(this->arg5); // file write to

    //uint genenum = this->arg6;//sets genenum equal to the requested amount

    std::string REDhold, GREENhold, RBACKhold, GBACKhold; //holds values while files get read as STRINGS
    //std::vector<float> REDcol, GREENcol, RBACKcol, GBACKcol; // vectors to hold entire contents of each file

//check if each file exists
    //file1
    if(file1)
    {
      std::cout<< "Red file exists" << std::endl;
    } 
    else 
    {
      std::cout<< "ERROR: red file doesn't exist. EXITING PROGRAM" << std::endl;
      exit(1);
    }

    //file2
    if(file2)
    {
      std::cout<< "Red background file exists" << std::endl;
    } 
    else 
    {
      std::cout<< "ERROR: red background file doesn't exist. EXITING PROGRAM" << std::endl;
      exit(1);
    }

    //file3
    if(file3)
    {
      std::cout<< "Green file exists" << std::endl;
    } 
    else 
    {
      std::cout<< "ERROR: green file doesn't exist. EXITING PROGRAM" << std::endl;
      exit(1);
    }

    //file4
    if(file4)
    {
      std::cout<< "Green background file exists" << std::endl;
    } 
    else 
    {
      std::cout<< "ERROR: file doesn't exist. EXITING PROGRAM" << std::endl;
      exit(1);
    }

    //file5
    // if(file5)
    // {
    //   std::cout<< "File being written to exists" << std::endl;
    // } 
    // else 
    // {
    //   std::cout<< "ERROR: written file doesn't exist. EXITING PROGRAM" << std::endl;
    //   exit(1);
    // }



    //read red file 
   
     while(getline(file1, REDhold)) //read until gene num is the same as col size
    {
      if(REDhold.length() != 0)
      {
        REDcol->push_back(std::stof(REDhold));
      }
      else
      {
        REDcol->push_back(NAN);
      }

    }

    //printing out file into vector based on gene number
    //  std::cout << "printing red" << std::endl;
    // for(uint i=0; i<genenum; i++)
    // {
      
    //     std::cout << REDcol->at(i) << std::endl;
      
    // }


    //read red background file 
    while(getline(file2, RBACKhold))
    {
      //if(RBACKhold.length() != 0) had this originally
      if(RBACKhold.length() != 0) // if the genenum is larger than the length of file, throw error
      {
        RBACKcol->push_back(std::stof(RBACKhold));
      }
      else
      {
        RBACKcol->push_back(NAN);
      }

    }
  // std::cout << "printing red back" << std::endl;
  //   //printing out file into vector based on gene number
  //   for(uint i=0; i<genenum; i++)
  //   {

  //       std::cout << RBACKcol->at(i) << std::endl;
  //   }

    //read green file 
    while(getline(file3, GREENhold))
    {
      if(GREENhold.length() != 0)
      {
        GREENcol->push_back(std::stof(GREENhold));
      }
      else
      {
        GREENcol->push_back(NAN);
      }

    }

    // std::cout << "printing green" << std::endl;
    //  for(uint i=0; i<genenum; i++)
    // {

    //     std::cout << GREENcol->at(i) << std::endl;
    // }


    //read green background file 
    while(getline(file4, GBACKhold))
    {
      if(GBACKhold.length() != 0)
      {
        GBACKcol->push_back(std::stof(GBACKhold));
      }
      else
      {
        GBACKcol->push_back(NAN);
      }

    }
    // std::cout << "printing green back" << std::endl;
    // for(uint i=0; i<genenum; i++)
    // {

    //     std::cout << GBACKcol->at(i) << std::endl;
    // }


}



int main(int argc, char *argv[]){

    //storing arguments into strings and ints
    std::string argument1 = argv[1]; //name of red file
    std::string argument2 = argv[2]; //name of red background file
    std::string argument3 = argv[3]; //name of green file
    std::string argument4 = argv[4]; //name of green background file
    std::string argument5 = argv[5]; //name of file being wrote too
    uint argument6 = std::stoi(argv[6]); //number of genes being analyzed

    std::vector<float> REDcol, RBACKcol, GREENcol, GBACKcol, REDcorrect, GREENcorrect;

    std::cout << "Calling readfiles" << std::endl;
    preproc::mypreproc callconst(argument1, argument2, argument3, argument4, argument5, argument6);
    callconst.readfiles(&REDcol, &RBACKcol, &GREENcol, &GBACKcol);

    std::cout << "Calling substuff" << std::endl;
    vectorops::myvectorops passvar;
    passvar.substuff(&REDcol, &RBACKcol, &REDcorrect, argument6);
    passvar.substuff(&GREENcol, &GBACKcol, &GREENcorrect, argument6);

    // these WORK
    // std::cout << "pringing REDcorrect" << std::endl;
    //   for(int i = 0; i<5; i++){
    //     std::cout << REDcorrect.at(i) << std::endl;
    // }

    // std::cout << "pringing GREENcorrect" << std::endl;
    //   for(int i = 0; i<5; i++){
    //     std::cout << GREENcorrect.at(i) << std::endl;
    // }


    return 0;

}
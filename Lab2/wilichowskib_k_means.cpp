#include "wilichowskib_k_means.hpp"


cluster::mycluster::mycluster()
{

}


int main(int argc, char *argv[]){
    //read in and check if file exitst (WORKS)
    std::string argument1 = argv[1]; //name of log file

    std::ifstream logfile(argument1);
     if(logfile)
    {
      std::cout<< "log file exists" << std::endl;
    } 
    else 
    {
      std::cout<< "ERROR: log file doesn't exist. EXITING PROGRAM" << std::endl;
      exit(1);
    }


    return 0;
}
 /*
Author: Ben Wilichowski
Purpose: The purpose of this lab is to
Date: 2/7/2023
Class: BIEN4290
*/

#include "wilichowskib_vector_ops.hpp"



//fuction stuff!
vectorops::myvectorops::myvectorops()//constructor def.
{

} 

void sumstuff(std::vector<float> array1, std::vector<float> array12, std::vector<float> holdvect){
    
   
}

void vectorops::myvectorops::substuff(std::vector<float>* arraycolor, std::vector<float>* arrayback, std::vector<float>* holdvect, uint num){
    // std::cout << "printing array color" << std::endl;
    // for(uint i = 0; i<5; i++){
    //     std::cout << arraycolor->at(i) << std::endl;
    // }

    // std::cout << "printing array back" << std::endl;
    // for(uint i = 0; i<5; i++){
    //     std::cout << arrayback->at(i) << std::endl;
    // }


    //std::cout << "Made it into the sub function" << std::endl;
    for(uint i = 0; i<arraycolor->size(); i++){
        holdvect->push_back(arraycolor->at(i) - arrayback->at(i));
    }

    // std::cout << "Corrected array: " << std::endl;
    // for(uint i = 0; i<num; i++)
    // {
    //     std::cout << holdvect->at(i) << std::endl;
    // }
    
}

void multstuff(int c, std::vector<float> array4){
    
    std::vector<float> multarray;
    for(uint i = 0; i<array4.size(); i++){
        multarray.push_back(c * array4[i]);
    }
    
}

float vectorops::myvectorops::Means(std::vector<float>* corCOLOR, uint num)
{
    float temp = 0;
    for(uint i = 0; i<num; i++)
    {
        temp = corCOLOR->at(i) + temp;
       
    }
    temp = temp/num;
    return temp;
}

 void vectorops::myvectorops::norms(std::vector<float>* Ccorrect, float CMean, std::vector<float>* NormalArray, uint num)
 {
    //std::cout << "Normalized array" << std::endl;
    for(uint i = 0; i < num; i++)
    {
        NormalArray->push_back(Ccorrect->at(i)/CMean); //if the value is the mean, the true mean value should be 1
       // std::cout << NormalArray->at(i) << std::endl;
    }
    
 }

 void vectorops::myvectorops::logintensity(std::vector<float>* Rcolor, std::vector<float>* Gcolor, std::vector<float>* loghold, uint num)
 {
    std::cout << "Log intensity array:" << std::endl;
    for(uint i = 0; i < num; i++)
    {
        loghold->push_back(log10((Rcolor->at(i))/Gcolor->at(i)));
        //std::cout << loghold->at(i) << std::endl;
    }
 }

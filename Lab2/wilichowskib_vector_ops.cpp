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


std::vector<float> sumstuff(std::vector<float> array1){
    return array1;
}

std::vector<float> substuff(std::vector<float> array2, std::vector<float> array3){
    std::vector<float> totalarray;


    for(uint i = 0; i<=array2.size(); i++){
        totalarray.push_back(array3[i] - array2[i]);
    }
    return totalarray;
}

std::vector<float> multstuff(int c, std::vector<float> array4){
    
    std::vector<float> multarray;
    for(uint i = 0; i<array4.size(); i++){
        multarray.push_back(c * array4[i]);
    }
    return multarray;
}

int main(void){
    return 0;
}
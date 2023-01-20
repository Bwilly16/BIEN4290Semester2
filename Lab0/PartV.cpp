/*Author: Ben Wilichowski
 * Date: 1/19/2023
 * Purpose: This program is designed to calculate the values within my txt file
 * Professor: Dr.Cooper
 * Class: BIEN 4290 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Main
int main()
{
//Variables
    FILE* fileopen;
    FILE *out_file;
    char ch;
    int numberArray[20];
    int i;
    int sum = 0;
    double avg = 0;
    double gavgPRE = 1;
    double gavg = 0;
     
    // Opening file in reading mode
    fileopen = fopen("random.txt", "r");
    out_file = fopen("MathOut.csv", "w"); // write only
 
    if (NULL == fileopen)
    {
        printf("file can't be opened \n");
    } 
    else
    {
	    printf("File opened successfully!\n");
    }
   
//Print into an array for math purposes
    for (i = 0; i < 20; i++)
    {
        fscanf(fileopen, "%d", &numberArray[i]);
	printf("Value is: %d\n\n", numberArray[i]);
	sum = sum + numberArray[i];
	avg = sum/20;
	gavgPRE = (gavgPRE*numberArray[i]);
	gavg = pow(gavgPRE,0.05);
	
    }
	fprintf(out_file,"Sum = %i, ",sum);//print out of sum
	fprintf(out_file,"Average = %f, ",avg);//print out of average
	fprintf(out_file,"Geometric Average = %f\n",gavg);

	

    fclose(fileopen);

}

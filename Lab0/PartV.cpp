#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Main
int main()
{
    FILE* fileopen;
    char ch;
 
    // Opening file in reading mode
    fileopen = fopen("random.txt", "r");
 
    if (NULL == fileopen) {
        printf("file can't be opened \n");
    }
 
    printf("content of this file are \n");

     do {
        ch = fgetc(fileopen);
        printf("%c", ch);

        // If it is EOF stop reading.
    } while (ch != EOF);

    // Closing the file
    fclose(fileopen);
    return 0;
}

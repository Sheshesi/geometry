#include "inputCheck.h"
#include "check.h"
#include "print.h"
#include <stdio.h>
char** file_func(char** data)
{
    FILE* myfile;
    myfile = fopen("./example/figures.txt", "r");
    if (myfile == NULL) {
        printf("File open error!");
        return 0;
    }
    int i = 0;
    char *temp, *ptrFile, *buff;
    while (i < 100) {
        temp = (char*)malloc(1000 * sizeof(char));
        ptrFile = fgets(temp, 1000, myfile);
        if (ptrFile == NULL) {
            if (feof(myfile) != 0) {
                break;
            } else {
                continue;
            }
        }
        data[i] = temp;
        i++;
    }
    fclose(myfile);
    return data;
}
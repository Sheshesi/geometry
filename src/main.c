#include "check.h"
#include "inputCheck.h"
#include "print.h"
#include <stdio.h>
#define MAX_LEN 100
int main()
{
    char** data = (char**)malloc(MAX_LEN * sizeof(char*));
    for (int k = 0; k < MAX_LEN; k++) {
        data[k] = (char*)malloc(MAX_LEN * sizeof(char));
    }
    data = file_func(data);
    for (int i = 0; i < MAX_LEN; i++) {
        for (int j = 0; j < MAX_LEN; j++) {
            printf("%s\n", data[i]);
        }
    }
    return 0;
}
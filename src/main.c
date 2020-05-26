#include "function.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100
int main()
{
    int count = 0;
    char** data = (char**)malloc(MAX_LEN * sizeof(char*));
    for (int k = 0; k < MAX_LEN; k++) {
        data[k] = (char*)malloc(MAX_LEN * sizeof(char));
    }
    for (int i = 0; i < MAX_LEN; i++) {
        for (int j = 0; j < MAX_LEN; j++) {
            data[i][j] = 0;
        }
    }
    printf("%s\n", "Read from file ");
    data = file_func(data);
    if (data == NULL) {
        return 0;
    }
    for (int i = 0; i < MAX_LEN; i++) {
        if (strlen(data[i]) > 0) {
            count++;
        }
    }
    fill_list(data, count);
    return 0;
}

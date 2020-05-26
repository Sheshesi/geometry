#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100
char* squeeze(char s[])
{
    int i, j = 0;
    char* dest = (char*)malloc(((strlen(s) + 1) * sizeof(char)));
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != ' ')
            dest[j++] = s[i];
    dest[j] = '\0';
    return dest;
}
double side_length(double x, double y, double xx, double yy)
{
    double len = 0;
    len = sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
    return len;
}
int symbols_tr_check(const char string[])
{
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == '(') {
            a++;
        }
        if (string[i] == ';') {
            b++;
        }
        if (string[i] == ',') {
            c++;
        }
        if (string[i] == ')') {
            d++;
        }
    }
    if (a == 1 && b == 3 && c == 4 && d == 1) {
        return 1;
    } else {
        return 0;
    }
}
int symbols_cr_check(const char string[])
{
    int a = 0, b = 0, c = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == '(') {
            a++;
        }
        if (string[i] == ';') {
            b++;
        }
        if (string[i] == ')') {
            c++;
        }
    }
    if (a == 1 && b == 2 && c == 1) {
        return 1;
    } else {
        return 0;
    }
}
int name_check(const char str[])
{
    const char trin[] = "triangle";
    const char cap_trin[] = "TRIANGLE";
    const char circ[] = "circle";
    const char cap_circ[] = "CIRCLE";
    int bool = 1;
    if (str[0] == 't' || str[0] == 'T') {
        for (int k = 0; trin[k] != '\0'; k++) {
            if (str[k] != trin[k] && str[k] != cap_trin[k]) {
                bool = 0;
            }
        }
    } else {
        for (int k = 0; circ[k] != '\0'; k++) {
            if (str[k] != circ[k] && str[k] != cap_circ[k]) {
                bool = 0;
            }
        }
    }
    if (bool) {
        return 1;
    } else {
        return 0;
    }
}
int permissible_symb(char symb)
{
    if (symb == '0' || symb == '1' || symb == '2' || symb == '3' || symb == '4'
        || symb == '5' || symb == '6' || symb == '7' || symb == '8'
        || symb == '9') {
        return 1;
    } else {
        return 0;
    }
}
double* cord_get(char str[])
{
    double* cord = (double*)malloc(8 * sizeof(double));
    int j = 0, count = 0, start = 0;
    char substr[100] = {0};
    str = squeeze(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i - 1] == '(') {
            start = 1;
        }
        if (str[i] == ')') {
            start = 0;
        }
        if (str[i] == ',' || str[i] == ';') {
            continue;
        }
        if (start) {
            substr[j] = str[i];
            j++;
        }
        if (start
            && (str[i + 1] == ',' || str[i + 1] == ';' || str[i + 1] == ')')) {
            cord[count] = strtod(substr, NULL);
            memset(substr, 0, sizeof(substr));
            j = 0;
            count++;
        }
    }
    return cord;
}
int cord_check(char str[])
{
    int start = 0, sem_quan = 0, points = 0, pres_number = 0, pres_minus = 0,
        first_el = 0;
    double* cord;
    str = squeeze(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i - 1] == '(') {
            start = 1;
        }
        if (str[i] == ')') {
            start = 0;
        }
        if (start) {
            if (str[i] == ';') {
                sem_quan++;
                continue;
            }
            if (str[i] == ',') {
                continue;
            }
            if (!permissible_symb(str[i]) && str[i] != '-' && str[i] != ','
                && str[i] != ';' && str[i] != '.') {
                return 0;
            }
            if (pres_number || pres_minus) {
                if (str[i] == '-') {
                    return 0;
                }
                if (str[i] == '.') {
                    points++;
                }
            }
            if (!first_el) {
                if (str[i] == '-') {
                    first_el = 1;
                    pres_minus = 1;
                    if (str[i + 1] == '.' || str[i + 1] == ','
                        || str[i + 1] == ';' || str[i + 1] == ')'
                        || str[i + 1] == '-') {
                        return 0;
                    }
                }
                if (permissible_symb(str[i])) {
                    first_el = 1;
                    pres_number = 1;
                }
                if (!pres_minus && !pres_number) {
                    return 0;
                }
            }
        }
        if (start
            && (str[i + 1] == ',' || str[i + 1] == ';' || str[i + 1] == ')')) {
            if (points >= 2) {
                return 0;
            }
            points = 0;
            first_el = 0;
            pres_number = 0;
            pres_minus = 0;
        }
    }
    if (sem_quan == 2) {
        cord = cord_get(str);
        if (cord[2] <= 0) {
            return 0;
        } else {
            return 1;
        }
    } else if (sem_quan == 3) {
        cord = cord_get(str);
        double a = 0, b = 0, c = 0;
        a = side_length(cord[0], cord[1], cord[2], cord[3]);
        b = side_length(cord[2], cord[3], cord[4], cord[5]);
        c = side_length(cord[4], cord[5], cord[0], cord[1]);
        if (cord[0] == cord[6] && cord[1] == cord[7] && ((a + b) > c)
            && ((a + c) > b) && ((b + c) > a)) {
            return 1;
        } else {
            return 0;
        }
    }
    return 0;
}
char* data_check(char* str)
{
    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] == '\n') {
            str[j] = 0;
        }
    }
    int boolt = 0;
    int boolc = 0;
    boolt = symbols_tr_check(str) * name_check(str) * cord_check(str);
    boolc = symbols_cr_check(str) * name_check(str) * cord_check(str);
    if (!(boolc || boolt)) {
        printf("%s", "Invalid input format");
        if (!name_check(str)) {
            printf("%s%s\n", ",unknown func: ", str);
        } else if (!(symbols_tr_check(str) || symbols_cr_check(str))) {
            printf("%s%s\n", ",error in signs in:", str);
        } else if (!cord_check(str)) {
            printf(" %s%s", str, " does not exist\n");
        }
        return 0;
    } else {
        return str;
    }
}
char** file_func(char** data)
{
    FILE* myfile;
    myfile = fopen("./example/my.txt", "r");
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
        if (temp[0] == '#') {
            continue;
        }
        buff = data_check(temp);
        if (buff == 0) {
            return 0;
        } else {
            for (int j = 0; j < 100; j++) {
                if (temp[j] != '\n') {
                    data[i][j] = temp[j];
                }
            }
            i++;
        }
    }
    fclose(myfile);
    return data;
}

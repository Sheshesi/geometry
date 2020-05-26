#include "parser.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100
#define pi 3.14159265359
struct figure {
    char* name;
    char type;
    double* cord;
    double per;
    double area;
    char** inc;
};
double cr_per(double radius)
{
    double per = 0;
    per = 2 * pi * radius;
    return per;
}
double cr_area(double radius)
{
    double area = 0;
    area = pi * radius * radius;
    return area;
}
double tr_per(double* cord)
{
    double per = 0;
    double a = 0, b = 0, c = 0;
    a = side_length(cord[0], cord[1], cord[2], cord[3]);
    b = side_length(cord[2], cord[3], cord[4], cord[5]);
    c = side_length(cord[4], cord[5], cord[0], cord[1]);
    per = a + b + c;
    return per;
}
double tr_area(double* cord)
{
    double area = 0;
    double h_per = 0;
    double a = 0, b = 0, c = 0;
    a = side_length(cord[0], cord[1], cord[2], cord[3]);
    b = side_length(cord[2], cord[3], cord[4], cord[5]);
    c = side_length(cord[4], cord[5], cord[0], cord[1]);
    h_per = (tr_per(cord) / 2);
    area = sqrt(h_per * (h_per - a) * (h_per - b) * (h_per - c));
    return area;
}
int intersection_cr_tr(struct figure circle, struct figure triangle)
{
    if (circle.type != 'c' || triangle.type != 't') {
        printf("%s\n", "Input ERROR");
        return -1;
    }
    if (side_length(
                triangle.cord[0],
                triangle.cord[1],
                circle.cord[0],
                circle.cord[1])
        <= circle.cord[2]) {
        return 1;
    }
    if (side_length(
                triangle.cord[2],
                triangle.cord[3],
                circle.cord[0],
                circle.cord[1])
        <= circle.cord[2]) {
        return 1;
    }
    if (side_length(
                triangle.cord[4],
                triangle.cord[5],
                circle.cord[0],
                circle.cord[1])
        <= circle.cord[2]) {
        return 1;
    }
    return 0;
}
int intersection_cr_cr(struct figure circle_a, struct figure circle_b)
{
    double d = (circle_a.cord[0] - circle_b.cord[0])
                    * (circle_a.cord[0] - circle_b.cord[0])
            + (circle_a.cord[1] - circle_b.cord[1])
                    * (circle_a.cord[1] - circle_b.cord[1]);
    if (d <= (circle_a.cord[2] + circle_b.cord[2])
                        * (circle_a.cord[2] + circle_b.cord[2])
        && d >= (circle_a.cord[2] > circle_b.cord[2]
                         ? circle_a.cord[2] - circle_b.cord[2]
                         : circle_b.cord[2] - circle_a.cord[2])) {
        return 1;
    } else {
        return 0;
    }
}
double min(double a, double b)
{
    if (a < b)
        return a;
    if (a > b)
        return b;
    return 0;
}
double max(double a, double b)
{
    if (a < b)
        return b;
    if (a > b)
        return a;
    return 0;
}
double det(double a, double b, double c, double d)
{
    return a * d - b * c;
}
double between(double a, double b, double c)
{
    double exp_1;
    double exp_2;
    if (min(a, b) <= c)
        exp_1 = 1;
    else
        exp_1 = 0;
    if (c <= max(a, b))
        exp_2 = 1;
    else
        exp_2 = 0;
    return exp_1 * exp_2;
}
void swap(double* a, double* b)
{
    double tmp = *a;
    *a = *b;
    *b = tmp;
}
int intersect(double a, double b, double c, double d)
{
    if (a > b)
        swap(&a, &b);
    if (c > d)
        swap(&c, &d);
    if (max(a, c) <= min(b, d))
        return 1;
    if (max(a, c) > min(b, d))
        return 0;
    return 0;
}
int intersection_tr_tr(struct figure a, struct figure b)
{
    double A1 = 0, B1 = 0, C1 = 0, A2 = 0, B2 = 0, C2 = 0, zn = 0, x = 0, y = 0,
           bool = 0, c = 0, d = 0;
    if (a.type == 't') {
        if (b.type == 't') {
            A1 = a.cord[1] - a.cord[3], B1 = a.cord[2] - a.cord[0],
            C1 = -A1 * a.cord[0] - B1 * a.cord[1];
            A2 = b.cord[1] - b.cord[3], B2 = b.cord[2] - a.cord[0],
            C2 = -A2 * b.cord[0] - B2 * b.cord[1];
            zn = det(A1, B1, A2, B2);
            if (zn != 0) {
                x = -det(C1, B1, C2, B2) * 1. / zn;
                y = -det(A1, C1, A2, C2) * 1. / zn;
                bool = between(a.cord[0], a.cord[2], x)
                        * between(a.cord[1], a.cord[3], y)
                        * between(b.cord[0], b.cord[2], x)
                        * between(b.cord[1], b.cord[3], y);
                if (bool == 0) {
                    return 0;
                } else if (bool == 1) {
                    return 1;
                }
            } else {
                if ((det(A1, C1, A2, C2) == 0) && (det(B1, C1, B2, C2) == 0)) {
                    c = (intersect(a.cord[0], a.cord[2], b.cord[0], b.cord[2]));
                    d = (intersect(a.cord[1], a.cord[3], b.cord[3], b.cord[3]));
                    if ((c * d) == 1) {
                        return 1;
                    }
                }
            }
        }
    } else {
        return 0;
    }
    return 0;
}
void print_list(struct figure list[], int n)
{
    for (int i = 0; i < n; i++) {
        printf(" %s\n", list[i].name);
        printf("   perimeter = %.4f\n", list[i].per);
        printf("   area = %.4f\n", list[i].area);
        if (strlen(list[i].inc[0]) > 0) {
            printf("   intersects:\n");
        }
        for (int j = 0; j < n; j++) {
            if (strlen(list[i].inc[j]) > 0) {
                printf("      %s\n", list[i].inc[j]);
            }
        }
        printf("\n");
    }
}
char* caps(char str[])
{
    const char trin[] = "triangle";
    const char cap_trin[] = "TRIANGLE";
    const char circ[] = "circle";
    const char cap_circ[] = "CIRCLE";
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == trin[j] || str[i] == cap_trin[j]) {
            str[i] = cap_trin[j];
            j++;
        } else if (str[i] == circ[j] || str[i] == cap_circ[j]) {
            str[i] = cap_circ[j];
            j++;
        }
    }
    return str;
}
void fill_list(char** data, int count)
{
    struct figure* list = (struct figure*)malloc(count * sizeof(struct figure));
    for (int i = 0; i < count; i++) {
        char* new_name = (char*)malloc(MAX_LEN * sizeof(char));
        new_name[0] = (char)(i + 1 + 48);
        new_name[1] = '.';
        list[i].name = strcat(new_name, squeeze(data[i]));
        list[i].name = caps(list[i].name);
        if (data[i][0] == 't' || data[i][0] == 'T') {
            list[i].type = 't';
        } else {
            list[i].type = 'c';
        }
        list[i].cord = cord_get(data[i]);
        if (list[i].type == 't') {
            list[i].per = tr_per(list[i].cord);
            list[i].area = tr_area(list[i].cord);
        } else {
            list[i].per = cr_per(list[i].cord[2]);
            list[i].area = cr_area(list[i].cord[2]);
        }
    }
    int k = 0;
    for (int i = 0; i < count; i++) {
        char** intersec_matrix = (char**)malloc(count * sizeof(char*));
        for (int ii = 0; ii < count; ii++) {
            intersec_matrix[ii] = (char*)malloc(MAX_LEN * sizeof(char));
        }
        for (int ii = 0; ii < count; ii++) {
            for (int jj = 0; jj < MAX_LEN; jj++) {
                intersec_matrix[ii][jj] = 0;
            }
        }
        for (int j = 0; j < count; j++) {
            if (i == j) {
                continue;
            }
            if (list[i].type == 'c') {
                if (list[j].type == 'c') {
                    if (intersection_cr_cr(list[i], list[j])) {
                        intersec_matrix[k] = list[j].name;
                        k++;
                    }
                } else {
                    if (intersection_cr_tr(list[i], list[j])) {
                        intersec_matrix[k] = list[j].name;
                        k++;
                    }
                }
            } else {
                if (list[j].type == 't') {
                    if (intersection_tr_tr(list[i], list[j])) {
                        intersec_matrix[k] = list[j].name;
                        k++;
                    }

                } else {
                    if (intersection_cr_tr(list[j], list[i])) {
                        intersec_matrix[k] = list[j].name;
                        k++;
                    }
                }
            }
        }
        list[i].inc = intersec_matrix;
        k = 0;
    }
    print_list(list, count);
}
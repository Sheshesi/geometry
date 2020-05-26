#ifndef FUNCTION_H
#define FUNCTION_H
struct figure {
    char* name;
    char type;
    double* cord;
    double per;
    double area;
    char** inc;
};
double cr_per(double radius);
double cr_area(double radius);
double tr_per(double* cord);
double tr_area(double* cord);
int intersection_cr_tr(struct figure circle, struct figure triangle);
int intersection_cr_cr(struct figure circle_a, struct figure circle_b);
double min(double a, double b);
double max(double a, double b);
double det(double a, double b, double c, double d);
double between(double a, double b, double c);
void swap(double* a, double* b);
int intersect(double a, double b, double c, double d);
int intersection_tr_tr(struct figure a, struct figure b);
void print_list(struct figure list[], int n);
char* caps(char str[]);
void fill_list(char** data, int count);
#endif
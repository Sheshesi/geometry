#ifndef FUNCTION_H
#define FUNCTION_H
#define M_PI 3.14159265358979323846
#define EPS 1E-9
typedef struct {
    int type;
    double c[40];
    int size;
} Figure;

enum F { TRIANGLE = 1, CIRCLE = 2, POINT = 3 };

int min(int a, int b);
int max(int a, int b);
int det(int a, int b, int c, int d);
int between(int a, int b, double c);
void swap(int* a, int* b);
int intersect_1(int a, int b, int c, int d);
void InSecTrTr(Figure* a, Figure* b, int a_1, int b_1);
void InSecTrCir(Figure* a, Figure* b, int a_1, int b_1);
void InSecCirTr(Figure* a, Figure* b, int a_1, int b_1);
void InSecCirCir(Figure* a, Figure* b, int a_1, int b_1);
// int Intersection(Figure* x, Figure* y)
void Work(Figure* newPath);
void Print_Coordinats(Figure* newPath);
void S_Circle(double* S, Figure* newPath);
void P_Circle(double* P, Figure* newPath);
void Vector(Figure* newPath, double* a, double* b, double* c);
void S_Triangle(double* S, double a, double b, double c);
void P_Triangle(double* P, double a, double b, double c);

#endif

#include "function.h"
#include "print.h"
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float x, y, r;

    string str;
    cout << "Correct imput example: (x y, r)" << endl;
    cout << "Enter coord of 1 circle: ";
    getline(cin, str, '\n');
    if (Coord(str, x, y, r)) {
        cout << "1. ";
        cout << "x = " << x << ", y = " << y << ", r = " << r;

        cout << "\nS: " << S(r) << "\nP: " << P(r) << endl;
    } else {
        cout << "Ooops...";
    }
    return 0;
}

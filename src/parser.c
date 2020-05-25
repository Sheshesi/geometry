#include "print.h"

bool Coord(std::string str, float& x, float& y, float& r)
{
    std::string strX, strY, strR;
    int i, Z, L, R, space;

    L = str.find("(");
    R = str.find(")");
    Z = str.find(", ");
    space = str.find(" ");
    if (L != -1 && R != -1 && Z != -1 && space != -1) {
        if (str[L + 1] == '-') {
            strX += str[L + 1];
            i = L + 2;
        } else {
            i = L + 1;
        }
        int o = 0;
        for (; i < space; ++i) {
            if (isdigit(str[i]) || str[i] == '.') {
                strX += str[i];
                if (str[i] == '.') {
                    o++;
                }
                if (o > 1) {
                    return false;
                }

            } else {
                return false;
            }
        }
        if (str[space + 1] == '-') {
            strY += str[space + 1];
            i = space + 2;
        } else {
            i = space + 1;
        }
        o = 0;
        for (; i < Z; ++i) {
            if (isdigit(str[i]) || str[i] == '.') {
                strY += str[i];
                if (str[i] == '.') {
                    o++;
                }
                if (o > 1) {
                    return false;
                }

            } else {
                return false;
            }
        }
        o = 0;
        for (i = Z + 2; i < R; ++i) {
            if (isdigit(str[i]) || str[i] == '.') {
                strR += str[i];
                if (str[i] == '.') {
                    o++;
                }
                if (o > 1) {
                    return false;
                }

            } else {
                return false;
            }
        }
    } else {
        return false;
    }
    x = stof(strX);
    y = stof(strY);
    r = stof(strR);
    return true;
}

#include "../thirdparty/ctest.h"
#include <function.h>
#include <stdlib.h>
CTEST(geometry, crper)
{
    // Given
    double radius = 3;
    // When
    double res = cr_per(radius);
    // Then
    double exp = 18.885;
    ASSERT_DBL_NEAR_TOL(res, exp, 0.5);
}
CTEST(geometry, trper)
{
    // Given
    double cord[8] = {8, -4, 8, 4, 2, 0, 8, -4};
    // When
    double res = tr_per(cord);
    // Then
    double exp = 22.422;
    ASSERT_DBL_NEAR_TOL(res, exp, 0.5);
}
CTEST(geometry, crarea)
{
    // Given
    double radius = 3;
    ;
    // When
    double res = cr_area(radius);
    // Then
    double exp = 28.274;
    ASSERT_DBL_NEAR_TOL(res, exp, 0.5);
}
CTEST(geometry, trarea)
{
    // Given
    double cord[8] = {8, -4, 8, 4, 2, 0, 8, -4};
    // When
    double res = tr_area(cord);
    // Then
    double exp = 24.000;
    ASSERT_DBL_NEAR_TOL(res, exp, 0.5);
}
CTEST(geometry, min)
{
    // Given
    double a = 3;
    double b = 3;
    double c = 5;
    // When
    double res = min(a, b);
    double res_t = min(a, c);
    // Then
    double exp = 0;
    double exp_t = 3;
    ASSERT_DBL_NEAR_TOL(res, exp, 0.5);
    ASSERT_DBL_NEAR_TOL(res_t, exp_t, 0.5);
}
CTEST(geometry, max)
{
    // Given
    double a = 3;
    double b = 3;
    double c = 5;
    // When
    double res = max(a, b);
    double res_t = max(a, c);
    // Then
    double exp = 0;
    double exp_t = 5;
    ASSERT_DBL_NEAR_TOL(res, exp, 0.5);
    ASSERT_DBL_NEAR_TOL(res_t, exp_t, 0.5);
}
CTEST(geometry, caps)
{
    // Given
    char str[] = "CiRcLe";
    // When
    char* res = caps(str);
    // Then
    char* exp = "CIRCLE";
    ASSERT_STR(res, exp);
}
CTEST(geometry, in_cr_tr)
{
    // Given
    double* cord = (double*)malloc(3 * sizeof(double));
    double* cord_f = (double*)malloc(8 * sizeof(double));
    cord[0] = 3;
    cord[1] = 3;
    cord[2] = 4;
    cord_f[0] = -8;
    cord_f[1] = 4;
    cord_f[2] = 8;
    cord_f[3] = 4;
    cord_f[4] = 2;
    cord_f[5] = 0;
    cord_f[6] = -8;
    cord_f[7] = 4;
    struct figure circle = {"circle", 'c', cord};
    struct figure triangle = {"triangle", 't', cord_f};
    // When
    int res = intersection_cr_tr(circle, triangle);
    // Then
    int exp = 1;
    ASSERT_EQUAL(res, exp);
}
CTEST(geometry, in_tr_tr)
{
    // Given
    double* cord = (double*)malloc(8 * sizeof(double));
    double* cord_f = (double*)malloc(8 * sizeof(double));
    cord[0] = -8;
    cord[1] = 4;
    cord[2] = 8;
    cord[3] = 4;
    cord[4] = 2;
    cord[5] = 0;
    cord[6] = -8;
    cord[7] = 4;
    cord_f[0] = -8;
    cord_f[1] = 4;
    cord_f[2] = 8;
    cord_f[3] = 4;
    cord_f[4] = 2;
    cord_f[5] = 0;
    cord_f[6] = -8;
    cord_f[7] = 4;
    struct figure triangle_f = {"triangle", 't', cord};
    struct figure triangle = {"triangle", 't', cord_f};
    // When
    int res = intersection_tr_tr(triangle_f, triangle);
    // Then
    int exp = 1;
    ASSERT_EQUAL(res, exp);
}
CTEST(geometry, in_cr_cr)
{
    // Given
    double* cord = (double*)malloc(3 * sizeof(double));
    double* cord_f = (double*)malloc(3 * sizeof(double));
    cord[0] = 3;
    cord[1] = 3;
    cord[2] = 3;
    cord_f[0] = 3;
    cord_f[1] = 3;
    cord_f[2] = 5;
    struct figure circle = {"circle", 'c', cord};
    struct figure circle_f = {"circle", 'c', cord_f};
    // When
    int res = intersection_cr_cr(circle, circle_f);
    // Then
    int exp = 0;
    ASSERT_EQUAL(res, exp);
}
#include "../thirdparty/ctest.h"
#include <parser.h>
CTEST(geometry, squeeze)
{
    // Given
    char* string = "C i r c l e ( 3 ; 3 ; 3 )";
    // When
    char* result_string = squeeze(string);
    // Then
    const char* expected_string = "Circle(3;3;3)";
    ASSERT_STR(expected_string, result_string);
}
CTEST(geometry, symb_cr)
{
    // Given
    char* string = "circle(0;0;4.1)";
    char* string_t = "circle((0,0,4.1))";
    // When
    int exp = symbols_cr_check(string);
    int exp_t = symbols_cr_check(string_t);
    // Then
    int real = 1;
    int real_t = 0;
    ASSERT_EQUAL(exp, real);
    ASSERT_EQUAL(exp_t, real_t);
}
CTEST(geometry, symb_tr)
{
    // Given
    char* string = "triangle(-8,-4;-8,4;-2,0;-8,-4)";
    char* string_t = "triangle(-8;-4,-8,4,-2,0;-8,-4))";
    // When
    int exp = symbols_tr_check(string);
    int exp_t = symbols_tr_check(string_t);
    // Then
    int real = 1;
    int real_t = 0;
    ASSERT_EQUAL(exp, real);
    ASSERT_EQUAL(exp_t, real_t);
}
CTEST(geometry, name)
{
    // Given
    char* string = "triangle(-8,-4;-8,4;-2,0;-8,-4)";
    char* string_t = "shape(-8;-4;-8,4,-2,0;-8,-4)";
    // When
    int exp = name_check(string);
    int exp_t = name_check(string_t);
    // Then
    int real = 1;
    int real_t = 0;
    ASSERT_EQUAL(exp, real);
    ASSERT_EQUAL(exp_t, real_t);
}
CTEST(geometry, perm_sumb)
{
    // Given
    char string = '1';
    char string_t = 'a';
    // When
    int exp = permissible_symb(string);
    int exp_t = permissible_symb(string_t);
    // Then
    int real = 1;
    int real_t = 0;
    ASSERT_EQUAL(exp, real);
    ASSERT_EQUAL(exp_t, real_t);
}
CTEST(geometry, cord)
{
    // Given
    char* string = "triangle(-8,-4;-8,4;-2,0;-8,-4)";
    char* string_t = "circle(3;3;-3)";
    // When
    int exp = cord_check(string);
    int exp_t = cord_check(string_t);
    // Then
    int real = 1;
    int real_t = 0;
    ASSERT_EQUAL(exp, real);
    ASSERT_EQUAL(exp_t, real_t);
}
CTEST(geometry, data_check)
{
    // Given
    char* string = "triangle(-8,-4;-8,4;-2,0;-8,-4)";
    char* string_t = "circle(3;3;-3)";
    // When
    char* exp = data_check(string);
    char* exp_t = data_check(string_t);
    // Then
    char* real = "triangle(-8,-4;-8,4;-2,0;-8,-4)";
    char* real_t = 0;
    ASSERT_STR(exp, real);
    ASSERT_STR(exp_t, real_t);
}
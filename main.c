#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "func.h"

int main()
{
    float   a, b, c, x1, x2;
    int     roots_num;
    x1      = NAN;
    x2      = NAN;
    printf ("Введите 3 коэффициента квадратного уравнения:\n");
    scanf ("%f %f %f", &a, &b, &c);
    /// check_input(&a, &b, &c);
    if (is_zero(a)) 
    {
        roots_num = linear_eq(b, c, &x1);
    }
    else
    {
        roots_num = quadratic_eq(a, b, c, &x1, &x2);
    }
    output (roots_num, x1, x2);
    return 0;
}
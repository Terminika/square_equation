#include <stdio.h>
#include <math.h>
#include "func.h"

enum Roots {
    ZERO,   //0
    ONE,    //1
    TWO,    //2
    INF,    //3
};

float discriminant (float a, float b, float c)
{
    return b * b - 4 * a * c;
}

int is_zero(float a)
{
    if (-0.00001 < a < 0.00001)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int quadratic_eq (float a, float b, float c, float *x1, float *x2)
{
    float d, _x1, _x2;
    d = discriminant(a, b, c);
    if (d < 0)
    {
        return 0;
    }
    _x1 = (-b - sqrtf(d)) / (2 * a);
    _x2 = (-b + sqrtf(d)) / (2 * a);
    if (_x1 == _x2)
    {
        *x1 = _x1;
        return 1;
    }
    *x1 = _x1;
    *x2 = _x2;
    return 2;
}

int linear_eq (float b, float c, float *x1)
{
    if (is_zero(b) && is_zero(c))
    {
        return 3;
    }
    else if (is_zero(b) && (!is_zero(c)))
    {
        return 0;
    }
    else
    {
        *x1 = -c / b;
        return 1;
    }
}

int output(int root_num, float x1, float x2) 
{
    switch (root_num)
    {
        case ZERO:
            printf("Уравнение не имеет корней\n");
            break;
        case ONE:
            printf("Уравнение имеет 1 корень: %.4f\n", x1);
            break;
        case TWO:
            printf("Уравнение имеет 2 корня: %f %.4f\n", x1, x2);
            break;
        case INF:
            printf("Уравнение имеет бесконечно много корней\n");
            break;
        default:
            printf("Неправильный ввод\n");
    }
    return 0;
}

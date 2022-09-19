#include <stdio.h>
#include <math.h>
#include "func.h"

typedef enum {
    ZERO = 0,   //0
    ONE = 1,    //1
    TWO = 2,    //2
    INF = 3,    //3
    WRONG = 4   //4
} roots;

const float _EPSILON = 0.00000001;

float discriminant (float a, float b, float c)
{
    return b * b - 4 * a * c;
}

int is_zero(float a)
{
    if (fabsf(a) < _EPSILON)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int check_input(float *a, float *b, float *c) /// неработающая хрень
{
    float tmp_a , tmp_b, tmp_c;
    scanf ("%f %f %f", a, b, c);
    tmp_a = (float) *a; tmp_b = (float) *b; tmp_c = (float) *c;
    printf ("%f %f %f\n", tmp_a, tmp_b, tmp_c);
    while (!(tmp_a == *a && tmp_b == *b && tmp_c == *c))
    {
        printf("Введена ХУЙня\n");
        check_input(a, b, c);
    }
    return 1;
}

int quadratic_eq (float a, float b, float c, float *x1, float *x2) 
{
    float d, _x1, _x2;
    if (x1 == NULL || x2 == NULL)
    {
        return WRONG;
    }
    d = discriminant(a, b, c);
    if (d < 0)
    {
        return ZERO;
    }
    _x1 = (-b - sqrtf(d)) / (2 * a);
    _x2 = (-b + sqrtf(d)) / (2 * a);
    if (_x1 == _x2)
    {
        *x1 = _x1;
        return ONE;
    }
    *x1 = _x1;
    *x2 = _x2;
    return TWO;
}

int linear_eq (float b, float c, float *x1)
{
    if (is_zero(b) && is_zero(c))
    {
        return INF;
    }
    else if (is_zero(b) && (!is_zero(c)))
    {
        return ZERO;
    }
    else
    {
        *x1 = -c / b;
        return ONE;
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
            printf("Уравнение имеет 1 корень: %f\n", x1);
            break;
        case TWO:
            printf("Уравнение имеет 2 корня: %f %f\n", x1, x2);
            break;
        case INF:
            printf("Уравнение имеет бесконечно много корней\n");
            break;
        case WRONG:
            printf ("Произошла ошибка");
        default:
            printf("Неправильный ввод\n");
    }
    return 0;
}

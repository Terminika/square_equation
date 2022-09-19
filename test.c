#include <stdio.h>
#include "func.h"
#include <math.h>

typedef struct  {
    float a;
    float b;
    float c;
    unsigned nroot;
    float x1in; // результат работы функции quadratic_eq
    float x1out; // ожидаемый ответ
    float x2in;
    float x2out;
} test;

typedef enum {
    LINEAR = 1,
    QUADRATIC = 2,
} func;

void testF(test* test_array, unsigned sz, func function);


int main ()
{
    test arr_q[3] = {
    {1, 5, 6, 2, NAN, -3, NAN, -2},
    {1,2,1,1,NAN,-1,NAN, NAN},
    {1, 0, 0, 1, NAN, 0, NAN, NAN},
    };
    printf("Проверка quadratic_eq:\n");
    testF(arr_q, 3, QUADRATIC);

    test arr_lin[3] = {
        {0, 2, -4, 1, NAN, 2, NAN, NAN},
        {0, 0, 0, 3, NAN, NAN, NAN, NAN},
        {0, 0, 4, 0, NAN, NAN, NAN, NAN}
    };
    printf("Проверка linear_eq:\n");
    testF(arr_lin, 3, LINEAR);
}



// порядок возрастания корней
// счетчик сработавших тестов и провалившихся (по указателю передаваь переменуую и прибавлять значение)

void testF (test* test_array, unsigned sz, func function) // проверка указателя на
{
    int success_test = 0;
    for (unsigned idx = 0 ; idx < sz; idx++) 
    {
        int nroot;
        if (function == QUADRATIC)
        {
            nroot = quadratic_eq (test_array[idx].a, test_array[idx].b, test_array[idx].c, &test_array[idx].x1in, &test_array[idx].x2in);
            printf ("%d %d %f %f %f %f\n", test_array[idx].nroot, nroot, test_array[idx].x1in, test_array[idx].x1out, test_array[idx].x2in, test_array[idx].x2out);
        }
        else if (function == LINEAR)
        {
            nroot = linear_eq (test_array[idx].b, test_array[idx].c, &test_array[idx].x1in);
            printf ("%d %d %f %f %f %f\n", test_array[idx].nroot, nroot, test_array[idx].x1in, test_array[idx].x1out, test_array[idx].x2in, test_array[idx].x2out);
        }
        if (test_array[idx].nroot == nroot && 
            (test_array[idx].x1in == test_array[idx].x1out || (isnan(test_array[idx].x1in) && isnan(test_array[idx].x1out))) && 
            (test_array[idx].x2in == test_array[idx].x2out || (isnan(test_array[idx].x2in) && isnan(test_array[idx].x2out))))
            success_test++;
        else 
            printf ("ХУЙня ваш тест\n Ожидаемые ответы: %f %f\n Что получилось: %f %f\n\n",
             test_array[idx].x1out, test_array[idx].x2out, test_array[idx].x1in, test_array[idx].x2in); 
    };
    printf("Удачных тестов %d\n", success_test);
};
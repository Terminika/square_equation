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

void testF(test* test_array, unsigned sz);


int main ()
{
    test arr[3] ={
    {1, 5, 6, 2, NAN, -3, NAN, -2},
    {1,2,1,1,NAN,-1,NAN, NAN},
    {1, 0, 0, 1, NAN, 0, NAN, NAN},
    };
    testF(arr, 3);
}



// порядок возрастания корней
// счетчик сработавших тестов и провалившихся (по указателю передаваь переменуую и прибавлять значение)

void testF (test* test_array, unsigned sz) 
{
    int success_test = 0;
    for (int idx=0; idx < sz; idx++) 
    {
        int nroot;
        nroot = quadratic_eq (test_array[idx].a, test_array[idx].b, test_array[idx].c, &test_array[idx].x1in, &test_array[idx].x2in);
        printf ("%d %d %f %f %f %f\n", test_array[idx].nroot, nroot, test_array[idx].x1in, test_array[idx].x1out, test_array[idx].x2in, test_array[idx].x2out);
        if (test_array[idx].nroot == nroot && 
            (test_array[idx].x1in == test_array[idx].x1out || (isnan(test_array[idx].x1in) && isnan(test_array[idx].x1out))) && 
            (test_array[idx].x2in == test_array[idx].x2out || (isnan(test_array[idx].x2in) && isnan(test_array[idx].x2out))))
            success_test++;
        else 
            printf ("ХУЙня ваш тест\n");
    };
    printf("Удачных тестов %d\n", success_test);

};
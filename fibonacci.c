#include <stdio.h>

int F_v1(int n)
{
    return (n < 2) ? n : F_v1(n - 1) + F_v1(n - 2);
}

int F_v2(int n)
{   // Fibonacci using Dynamic Programming
    static int Fv[50] = {0,1};

    if(n > 1 && Fv[n] == 0)
    {
        Fv[n] = F_v2(n-1) + F_v2(n-2);
    }
    return Fv[n];
}

int main(int argc, char **argv)
{

    int n = 50;

    printf("Fibonacci version 2: n = %d ; f1(n) = %d\n",n,F_v2(n));
    printf("Fibonacci version 1: n = %d ; f1(n) = %d\n",n,F_v1(n));

    return 0;
}
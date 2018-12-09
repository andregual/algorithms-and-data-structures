#include <stdio.h>

int pascals_triangle(int n,int k)
{
    static int Cv[100][100];
    if(k < 0 || k > n)
        return 0;
    if(k == 0 || k == n) 
        return 1;
    if(Cv[n][k] == 0)
        Cv[n][k] = pascals_triangle(n - 1,k - 1) + pascals_triangle(n - 1,k);
    return Cv[n][k];
}

int main(int argc, char **argv)
{
    int n = 5, k = 2;
    printf("Binomial coefficient\n%dC%d = %d\n",n,k,pascals_triangle(n,k));

    return 0;
}
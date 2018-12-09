#include <stdio.h>

void heap_sort(T *data,int first,int one_after_last)
{
    int i,j,k,n;
    T tmp;
    data += first - 1;          // adjust pointer (data[first] becomes data[1])
    n = one_after_last - first; // number of items to sort
    //
    // phase 1. heap construction
    //
    for(i = n / 2;i >= 1;i--)
        for(j = i;2 * j <= n;j = k)
        {
            k = (2 * j + 1 <= n && data[2 * j + 1] > data[2 * j]) ? 2 * j + 1 : 2 * j;
            if(data[j] >= data[k])
                break;
            tmp = data[j];
            data[j] = data[k];
            data[k] = tmp;
        }
    //
    // phase 2. sort (by successively removing the largest element)
    //
    while(n > 1)
    {
        tmp = data[1]; // largest
        data[1] = data[n];
        data[n--] = tmp;
        for(j = 1;2 * j <= n;j = k)
        {
            k = (2 * j + 1 <= n && data[2 * j + 1] > data[2 * j]) ? 2 * j + 1 : 2 * j;
            if(data[j] >= data[k])
                break;
            tmp = data[j];
            data[j] = data[k];
            data[k] = tmp;
        }
    }
}


int main(int argc, char **argv)
{
    int numbers[] = {3,4,6,1,2,67,8,1,2,4,5,1,24,15,35,12,21,124,123,1255,122,6123,36,8,1,7,8,2,3,7,1,2,57,23,1235,125,124,1124,123,12,12,12,125,351,75,23,65};
    
    heap_sort(numbers, 0, 17);

    printf("\n\nProgramm finished with exit code 0\n");
    return 0;
}
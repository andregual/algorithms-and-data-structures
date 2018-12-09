#include <stdio.h>

void shell_sort(int *data, int first, int one_after_last)
{       
    int h,i,j;

    for(h = 1;h < (one_after_last - first) / 3;h = 3 * h + 1)
        ;
    while(h >= 1)
    {   // for each stride h, use insertion sort
        for(i = first + h;i < one_after_last;i++)
        {
            int tmp = data[i];
            for(j = i; j - h >= first && tmp < data[j-h];j -= h)
            {
                data[j] = data[j-h];
            }
            data[j] = tmp;
        }
        h/=3;
    }

    printf("Sorted array: \n");
    for(i = 0;i < one_after_last;i++)
    {
        printf("%d ",data[i]);
    }
}


int main(int argc, char **argv)
{
    int numbers[] = {3,4,6,1,2,67,8,1,2,4,5,1,24,15,35,12,21};
    
    shell_sort(numbers, 0, 17);

    printf("\n\nProgramm finished with exit code 0\n");
    return 0;
}
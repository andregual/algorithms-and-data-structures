#include <stdio.h>

void insertion_sort(int *data, int first, int one_after_last)
{       
    int i,j;

    for(i = first + 1;i < one_after_last;i++)
    {
        int tmp = data[i];
        for(j = i; j > first && tmp < data[j-1];j--)
        {
            data[j] = data[j-1];
        }
        data[j] = tmp;
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
    
    insertion_sort(numbers, 0, 17);

    printf("\n\nProgramm finished with exit code 0\n");
    return 0;
}
#include <stdio.h>

void bubble_sort(int *data, int first, int one_after_last)
{   // sort data[first],...,data[one_after_last - 1] in increasing order
    
    int i, i_low, i_high, i_last;

    i_low = first;
    i_high = one_after_last - 1;
    while(i_low < i_high) 
    {
        for(i = i_last = i_low;i < i_high;i++)
        {
            if(data[i] > data[i+1])
            {
                int temp = data[i];
                data[i] = data[i+1];
                data[i+1] = temp;
                i_last = i;
            }
        }
        i_high = i_last;
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
    
    bubble_sort(numbers, 0, 17);

    printf("\n\nProgramm finished with exit code 0\n");
    return 0;
}
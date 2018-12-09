#include <stdio.h>

void merge_sort(T *data,int first,int one_after_last)
{
    int i,j,k,middle;
    T *buffer;
    
    if(one_after_last - first < 40) // do not allocate less than 40 bytes
        insertion_sort(data,first,one_after_last);
    else
    {
        middle = (first + one_after_last) / 2;
        merge_sort(data,first,middle);
        merge_sort(data,middle,one_after_last);
        buffer = (T *)malloc((size_t)(one_after_last - first) * sizeof(T)) - first; // no error check!
        i = first; // first input (first half)
        j = middle; // second input (second half)
        k = first; // merged output
        while(k < one_after_last)
            if(j == one_after_last || (i < middle && data[i] <= data[j]))
                buffer[k++] = data[i++];
            else
                buffer[k++] = data[j++];
        for(i = first;i < one_after_last;i++)
            data[i] = buffer[i];
        free(buffer + first);
    }
}

int main(int argc, char **argv)
{
    int numbers[] = {3,4,6,1,2,67,8,1,2,4,5,1,24,15,35,12,21,124,123,1255,122,6123,36,8,1,7,8,2,3,7,1,2,57,23,1235,125,124,1124,123,12,12,12,125,351,75,23,65};
    
    merge_sort(numbers, 0, 17);

    printf("\n\nProgramm finished with exit code 0\n");
    return 0;
}
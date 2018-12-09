#include <stdio.h>

void rank_sort(T *data,int first,int one_after_last)
{
    int i,j,*rank;
    T *buffer;
    rank = (int *)malloc((size_t)(one_after_last - first) * sizeof(int)) - first; // no error check!
    for(i = first;i < one_after_last;i++)
        rank[i] = first;
    for(i = first + 1;i < one_after_last;i++)
        for(j = first;j < i;j++)
            rank[(data[i] < data[j]) ? j : i]++;
    buffer = (T *)malloc((size_t)(one_after_last - first) * sizeof(T)) - first; // no error check!
    for(i = first;i < one_after_last;i++)
        buffer[i] = data[i];
    for(i = first;i < one_after_last;i++)
        data[rank[i]] = buffer[i];
    free(buffer + first);
    free(rank + first);
}

int main(int argc, char **argv)
{
    int numbers[] = {3,4,6,1,2,67,8,1,2,4,5,1,24,15,35,12,21,124,123,1255,122,6123,36,8,1,7,8,2,3,7,1,2,57,23,1235,125,124,1124,123,12,12,12,125,351,75,23,65};
    
    rank_sort(numbers, 0, 17);

    printf("\n\nProgramm finished with exit code 0\n");
    return 0;
}
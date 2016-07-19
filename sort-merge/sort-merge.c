//归并排序是稳定的排序算法，即相等的元素的顺序不会改变，仍为其输入顺序。

#include <stdio.h>
// #include <stdlib.h>  //system()

void Merge(int sourceArr[], int targetArr[], int startIndex, int midIndex, int endIndex)
{
    int i, j, k;

    for(i=midIndex+1,j=startIndex; startIndex<=midIndex && i<=endIndex; j++)
    {
        if(sourceArr[startIndex] < sourceArr[i])
        {
            targetArr[j] = sourceArr[startIndex++];
        }
        else
        {
            targetArr[j] = sourceArr[i++];
        }
    }

    if(startIndex <= midIndex)
    {
        for(k=0; k<=midIndex-startIndex; k++)
        {
            targetArr[j+k] = sourceArr[startIndex+k];
        }
    }

    if(i <= endIndex)
    {
        for(k=0; k<=endIndex-i; k++)
        {
            targetArr[j+k] = sourceArr[i+k];
        }
    }

    return;
}

//内部使用递归
void MergeSort(int sourceArr[], int targetArr[], int startIndex, int endIndex)
{
    int midIndex;
    int tempArr[100];  //tempArr的大小依需求更改

    if(startIndex == endIndex)
    {
        targetArr[startIndex] = sourceArr[startIndex];
    }
    else
    {
        midIndex = (startIndex + endIndex) / 2;
        
        MergeSort(sourceArr, tempArr, startIndex, midIndex);
        MergeSort(sourceArr, tempArr, midIndex+1, endIndex);

        Merge(tempArr, targetArr, startIndex, midIndex, endIndex);
    }
}

int main(int argc, char *argv[])
{
    int a[7] = {5, 1, 2, 3, 7, 4, 6};
    int b[7];

    MergeSort(a, b, 0, 6);
    
    printf("sizeof(a): %ld\n", sizeof(a));
    printf("sizeof(*a): %ld\n", sizeof(*a));
    printf("sizeof(int): %ld\n", sizeof(int));

    for(int i=0; i<sizeof(a)/sizeof(*a); i++)
        printf("%d ", b[i]);

    printf("\n");
    
    // system("pause");

    return 0;
}


/*
sizeof(a): 28
sizeof(*a): 4
sizeof(int): 4
1 2 3 4 5 6 7 
*/
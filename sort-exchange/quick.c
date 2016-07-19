// gcc quick.c -o quick
// ./quick

#include <stdio.h>

void quick_sort(int a[], int num)
{
    int i = 0;
    int j = 0;
    int key = 0;
    
    if(a == NULL || num <= 1)
    {
        return;
    }
    
    /* 检查入参的合法性之后再初始化变量. */
    j = num - 1;
    key = a[0];
    
    while(i < j)
    {
        /* 从后向前搜索比key小的元素. */
        for( ; j>i; j--)
        {
            if(a[j] < key)
            {
                a[i++] = a[j];
                break;
            }
        }
        
        /* 从前向后搜索比key大的元素. */
        for( ; i<j; i++)
        {
            if(a[i] > key)
            {
                a[j--] = a[i];
                break;
            }
        }
    }
    
    a[i] = key;
    
    printf("a[%d] = %d\n", i, key);
    
    quick_sort(a, i);/* 对前i个数排序. */
    quick_sort(a+i+1, num-i-1);/* 对i+2到num排序. */
    
    return;
}

void output(int a[], int n)
{
    int i = 0;
    
    for(i=0; i<n; i++)
    {
        printf("%d\t", a[i]);
    }
    
    printf("\n");
    
    return;
}

int main(int argc, char *argv[])
{
    int a[10] = {0, 7, 1, 9, 8, 5, 6, 4, 2, 3};
    printf("sizeof a[]: %lu\n", sizeof(a));
    printf("sizeof int: %lu\n", sizeof(int));
    printf("Before quick sort:\n");
    output(a, 10);
    
    quick_sort(a, 10);
    printf("After quick sort:\n");
    output(a, 10);
    
    return 0;
}
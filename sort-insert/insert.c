#include <stdio.h>

void insert(int *a, int num)
{
    int i, j, temp;
    
    if(NULL == a || num <= 1)
    {
        return;
    }
    
    for(i=1; i<num; i++)
    {
        temp = a[i];
        
        for(j=i-1; (j>=0)&&(a[j]>temp); j--)
        {
            a[j+1] = a[j];
        }
        
        if(j != i-1)
        {
            a[j+1] = temp;
        }
    }
    
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
    printf("Before insert sort:\n");
    output(a, 10);
    
    insert(a, 10);
    printf("After insert sort:\n");
    output(a, 10);
    
    return 0;
}
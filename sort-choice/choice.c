#include<stdio.h>

void choice(int *a, int num)
{
    int i, j, temp, min;
    
    if(NULL == a || num <= 1)
    {
        return;
    }
    
    for(i=0; i<num-1; i++)
    {
        min = i;
        
        for(j=i+1; j<num; j++)
        {
            if(a[j] < a[min])
            {
                min = j;
            }
        }
        
        if(i != min)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
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
    printf("Before choice sort:\n");
    output(a, 10);
    
    choice(a, 10);
    printf("After choice sort:\n");
    output(a, 10);
    
    return 0;
}
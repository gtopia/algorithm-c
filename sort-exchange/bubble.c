#include<stdio.h>

void bubble(int *a, int num)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    
    if(NULL == a || num <= 1)
    {
        return;
    }
    
    for(i=0; i<num-1; i++)
    {
        for(j=i+1; j<num; j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
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
    printf("Before bubble sort:\n");
    output(a, 10);
    
    bubble(a, 10);
    printf("After bubble sort:\n");
    output(a, 10);
    
    return 0;
}
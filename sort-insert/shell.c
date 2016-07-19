#include <stdio.h>

void shell(int *a, int num)
{
    int i, j, temp, gap;
    
    if(NULL == a || num <= 1)
    {
        return;
    }
    
    for(gap=num/2; gap>0; gap/=2)
    {
        for(i=gap; i<num; i++)
        {
            temp = a[i];
            
            for(j=i-gap; (j>=0 && a[j]>temp); j-=gap)
            {
                a[j+gap] = a[j];
            }
            
            if(j != (i-gap))
            {
                a[j+gap] = temp;
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
    printf("Before shell sort:\n");
    output(a, 10);
    
    shell(a, 10);
    printf("After shell sort:\n");
    output(a, 10);
    
    return 0;
}
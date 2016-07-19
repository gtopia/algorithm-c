#include <stdio.h>

/* 根据数组a，构建大根堆. */
/* i是待调整的数组元素的下标，即调整i和i的左右子节点的相对位置. */
/* 2*i+1是i的左子节点下标，2*i+2为i的右子节点下标. */
void adjust(int *a, int num, int i)
{
    int child, temp;
    
    if(NULL == a || num <= 1)
    {
        return;
    }
    
    /*
    for( ; 2*i+1<num; i=child)
    {
        child = 2*i + 1;
        
        if((child < num-1) && (a[child+1] > a[child]))
        {
            child++;
        }
        
        if(a[child] > a[i])
        {
            temp = a[i];
            a[i] = a[child];
            a[child] = temp;
        }
        else
        {
            break;
        }
    }
    */
    
    while(2*i+1 < num)
    {
        child = 2*i + 1;
        
        if((child < num-1) && (a[child+1] > a[child]))
        {
            child++;
        }
        
        if(a[child] > a[i])
        {
            temp = a[i];
            a[i] = a[child];
            a[child] = temp;
        }
        else
        {
            break;
        }
        
        i = child;
    }
    
    return;
}

/* 从小到大排序.(用大根堆调整) */
void heap(int *a, int num)
{
    int i, temp;
    
    if(NULL == a || num <= 1)
    {
        return;
    }
    
    /* 调整序列的前半部分元素，调整后第一个元素是序列的最大元素. */
    for(i=num/2-1; i>=0; i--)
    {
        adjust(a, num, i);
    }
    
    /* 从最后一个元素开始对序列调整，不断缩小调整的范围.(每次将无序区中最大的元素放到有序的前面？) */
    for(i=num-1; i>0; i--)
    {
        temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        
        adjust(a, i, 0);
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
    printf("Before heap sort:\n");
    output(a, 10);
    
    heap(a, 10);
    printf("After heap sort:\n");
    output(a, 10);
    
    return 0;
}
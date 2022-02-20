#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int a[10], n, i, j, min;
    printf("Enter the size of the list \n");
    scanf("%d", &n);
    printf("Enter the list \n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < n; i++)
    {
        min = i;
        for(j = i + 1; j < n; j++)
            if(a[min] > a[j])
                min = j;
        swap(&a[min], &a[i]);
    }
    printf("The sorted list is \n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}

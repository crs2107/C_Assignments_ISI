#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int a[] = {12,3,45,6,43,2,17,23,14,54,87,35,78,98,24}, n = 15, i, swapping;
    //printf("Enter the size of the list \n");
    //scanf("%d", &n);
    //printf("Enter the list \n");
    //for(i = 0; i < n; i++)
        //scanf("%d", &a[i]);
    do
    {
        swapping = 0;
        for(i = 0; i < n - 1; i++)
        {

            if(a[i] > a[i + 1])
            {
                swap(&a[i], &a[i + 1]);
                swapping ++;
                //count ++;
            }
        }
    }
    while(swapping != 0);
    printf("The sorted list is  \n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    //printf("Number of comparisons needed is %d\n",count);
    return 0;
}

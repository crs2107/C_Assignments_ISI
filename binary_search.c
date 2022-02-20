// Binary Search Implementation 
#include <stdio.h>

int binary_search(int a[], int , int , int );
int main()
{
    int a[10],  x, n, i, r;
    printf("Enter the size of your array \n");
    scanf("%d", &n);
    printf("Enter the array in ascrending order \n"); //because binary search works only for sorted arrays
    for(i = 1; i <= n; i++)
        scanf("%d",&a[i]); 
    printf("Enter the number that you want to search\n ");
    scanf("%d", &x);
    u = n;
    r = binary_search(a, 0, n-1, x);
    (r == -1)
    ? printf("%d is not in the given array\n", x)
    : printf("%d is the %d-th element of the array\n.", x, r);
    return 0;
}

int binary_search(int a[], int l, int u, int x)
{
    if( l <= u) 
    {
        int mid  = l + (u - l)/2; //here we are defining the midpoint in the interval
        if(a[mid] == x)  // here we are checking if x is the midpoint 
            return mid; 
        else if(a[mid] > x) // here if x is less than the midpoint then we are going to search x only in the left side of the midpoint
            return binary_search(a, l, mid - 1, x);
        else
            return binary_search(a, mid + 1, u, x);
    }
    return -1;

}

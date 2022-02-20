#include<stdio.h>

int main()
{
    int n , i , a[100] ;
    printf("enter the number\n");
    scanf("%d", &n) ;
    
    for ( i = 0 ; n>0 ; i++ )
    {
        a[i] = n%2 ;
        n = n/2 ;
    }

    printf("after converting the binary number is : \n");

    for ( i = i-1 ; i>= 0 ; i-- )
    {
        printf("%d" , a[i]);
    }
    printf("\n");

    return 0 ;
}

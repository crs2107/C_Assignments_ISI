#include<stdio.h>

int ncr ( int , int  );
int fact (int); 

int main()
{
    int n , i , j;
    printf("enter the number of rows\n");
    scanf("%d" , &n);

    for(i = 0 ; i<= n; i++)
    {
        for(j = 0 ; j<= n-i ; j++)
        {
            printf("  ");
            
        }
        for(j = 0 ; j <= i ; j++)
        {
            printf("%3d",ncr(i,j));
        }
        printf("\n");
    }
}

int ncr (n , r)
{
    return (fact(n)/(fact(n-r)*fact(r))) ;
}

int fact (n)
{
    int factorial = 1;
    for (factorial = 1; n>1 ; n--)
    {
        factorial = factorial * n ;
    }
    return factorial ;
}

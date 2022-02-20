#include<stdio.h>
#include<math.h>
int main()
{
    int N,i;
    printf("Enter the number\n");
    scanf("%d",&N);
    if ( check_prime(N) == 1)
        printf("it is prime\n");
    else
        printf("not prime\n");
    for(i=2 ; i<N ; i++)
    {
        if(check_prime(i) == 1)
            printf("it is prime \n");

    }
    return 0;

}

int check_prime(n)
{
    int r , flag = 0, temp = 0;
    for(r = 1 ; r< sqrt(n); r++)
    {
        if (n%r == 0)
            flag ++ ;
          
    }
    if ( flag == 1 && n >1 )
        temp = 1;
    return temp;
}

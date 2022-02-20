/*Write a C program to print N Fibonacci numbers which are prime.*/

#include<stdio.h>
#include<math.h>

int check_prime (int n) 
{
     int i , flag = 0;
     float sqrt_n = pow(n,0.5);

     for(i = 2 ; i <= sqrt_n ; i++)
     {
         if(n%i == 0)
         {
             flag = 1;
             break ;
         }
        
     }
     return flag;
}

int main()
{

     int N , i ,j=0, a[100] , b[50];
     printf("Please enter the value of N \n");
     scanf("%d",&N);

     a[0] = 1;
     a[1] = 1;

     for(i=2; i<N ; i++)
     {
         a[i] = a[i-1] + a[i-2];
         if(check_prime(a[i])==0)
         {
             b[j] = a[i];
             j++ ;
         }
     }
     printf("%d Fibonacci numbers which are prime are : \n",j);
     for(i=0 ; i <j ; i++)
     {
         printf("%d\n",b[i]);
     }

     return 0;
     
      
}

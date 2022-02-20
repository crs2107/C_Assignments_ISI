/*Write a C program to compute the sum of 1+x+x^2/2!+x^3/3!+......................+x^n/n! when x and n
are given (take these as inputs).*/
#include<stdio.h>
int main() {
     
     int n,i;

     float x, sum,term ;

     sum = 1. ;

     term = 1. ;


     printf("please enter the value of n \n");

     scanf("%d",&n);

     printf("please enter the value of x\n");

     scanf("%f",&x);

     for(i = 1 ; i <= n ; i++) {

         
         term = term*(x/i);

         sum = sum + term ;

        
        }
     printf("the required sum is %f \n",sum);

     return 0;


     }

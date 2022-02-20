/* Given two matrices A and B, you need to write a C program to get C=AB (Multiplication of A and B)*/

#include<stdio.h>

int main()

{

     int n , m , n1 , m1 , a[5][5] , b[5][5], c[5][5] ;
     int i , j , k;
     printf("Please enter the order of the matrix A : \n");
     scanf("%d%d",&n,&m);
     printf("Please enter the order of the matrix B : \n");
     scanf("%d%d",&n1,&m1);

     if( m != n1 )
     {
         printf("The multiplication is not possible\n");
     }

     else
     {
         for(i = 0 ; i < n ; i++) 
         {
             for(j=0 ; j< m; j++)
             {
                 printf("Enter the value of a[%d][%d] : \n",i,j);
                 scanf("%d",&a[i][j]);
             }
             

         }

         for(i = 0 ; i < n1 ; i++) 
         {
             for(j=0 ; j< m1; j++)
             {
                 printf("Enter the value of b[%d][%d] : \n",i,j);
                 scanf("%d",&b[i][j]);
             }
             

         }

        
         for(i=0;i<n;i++)
         {

              for(j=0;j<m1;j++)
              {
                     c[i][j] = 0 ;

                     for(k=0;k<m;k++)
                         c[i][j]=c[i][j]+a[i][k]*b[k][j];
              }
         }
         printf("after multiplication the C matrix is \n  ");

         for(i=0 ; i<n; i++)
         {  
             for(j=0 ; j<m1; j++)
                 printf("c[%d][%d] = %d \n   ",i,j,c[i][j]);
         }




     }
     return 0;

}

#include<stdio.h>
#include<math.h>

int main()
{
 int n , r ;
 printf("enter the number\n");
 scanf("%d",&n);
 
 printf("Prime digits: \n");
 while (n>0)
 {
   r = n%10;
   n = n/10;
   
   if(r == 2 || r == 3 || r== 5 || r == 7)
     {
       printf("%d\n",r);
     }
 }
 return(0);

 }

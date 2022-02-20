#include<stdio.h>
void swap (*int , *int);
void main()
{
 int a , b ,*x , *y;
 printf("enter the two numbers\n");
 scanf("%d%d",&a,&b);
 x = &a;
 y = &b;
 swap(x,y);
 printf("after swapping the values are %d and %d \n",a,b);
 }
void swap(*x,*y)
{
int c;
c = *x;
*x = *y;
*y = c;
printf("after swapping the values are %d and %d",*x,*y);
}

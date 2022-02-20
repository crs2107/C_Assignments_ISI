#include<stdio.h>
void main()
{
 int x[10],n,i,max,second_max,temp = 0;
 printf("enter the length of the array\n");
 scanf("%d",&n);
 for( i =0; i<n ; i++ )
 {
   printf("enter the number %d ",i+1);
   scanf("%d",&x[i]);
 }
 
 max = x[0];
 second_max = x[1];
 if (max < second_max)
 {
   temp = max ;
   max = second_max;
   second_max = temp;
 }
 for(i = 2; i<n ; i++)
 {
  if(x[i]>max)
    {
        second_max = max;
        max = x[i];
    }
  else if(x[i] > second_max && x[i] != max)
        second_max = x[i];
  
 }
printf("the largest element is %d\n",max);
printf(" the second largest element is %d\n",second_max);
}

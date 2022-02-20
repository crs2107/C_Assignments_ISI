/*Given two sets (x and y) of values. Find the correlation coefficient between x and y.*/

#include <stdio.h>
#include<math.h>
int main()
{
    int i,n;
    float a[100],b[100],x_mean=0,y_mean=0,sd_x=0,sd_y=0,cor=0;
    printf("Enter the number of elements for x or y\n");
    scanf("%d",&n);
    printf("Enter the values for x\n");
    for(i=0;i<n;i++)
        scanf("%f",&a[i]);

    printf("Enter the values for y\n");
    for(i=0;i<n;i++)
        scanf("%f",&b[i]);

    for(i=0;i<n;i++)
    x_mean=x_mean+a[i];
     x_mean=x_mean/n;


     for(i=0;i<n;i++)
    y_mean=y_mean+b[i];
     y_mean=y_mean/n;


    for(i=0;i<n;i++)
    {
        sd_x=sd_x+(x_mean-a[i])*(x_mean-a[i]);
    }
    sd_x=sd_x/n;
    sd_x=pow(sd_x,0.5);


    for(i=0;i<n;i++)
    {
        sd_y=sd_y+(y_mean-b[i])*(y_mean-b[i]);
    }
    sd_y=sd_y/n;
    sd_y=pow(sd_y,0.5);


    for(i=0;i<n;i++)
    {
        cor=cor+(x_mean-a[i])*(y_mean-b[i]);
    }
    cor=cor/(n*sd_x*sd_y);

    printf(" \n correlation coefficient between x and y is %f\n",cor);
     return 0;
}


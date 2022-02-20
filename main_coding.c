// To find the largest element from the text file 
#include<stdio.h>
#include <stdlib.h>

int maximum_element(int arr[], int n)
{
    int i; 
    int max = arr[0] ;

    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
 
    return max;
}


int main()
{

    int i,n,max, a[20] = {0};
    FILE *ip, *op;
    ip = fopen("/home/samipa/Coding_Practice/file_input.txt","r");
    op = fopen("/home/samipa/Coding_Practice/output.txt", "w+");


    if(ip==NULL)
    {
            printf("No such file in directory.\n");
            fprintf(op,"No such file in directory.\n");
            return(0);
    }

    fscanf(ip,"%d",&n);

    for(i = 0; i < n; i++)
        fscanf(ip,"%d" ,&a[i]);

    max = maximum_element ( a , n ) ;
    printf("Max is %d \n",max);
    fprintf(op," The maximum element is %d \n",max);
    fclose(ip);
    fclose(op);
    return(0);
}



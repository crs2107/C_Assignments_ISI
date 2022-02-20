#include<stdio.h>
#include <stdlib.h>

int main()
{

    int i,count_num, x, num[20] = {0}, flag = 0;
    FILE *ip, *op;
    ip = fopen("/home/samipa/Coding_Practice/file_input.txt","r");
    op = fopen("/home/samipa/Coding_Practice/x.txt", "w+");
    if(ip==NULL)
    {
        printf("No such file in directory.\n");
        fprintf(op,"No such file in directory.\n");
        return(0);
    }
    printf("enter x: ");
    scanf("%d", &x);
    fscanf(ip,"%d",&count_num);
    for(i = 0; i < count_num; i++)
        fscanf(ip,"%d",&num[i]);
    for(i=0; i < count_num; i++)
        if(x == num[i])
        {
            flag = 1;
            break;
        }
    if(flag == 1)
    {
        printf("%d is %dth element of the array.\n",x,i + 1);
        fprintf(op,"%d is %dth element of the array.\n",x,i + 1);
    }
    else
    {
        printf("%d is not present in the array.\n", x);
        fprintf(op,"%d is not present in the array.\n",x);
    }    fclose(ip);
    fclose(op);
    return(0);
}

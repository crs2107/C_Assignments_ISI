#include<stdio.h>
#include<stdlib.h>

int insertionsort(int *arr,int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        key = *(arr+i);
        //inserting arr+i into the sorted sequence arr+1,...arr+(i-1)
        j=i-1;
        while(key<*(arr+j) && j>=0)
        {
            *(arr+(j+1))=*(arr+j);
            j--;
        }
        *(arr+(j+1))=key;
    }
    return 0;
}
int main()
{
    int *arr,i,n;
    printf("Enter the no. of elements\n");
    scanf("%d",&n);
    //taking the array as input
    arr=(int*)malloc(n*sizeof(int));

    printf("Enter the  elements to be sorted\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",(arr+i));
    }

    insertionsort(arr,n);

    printf("The final sorted array is\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",*(arr+i));
    }


    return 0;
}


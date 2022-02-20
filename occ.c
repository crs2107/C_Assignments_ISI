#include<stdio.h>
int main(){
    int M,N,i,j,arr[100][100] ,c[201]={0} ;
  
    printf("please input the no of rows\n");
    printf("please input the number of columns\n");
    scanf("%d",&M);
    scanf("%d",&N);
    for( i = 0 ; i < M; i++){
         for(j = 0 ; j < N; j++){
             printf("Enter the values for arr[%d][%d] : ",i,j);
             scanf("%d",&arr[i][j]);
         }
    }
    for( i = 0 ; i < M; i++){
         for(j = 0 ; j < N; j++){
             c[arr[i][j]]++;
         }
    }
    for(i=0 ; i<=200 ; i++){
         if(c[i]!=0)
             printf("occurence of %d = %d \n",i,c[i]);
    }
    return 0;


    }

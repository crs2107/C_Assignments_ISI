#include<stdio.h>
void swap(int *a , int *b)
{
    int temp;
    temp = *a ;
    *a = *b ;
    *b = temp;
}
int main(){
    int M,N,i,j,arr[100][100] ;
  
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
         for(j = 0 ; j < N-1; j++){
             swap (&arr[i][j],&arr[i][j+1]);
         }
    }
    for( i = 0 ; i < M; i++){
         for(j = 0 ; j < N; j++){
             printf("after reversing the matrix is arr[%d][%d] : %d\n",i,j,arr[i][j]);
            
         }
    }



       return 0;


    }



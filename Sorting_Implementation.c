#include<stdio.h>
#include<stdlib.h>

int count_quick_sort = 0, count_merge_sort = 0;
int partition(int* , int , int);
void swap(int *x , int *y )
{
    int temp ;
    temp = *x ;
    *x = *y ;
    *y = temp;
}

void print_array(int a[], int a_size)
{
    int i;
    for(i=0;i<a_size;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int * copy_array(int a[], int a_size)
{
    int *new_array = (int*)malloc(sizeof(int)*a_size);
    int i;
    for(i=0 ; i<a_size ; i++)
    {
        new_array[i] = a[i];
    }
    return new_array;
}

void bubbleSort(int a[] , int a_size)
{
    int *arr = copy_array(a,a_size);
    //printf("after copying the array is \n");
    //print_array(arr,a_size);
    int i , j , count = 0;
    for( i=0 ; i<(a_size-1); i++ )
    {
        for(j=0 ; j<(a_size-i-1); j++)
        {
            count++;
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j] , &arr[j+1]);
            }

        }
    }
    printf("After using bubble sort the array is\n");
    print_array(arr,a_size);
    printf("Number of comparisons is %d\n",count);
}

void selectionSort(int a[], int a_size)
{

    int *arr = copy_array(a,a_size);
    //printf("after copying the array is \n");
    //print_array(arr,a_size);
    int i,j,min, count = 0;
    for( i=0 ; i<a_size ; i++ )
    {
        min = i;
        for (j=i+1 ; j<a_size ; j++ )
        {
            count ++;
            if(arr[min]>arr[j])
            {
                min = j;
            }
        }
        if( min != arr[i] )
        {
            swap(&arr[i],&arr[min]);
        }
    }
    
    printf("After using selection sort the array is\n");
    print_array(arr,a_size);
    printf("Number of comparisons is %d\n",count);
    
}

void insertionSort(int a[], int a_size)
{
    //printf("after copying the array is \n");
    int *arr = copy_array(a,a_size);
    //print_array(arr,a_size);
    int i, j, c, count = 0;
    for(i = 1; i < a_size; i++)
    {
        c = a[i];
        j = i - 1;
        count += i;
        while(arr[j] > c && j >= 0)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = c;
    }
    printf("After using insertion sort the array is\n");
    print_array(arr,a_size);
    printf("Number of comparisons is %d\n",count);

}

void quickSort(int a[], int low, int high)
{ 
  
    if (low < high)
    {
        int q = partition(a, low, high);
        quickSort(a, low, q - 1);
        quickSort(a, q + 1, high);
    }

}
int partition (int arr[],int  low, int  high)
{

    int pivot = arr[low], start = low, end = high, count =0;
    while(start < end)
    {
        while(arr[start] <= pivot)
        {
            start++;
            count_quick_sort++;
        }
        while(arr[end] > pivot)
        {
            end--;
            count_quick_sort++;
        }
        if(start < end)
            swap(&arr[start], &arr[end]);
    }
    swap(&arr[low], &arr[end]);
    return end;
}
void merge(int arr[], int l, int m, int r)
{
	int i = l, j = m + 1, k = l;
    int b[r+1];

	while (i <= m && j <= r)
	{
		if (arr[i] <= arr[j])
        {
			b[k] = arr[i];
			i++;
		}
		else
		{
			b[k] = arr[j];
			j++;
		}
        count_merge_sort++;
		k++;
	}

	while (i <= m)
    {
		b[k] = arr[i];
		i++;
		k++;
	}

	while (j <= r)
    {
		b[k] = arr[j];
		j++;
		k++;
	}
	for(k = l; k <= r; k++)
        arr[k] = b[k];
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r)
    {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

int main()
{
    int a[] = {12, 3, 45, 6, 43, 2, 17, 23, 14, 54, 87, 35, 78, 98, 24}, a_size = 15;
    printf("The given array is\n");
    print_array(a,a_size);
    printf("*************************************\n");
    bubbleSort(a,a_size);
    printf("*************************************\n");
    selectionSort(a,a_size);
    printf("*************************************\n");
    insertionSort(a,a_size);
    printf("*************************************\n");
    printf("After using quick sort the array is\n");
    int *arr = copy_array(a,a_size);

    quickSort(arr,0,a_size-1);
    print_array(arr,a_size);
    printf("Number of comparisons is %d\n",count_quick_sort);
    printf("*************************************\n");
    printf("After using merge sort the array is\n");
    int *b = copy_array(a,a_size);
    mergeSort(b,0,a_size-1);
    print_array(b,a_size);
    printf("Number of comparisons is %d\n",count_merge_sort);
    printf("*************************************\n");

    return 0;

}





#include <stdio.h>


void swap(int* , int* );
int partition (int array[], int , int );
void quickSort(int array[], int , int );
void printArray(int array[], int );


int main()
{
    int array[] = { 45,10,4,88,90,2,5,78,23 };
    int n = sizeof(array) / sizeof(array[0]);
    printf("The given array is\n");
    printArray(array, n);
    quickSort(array, 0, n - 1);
    printf("The final sorted array is\n");
    printArray(array, n);
    return 0;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int array[], int p, int r)
{
    int x = array[r];
    int i = p-1;
    for (int j = p; j < r; j++) 
    {

        if (array[j] <= x) 
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i+1],&array[r]);
    return (i+1);
}

void quickSort(int array[], int p, int r)
{
    if (p < r)
    {
        int q = partition(array, p, r);
        quickSort(array, p, q - 1);
        quickSort(array, q + 1, r);
    }
}

void printArray(int array[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}



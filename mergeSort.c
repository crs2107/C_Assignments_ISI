#include <stdio.h>

void merge(int arr[], int , int , int );
void mergeSort(int arr[], int , int );
void printArray(int arr[], int );

int arr_size;


int main()
{
	int arr[] = { 67,55,3,45,13,11,100,98,4,5 };

	arr_size = sizeof(arr) / sizeof(arr[0]);


	printf("The given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("The final sorted array is \n");
	printArray(arr, arr_size);
	return 0;
}


void merge(int arr[], int p, int q, int r)
{
	int i = p, j = q + 1, k = p;
    int b[arr_size];

	while (i <= q && j <= r)
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
		k++;
	}

	while (i <= q)
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
	for(k = p; k <= r; k++)
        arr[k] = b[k];
}

void mergeSort(int arr[], int p, int r)
{
	if (p < r)
    {
		int q = p + (r - p) / 2;

		mergeSort(arr, p, q);
		mergeSort(arr, q + 1, r);

		merge(arr, p, q, r);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


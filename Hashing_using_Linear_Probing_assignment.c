//Using Linear Linear probing
#include<stdio.h>
#define TABLE_SIZE 10

int a[TABLE_SIZE];

void creating_array()
{
    int i;
    for(i=0 ; i<TABLE_SIZE ; i++)
    {
        a[i] = 0;  //initiating the values of the array as null
    }
}
int modular_hash_func(int value)
{
    int key = value % TABLE_SIZE;
    return key;
}

void Insert(int x)
{
    int i;
    for( i=0 ; i<TABLE_SIZE; i++ )
    {
        if(a[modular_hash_func(x+i)] == 0)
        {
            a[modular_hash_func(x+i)] = x;
            //printf("Insertion of %d is succesful at the %d th position of the hash table\n",x,modular_hash_func(x+i));
            break;
        }
        
    }
    if(i == TABLE_SIZE)
    {
        printf("%d cannot be inserted using linear probing\n",x);
    }
    

}
int Find(int x)
{
    int key = modular_hash_func(x),i;
    for( i=0 ; i<TABLE_SIZE ; i++ )
    {
        if(a[modular_hash_func(x+i)] == x)
        {
            return 1;
        }
    }
    return 0;
}
int Delete(int x)
{
    int key = modular_hash_func(x),i;
    if( Find(x) == 0 )
    {
        printf("There is no such element to delete from the hash table\n");
        return 0;
    }
    else if(Find(x) == 1)
    {
        for(i=0 ; i<TABLE_SIZE ; i++)
        {
            if(a[modular_hash_func(x+i)] == x)
            {
                a[modular_hash_func(x+i)] = 0;
                printf("%d is successfully deleted from the position %d of the hash table\n",x,modular_hash_func(x+i));
                return 1;
            }
        }
    }

}

void print_array()
{
    int i;
    for(i=0 ; i<TABLE_SIZE ;i++)
    {
        printf("a[%d] = %d\n",i,a[i]);
    }
}

int main()
{
    creating_array();
    int arr[] = {25, 37, 28, 45, 49, 70, 89, 81, 31, 22, 43, 56, 73, 68},i;
    for(i=0; i<14; i++)
    {
        Insert(arr[i]);

    }
    printf("Using the hash function the hash table corresponding to the given key values is\n");
    print_array();
    printf("Now after inserting the values 35,32,42,52,66,76,59,69\n");
    Insert(35);
    Insert(32);
    Insert(42);
    Insert(52);
    Insert(66);
    Insert(76);
    Insert(59);
    Insert(69);
    printf("The hash table is\n");
    print_array();
    int a[] = {37, 45, 81, 56, 66};
    for(i=0 ; i<5 ; i++)
    {
        Delete(a[i]);
        printf("After deleting %d the hash table is\n",a[i]);
        print_array();
    }

    int b[] = {32,42,76,68,66};

    for(i=0 ; i<5 ; i++)
    {
        if(Find(b[i]) == 1)
        {

            printf("The element %d is present in the list\n",b[i]);
        }
        else if(Find(b[i]) == 0)
        {
            printf("the element %d is not present in the list\n",b[i]);
        }
    }

    return 0;


}


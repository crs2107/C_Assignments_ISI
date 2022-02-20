#include<stdio.h>
#include<stdlib.h>

typedef struct node node ;
struct node
{
    int value;
    node *prev;
    node * next;
};
node *root;

void print_element(void);
void insert_element(unsigned, unsigned);
void delete_element(int);
void remove_duplicate_element(void);
int find_middle_element(void);
void sort_elements(void);
int find_maximum_element(void);
float find_average(void);
void reverse_list(void);
int len_list(void);

int main()
{
    int c;
    root=NULL;
    while(1)
    {
        printf("***********\n");
        printf("press 1: To print the elements of the list\n");
        printf("press 2: To insert an element in the list\n");
        printf("press 3: To delete an element from the list\n");
        printf("press 4: To remove the duplicate elements\n");
        printf("press 5: To find the length of the list\n");
        printf("press 6: To find the middle element of the list\n");
        printf("press 7: To sort the linklist\n");
        printf("press 8: To find the maximum element of the list\n");
        printf("press 9: To find the average of the elements of the list\n");
        printf("press 10: To reverse the elements of the list\n");
        printf("press 0: To end the program\n");
        printf("*************\n");

        printf("enter your option : \n");
        scanf("%d",&c);
        printf("************\n");

        switch(c)
        {
        case 0:
            exit(1);
        case 1:
            print_element();
            break;
        case 2:
        {   unsigned loc, val;
            printf("enter the location you want to insert\n");
            scanf("%d",&loc);
            printf("enter the value you want to insert\n");
            scanf("%d",&val);
            insert_element(loc,val);
            break;
        }
        case 3:
        {
            int val;
            printf("enter the element you want to delete\n");
            scanf("%d",&val);
            delete_element(val);
            break;
        }
        case 4:
            remove_duplicate_element() ; 
            break;
        case 5:
        {
            int l; 
            l = len_list();
            printf("the length of the list is %d\n",l);
            break;
        }
       case 6: 
            printf("the middle element is %d\n",find_middle_element());
            break;
       case 7:
            sort_elements();
            break;
        case 8:
            printf("the maximum element is %d",find_maximum_element());
            break;
        case 9:
            printf("the average element is %f",find_average());
            break;
        case 10:
            reverse_list();
            break;


        default:
            printf("Invalid input:try again!!\n");
        }

    }

    return(0);
}
void insert_element(unsigned location, unsigned val)
{
    unsigned i ;
    node *p,*temp;
    p=root;
    temp=(node*)malloc(sizeof(node));
    temp->value = val;

    for(i=0;i<location && p;i++)
    {
        if (!p->next) break ; // to avoid segmentation error
        p = p->next ;
    }
    if(!p)
    {
        root = temp;
        temp->prev = 0;
        temp->next = 0;
    }
    else
    {
        //printf("enter the value that you want to add\n");
        //scanf("%d",&temp->value);
        temp->next = p->next;
        temp->prev = p;
        p->next = temp;
        if(temp->next != NULL)
        {
            temp->next->prev = temp;
        }

    }

    
}

void print_element()
{
    node *p;
    p=root;
    if(p==NULL)
    {
       printf("there is no element in the list\n");
    }
    else
    {
        while(p->next!=NULL)
        { 
            printf("%d--->",p->value);
            p=p->next;
        }
        printf("%d.\n\n",p->value);
    }
}
void delete_element(int val)
{
    node *p,*temp;
    temp = root;
    while (temp)
    {
        if (temp->value == val) {
            // Gotcha
            if(!temp->prev)
            {
                root = temp->next;
            }
            else
            {
                temp->prev->next = temp->next;
            }

            if (temp->next)
            {
                temp->next->prev = temp->prev ;
            }
            return ;
        }
        temp = temp->next;
    }
}



void remove_duplicate_element()
{
    node *runner1,*runner2;
    runner1 = root;
    while(runner1)
    {
        runner2 = runner1->next ;
        while(runner2)
        {
            if(runner2->value == runner1->value)
            {
                runner2->prev->next = runner2->next ;
                if(runner2->next)
                {
                    runner2->next->prev = runner2->prev;
                }
            }
            runner2 = runner2->next;
        }
        runner1 = runner1->next ;
    }


}
int len_list()
{
    int length=0;
    node *p;
    p = root;
    while(p)
    {
        p = p->next;
        length++;
    }
    return length;

}
int find_middle_element()
{
    int l = len_list(), mid, i;
    if(l%2 == 0)
    {
        mid = (l/2)-1;
    }
    else
    {
        mid = (l-1)/2;
    }
    node *p;
    p = root;
    printf("mid = %d\n",mid);
    printf("LENGTH = %d\n",l);
    for(i=0;i<mid;i++)
    {
        p = p->next;
    }
    
    return (p) ? p->value: -999999;//using ternary operation to handle the empty list

}
void sort_elements()
{
    node *current,*index;
    current = root;
    index = 0;
    int temp;
    if(!root)
    {
        return;
    }
    else
    {
        while(current)
        {
            index =  current->next;
            while(index)
            {
                if(current->value > index->value)
                {
                    temp = current->value;
                    current->value = index->value;
                    index->value =  temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }

}
int find_maximum_element()
{
    sort_elements();
    node *p;
    p = root;
    while(p)
    {
        p = p->next;
    }
    return p->value;
}
float find_average()
{
    node *p;
    float avg=0;
    int sum=0 , l = len_list();
    if (!l) return 0;
    p = root;
    while(p)
    {
        sum = sum + p->value;
        p = p->next;
    }
    avg = (float)sum/l ;
    return avg;
}

void reverse_list()
{
    node *prev = 0 ;
    node *next = 0 ;
    node *current = root ;
    while(current) {
        next = current->next ;
        current->next = prev ;
        current->prev = next ;
        prev = current ;
        current = next ;
    }
    root = prev ;
}






    

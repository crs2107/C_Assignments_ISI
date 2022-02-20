
#include <stdio.h>
#include <stdlib.h>
struct node
{
int value;
struct node * next;
};
int len;
struct node *root;
void print_elements(void);
void add_beginning(void);
void add_end(void);
void add_middle(void);
void  add_end(void);
void delete_middle(void);
void delete_beginning(void);
void delete_end(void);
int length(void);

int main()
{
    int a,b;
    int c;
    root=NULL;
    while(1)
    {
            printf("\n =================\n");
            printf("Press 1 : for Printing the elements of the List. \n");
            printf("Press 2 : for Inserting an element to the beginning. \n");
            printf("Press 3 : for Inserting an element to the middle. \n");
            printf("Press 4 : for Inserting an element to the end. \n");
            printf("Press 5 : for Deleting an element from the middle of the List. \n ");
            printf("Press 6 : for Deleting an element from the end of the List. \n ");
            printf("Press 7 : for Deleting an element from the beginning of the List. \n ");
            printf("Press 8 : for finding the length of the List. \n ");

            printf("Press 9 : for Exit from the Program. \n");

            printf("\n =================\n");


            printf("Enter your option : ");
            scanf("%d",&c);

            printf("\n =================\n");


            switch(c)
            {
                    case 1:
                        print_elements();

                        break;
                    case 2:
                        add_beginning();
                        break;


                    case 3:
                        add_middle();
                        break;

                    case 4:
                        add_end();
                        break;


                    case 5:
                        delete_middle();
                        break;

                    case 6:
                        delete_end();
                        break;

                    case 7:
                        delete_beginning();
                        break;


                    case 8:
                        printf("\n The length of the list is %d",length());
                        break;

                    case 9:
                        exit(1);
                    default:
                        printf("Invalid Input: Please try again \n");
                    }

        }

    return 0;
}

void add_beginning()
{
    struct node *p,*temp;
    p=root;
    temp=(struct node *)malloc(sizeof(struct node));

    if(root==NULL)
        printf("Please check the input, as there is no element in the list \n");
    else
    {
            printf("Enter the value that you want to insert at the beginning of the existing list: \n ");
            scanf("%d",&temp->value);
            root=temp;
            temp->next=p;
    }


}

void print_elements()
{
   struct node *p;
   p=root;
   if(p==NULL)
    printf("There is no element in the list \n");
   else
   {

      while(p->next!=NULL)
       {
              printf("%d -->",p->value);
              p=p->next;
       }
       printf("%d. \n\n",p->value);
    }
}

void add_end()
{
    struct node *p,*temp;
    p=root;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value that you want to insert at the end of the existing list: \n");
    scanf("%d",&temp->value);
    temp->next=NULL;
    if(root==NULL)
        root=temp;
    else
    {
         while(p->next!=NULL)
         {
                 p=p->next;
         }
         p->next=temp;
    }
    temp->next=NULL;
}
    
    
 void add_middle(void)
    {
         struct node *p,*q,*temp;
         int location,i;
         p=root;
         q=root;
         temp=(struct node *)malloc(sizeof(struct node));
         printf("Enter the value that you want to insert in  list: \n");
         scanf("%d",&temp->value);
         printf("Enter the location where you want to insert the element");
         scanf("%d",&location);
        for (i=1;i<location-1;i++)
        {
            p=p->next;
        }
    
        for (i=1;i<=location-1;i++)
        {
           q=q->next;
        }
        p->next=temp;
        temp->next=q;
    
    }
    
    
    void delete_middle(void)
    {
        struct node *p,*q;
        int location,i;
        if(root==NULL)
            printf("There is no element in the list");
    
        else
        {
            printf("\n Enter the location of the list from where you want to delete the element: ");
            scanf("%d",&location);
            if(location>=length())
            {
                printf("The location is more than equal to the no of elements in the list \n");
            }
            else
            {
                p=root;
                q=root;
                for(i=1;i<location-1;i++)
                p=p->next;
                for(i=1;i<location+1;i++)
                q=q->next;
                p->next=q;
    
            }
        }
    
    }
    
                                                                                                                                                                void delete_end()
    {
        struct node *p;
        int i=1;
        p=root;
        while (i<length()-1)
        {
            p=p->next;
            i++;
        }
        p->next=NULL;
    }
    
    
    
                                                                                                                                                                void delete_beginning()
    {
        struct node *p;
        int i;
        p=root;
        p=p->next;
        root=p;
    }
    
    int length()
    {
        struct node *p;
        int l=1;
        p=root;
        if(p==NULL)
        return 0;
        else
        {
            while(p->next!=NULL)
                {
                    p=p->next;
                    l++;
                }
            return(l);
        }
    }
    
    
                                                                                                                                                                                                                                                                                                                                                                     

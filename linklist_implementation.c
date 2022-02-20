/*Create a linked-list of N (take as input) nodes where data part of each node contains
student name (string), age (integer), class (string) and marks (in Mathematics). Now,
print the names of students who have received more than 80% marks Mathematics.
Print NONE if no such student is there. Also, print the name of the student who has
received the lowest marks.*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node
{
        char name[10];
        int age;
        char Class[10];
        float percentage;
   struct node *next;
};
int main()
{
struct node *head=NULL,*newnode,*temp,*minimum;
int i=1,n,k;
char c;
printf("enter the number of students:\n");
scanf("%d", &n);
while(i<n+1)
{
scanf("%c", &c);
newnode=(struct node *)malloc(sizeof(struct node));
printf("Enter name of the %dth Student: \n", i);
gets(newnode->name);
printf("Enter age of the %dth Student: \n", i);
scanf("%d", &newnode->age);
printf("Enter class of the %dth Student: \n", i);
scanf("%s", newnode->Class);
printf("Enter percentage of the %dth Student: \n", i);
scanf("%f", &newnode->percentage);
newnode->next=NULL;
if(head == 0)
            head = temp = newnode;
        else
        {
            temp->next =newnode;
            temp =newnode;
        }
        i++;
}
temp = head;
i = 1;
int sum = 0;
//minimum=temp;
struct node *ptr = head;
while(ptr != NULL)
{
    sum = sum+ptr->percentage;
    ptr = ptr->next;
}
float avg = sum/n ;
printf("The average is %f\n",avg);
printf("The students who got  more than average percent:\n");
while(i <= n)
    {
        if(temp -> percentage > avg)
        {
            printf("\n%s", temp -> name);
            k++;
        }
        /*if(minimum->percentage > temp -> percentage)
            minimum = temp;
        temp = temp -> next;
        i++;
    }
    if(k == 0)
        printf("NONE");
    printf("The student who got the lowest marks:%s\n",minimum->name);
    printf("\n");*/
    return 0;
    }
}

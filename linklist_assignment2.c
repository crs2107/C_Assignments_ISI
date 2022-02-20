/*1. Write a C program to create a linked-list of N (take as input) nodes where data part of 
each node contains only student name. Now, create its reverse linked list and print it.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct student student;
struct student
{
    char name[20];
    student *next;
};

void reverse(student** head);

int main()
{
    student *head, *new_student, *temp;
    int N, i = 1;
    char nothing;
    head = 0;
    printf("Enter the number  of students\n");
    scanf("%d", &N);
    while(i <= N)
    {
        scanf("%c", &nothing);
        new_student = (student*)malloc(sizeof(student));
        printf("Enter name of the %d th student\n", i);
        scanf("%[^\n]", new_student -> name);
        new_student -> next = 0;
        if(head == 0)
            head = temp = new_student;
        else
        {
            temp -> next = new_student;
            temp = new_student;
        }
        i++;
    }
    temp = head;
    i = 1;
    printf("The name of the studnets are\n");
    while(i <= N)
    {
        if (i == N)
            printf("%s\n", temp -> name);
        else
            printf("%s --> ", temp -> name);
        temp = temp -> next;
        i++;
    }

    reverse(&head);
    printf("After reversing the name of the studnets are\n");
    i = 1;
    temp = head;
    while(i <= N)
    {
        if (i == N)
            printf("%s\n", temp -> name);
        else
            printf("%s --> ", temp -> name);
        temp = temp -> next;
        i++;
    }
    //printf("\n")
    return 0;
}


void reverse(student** head)
{
    student* prev = NULL;
    student* current = *head;
    student* next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

    



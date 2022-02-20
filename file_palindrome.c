/* Given an input file. You need to write a C program (using function) to select only those
words which are Palindrome from this file and print those words in a new file.*/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int check_palindrome(char string[]) //returns 0 if not palindrome and 1 if palindrome
{
    int i, l ;
    int flag = 1;
    
    l = strlen(string) ;

    for (i=0 ; i<l ; i++)
    {
        if(string[i] != string[l-i-1])
        {
            flag = 0;
            break;
        }
    }
    
    return flag;

}

int main()
{
    char word[50] ;
    FILE *ip, *op;
    //printf("Enter the input file name: ");
    //scanf("%s", name);
    ip = fopen("/home/samipa/Coding_Practice/palindrome_input.txt","r");
    op = fopen("/home/samipa/Coding_Practice/palindrome_output.txt", "w+");
    if(ip==NULL)
    {
        printf("No such file in directory.\n");
        fprintf(op,"No such file in directory.\n");
        return(0);
    }
    while((fscanf(ip,"%s",word)) == 1)
    {
      
        if(check_palindrome(word) == 1)
        {
            fprintf(op , "%s\n" , word);
            printf("%s\n",word);
        }
    }

    fclose(ip);
    fclose(op);
    return(0);
}



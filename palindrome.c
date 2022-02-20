#include<stdio.h>
#include<string.h>


void check_palindrome(char s[])
{

  int i = 0 , n ;
  n = strlen(s) - 1;
  while(n > i)
    {
         if(s[i++] != s[n--])
         {
             printf("%s is not a palindrome\n",s);
             return;
         }
    }
  printf("%s is a palindrome\n",s);
}
int main()
{
    char s[100];
    printf("Enter the string : ");
    scanf("%[^\n]s",s);
    check_palindrome(s);
}

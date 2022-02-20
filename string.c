#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
 char a[10];
 char *b = "samipa";
 char *c;

 assert(argc == 3) ;
 c = (char *)malloc(atoi(argv[1]));
 printf("Garbage => %s\n",c) ;
 strcpy(c, argv[2]);
 printf("Value   => %s\n",c) ;

 return 0; 
}

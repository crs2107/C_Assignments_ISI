/* Write a C program to remove all comments from a C program file (take a C file as an
input). */

#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp , *fq ;
    char c ;

    fp = fopen( "/home/samipa/Coding_Practice/converting_string.c" , "r" ) ;
    fq = fopen ( "/home/samipa/Coding_Practice/new_text.txt" , "w+" ) ;
    if(fp == NULL)
    {
        printf("No such file in the directory.");
        fclose(fq);
        return 0;
    }

    while ( (c = fgetc(fp)) != EOF ) 
    {
        if ( c == '/' )
        {
            c = fgetc(fp) ;
            if ( c == '/' )
            {
                do
                    c = fgetc(fp);
                while ( c != '\n' );
                printf("%c",c);
                fprintf( fq,"%c",c );

            }
            else if ( c == '*' )
            {
                while ( (c = fgetc(fp)) != EOF  )
                    if ((c == '*') && (c = fgetc(fp) == '/'))
                        break;
            }
            else 
            {
                fprintf(fq , "/%c",c);
                printf("/%c",c);
            }
        }

        else
        {
            printf("%c",c);
            fprintf(fq,"%c",c);
        }
        
    }
    fclose(fp);
    fclose(fq);
    return 0;
}

/* A file (take its name as input) contains list of some alphabetic English words. Write a
C program that will take each English word from the file and for each word print (on
the screen) a respective word as its output where all non-vowel characters will be in
the beginning of the output word and all the vowels at the end of the non-vowels. For
example, if a word in the file is “Statisical” then the output of this word will be
‘Sttsclaiia’.*/

#include<stdio.h>
#include<string.h>

int main()
{

    int i,j,k,n;
    char word[20], vowel[20], consonent[20],  file_name[20];
    FILE *ip;
    printf("Enter the name of the input file \n");
    scanf("%s", file_name);
    ip = fopen(file_name,"r");
    if(ip == NULL)
    {
        printf("No such file in directory.\n");
        return(0);
    }
    while(fscanf(ip,"%s",word) == 1)
    {
        j = 0;
        k = 0;
        n = strlen(word);
        for(i=0; i < n; i++)
        {
            if(word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o' && word[i] != 'u' && word[i] != 'A' && word[i] != 'E' && word[i] != 'I' && word[i] != 'O' && word[i] != 'U')
            {
                consonent[j] = word[i];
                j++;
            }
            else      //here we are keeping the consonents in the consonent array and keeping the vowels in the vowel array
            {
                vowel[k] = word[i];
                k++;
            }
        }
        
        consonent[j] = 0; //to reset the last word to avoid junk elements
        vowel[k] = 0;
        printf("%s%s ", consonent,vowel); // printing as it was said in the question
        
    }
    printf("\n");
    fclose(ip);
    return(0);
}




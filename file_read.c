#include <stdio.h>
#include <stdlib.h>

int main()
{
	// This program reads a file from its arguments and prints word by word. Additionally, it counts the words in the file.

	char * filename = "/home/samipa/Downloads/test.txt";
	FILE * fp = fopen(filename, "r");
	if (fp == NULL) return 1;
	char c;
	int count = 0;
	long n;

	fseek(fp, -10, 2);    //this comments goes to 10 bytes back from the last position)

	while((c = fgetc(fp)) != EOF)
	{
		if(c == ' ' || c == '\n')
		{
			printf("\n");
			++count;
			n= ftell (fp);   //this will give you ftell information
			printf("value of n is =========================%ld\n", n);
		}
		else
		{
			printf("%c", c);
		}
	}
	fclose(fp);

	printf("This file has %d words in it.", count);
	return 0;
}



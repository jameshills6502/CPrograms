#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	FILE * pFile;
	char sentence[256], choice;
	long lSize;
	char* buffer;
	size_t result;
	printf("\nPlease input your name and age for the record");
	fgets(sentence, 256, stdin);
	//The fgets takes the user input and inputs it into a file, 256 refers to max no. of char
	//that are to be copied into, stdin is a pointer to a FILE object that identifies an 
	//input stream, stdin means standard input
	pFile = fopen("myfile.txt", "a, r");
	if (pFile!=NULL);
	{	
		fputs(sentence, pFile);
		printf("Would you like to see what is already in the file?");
		scanf("%c", &choice);
		if (strcmp(&choice, "y") == 0)
		{
			printf("Ok, here is the rest of the file");
			fseek(pFile, 0, SEEK_END);
			lSize = ftell(pFile);
			rewind(pFile);
			//these three obtain the file size
			buffer = (char*)malloc(sizeof(char)*lSize);
			if (buffer == NULL){fputs("Memory error",stderr); exit(1);}
			//these allocate memory to contain the whole file]
			result = fread(buffer,1,lSize,pFile);
			if (result != lSize){fputs("Reading error", stderr); exit(2);}
			//these cope the file into the buffer
			printf("%ld", result);
		}
		fclose(pFile);
		free(buffer);
	}
}

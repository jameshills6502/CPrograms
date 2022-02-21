#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
char encrypt();
int home_selection();
FILE* ignoreline(FILE* stream)
{
	for(int c;(c = fgetc(stream))!= EOF;)
	{
		if(c == '\n')
		{
			break;
		}
	}
	return stream;
}

int main()
{
	char plaintext[1000] = "", ciphertext[1000] = "", space[] = " ", upper_string[1000] = "";
	int shiftvalue, asciivalue, lenplaintext;
	
	printf("\nWelcome to the Caesar Cipher program! \n");
	int getchar();
	home_selection();
}

int home_selection()
{
	char home_choice;
	int entry[10], loop, take_input;
	printf("\n----HOME----\n");
	do
	{
		printf("\n Please select one of the following options \n");
		printf("\n	1. Encrypt	\n");
		printf("\n	3. Quit		\n");
		printf("\n:");
		while((take_input = getchar()) != '\n' && take_input != EOF)
		{
			entry[loop] = take_input;
			loop++;
			fflush(stdin);
			if(loop >= 9)
			{
				printf("\n Input too large!");
				break;
			}
		}
		home_choice = entry[loop-1];
		int home_choice_ascii = home_choice;

		if(home_choice_ascii >= 49 && home_choice_ascii <= 51)
		{
			if(home_choice_ascii == 49)
			{
				printf("\n Starting encryption");
				encrypt();
			}
			else if(home_choice_ascii == 50)
			{
				printf("\n Starting decryption");
			}
			else
			{
				printf("\n Quitting....");
				break;
			}
		}
		else
		{
			printf("\n Please select a valid option");
		}
		fflush(stdin);
		fflush(stdout);
	}
	while(1);
}

char encrypt(char *plaintext, char *ciphertext, int lenplaintext, int *shiftvalue, char *space, char *upper_string)
{
	int take_input, loop;
	loop = 0;
	printf("\n Please input the sentence you would like to encrypt:");
	//while(fgets(plaintext, 1000, stdin) != NULL)
	//{
	//	if(plaintext[0] == '\n')
	//	{
	//		break;
	//	}
	//}
	while((take_input = getchar()) != '\n' && take_input != EOF)
	{
		plaintext[loop] = take_input;
		loop++;
		fflush(stdin);
		if(loop >= 100)
		{
			printf("\n "
		}
	}
	printf("You entered '%s' \n", plaintext);
	fflush(stdin);
}

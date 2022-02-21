#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main
{
	home_choice();
}


int home_choice
{
	char home_choice;
	int entry[10], loop, take_input;
	printf("\n Please select an option from below");
	loop = 0;
	do
	{
		printf("\n 1. Start Program");
		printf("\n 2. See details");
		printf("\n 3. Quit");
		while((take_input = getchar()) != '\n' && take_input != EOF)
		{
			if(loop >= 9)
			{
				printf("\n Input too large!");
				break;
			}
			entry[loop] = take_input;
			loop++;
			fflush(stdin);
		}
		if(home_choice == 49)
		{
			printf("\n You have chosen 1");
			program();
		}
		if(home_choice == 50)
		{
			printf("\n You have chosen 2");
		}
		if(home_choice == 51)
		{
			printf("\n Quitting...");
			break;
		}
		else
		{
			printf("\n Please pick a valid option!");
		}
	}
	while(1);
}

int program()
{
	char name[20];
	printf("\n Welcome to the program");
	printf("\n Please input your full name for the record");
	printf("\n:");
	scanf("%[^\n]s", name);
	printf("\n Your name is: %s", name);
	printf("\n Please input your ")
}

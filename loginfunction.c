#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
char readfrom(char *data, char *username, int already_exists);
int main(void)
{
	FILE * file;
	long size;
	char* buffer;
	size_t result;
	char username[25] = "", password[25] = "", data[256];
	int already_exists;
	already_exists = 0;
	file = fopen("login.txt", "a");
	if(file!=NULL);
	{
		while(1)
		{
			printf("\nPlease input your login: ");
			printf("\nUsername: ");
			scanf("%s", username);
			readfrom(data, username, already_exists);
			printf("\n Here is the delimeter value after the function %d", already_exists);
			if(already_exists == 0)
			{
				fputs("\n", file);
				fputs(username, file);
				printf("\nUsername has been entered into file!");
				break;
			}
			else if(already_exists == 1)
			{
				printf("\nUsername already exists!");
			}
		}
	}
	fclose(file);
}

char readfrom(char *data, char *username, int already_exists)
{
	FILE *file;
	long size;
	char* buffer;
	size_t result;
	int i;
	file = fopen("login.txt", "r");
	//MAKE SURE THAT IT GOES THROUGH EACH LINE, NOT THE WHOLE FILE IN ONE GO
	while (fgets(data, 256, file))
	{
		for(i=0; i<=sizeof(data); i++)
		{printf("\n data[i] == %c", data[i]);}
		//the line above goes through each character in a line. It can be seen that
		//some of the code overlaps, so the array data needs to be reset each time.
		printf("%s", data);
		printf("\n Looping...");
		if(strcmp(data, username) == 0){already_exists = 1;
		printf("\n Here is the delimeter value in the if %d", already_exists);
		break;}
		else if(strcmp(data, username) != 0){already_exists = 0;}
		else
		{printf("\n Here is the delimeter value in the else %d", already_exists);}
	}
}


//THIS PROGRAM DOESN'T CURRENTLY WORK, AS I CANNOT GET THE FILE TO BE READ PROPERLY
//I CAN HOWEVER APPEND PROPERLY

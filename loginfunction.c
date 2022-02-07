#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
char readfrom(char *data, char *username);
int main(void)
{
	FILE * file;
	long size;
	char* buffer;
	size_t result;
	int already_exists;
	char username[25] = "", password[25] = "", data[256] = "";
	already_exists = 0;
	file = fopen("login.txt", "a");
	if(file!=NULL);
	{
		while(1)
		{
			already_exists = 0;
			printf("\nPlease input your login: ");
			printf("\nUsername: ");
			scanf("%s", username);
			already_exists = readfrom(data, username);
			printf("\n Here is the delimeter value after the function %d", already_exists);
			if(already_exists > 0 || already_exists < 0)
			{
				fputs("\n", file);
				fputs(username, file);
				printf("\nUsername has been entered into file!");
				break;
			}
			else if(already_exists == 0)
			{
				printf("\nUsername already exists!");
			}
		}
	}
	fclose(file);
}

char readfrom(char *data, char *username)
{
	FILE *file;
	long size;
	char* buffer;
	size_t result;
	int i, already_existing;
	char lenusername;
	file = fopen("login.txt", "r");
	//MAKE SURE THAT IT GOES THROUGH EACH LINE, NOT THE WHOLE FILE IN ONE GO
	while (fgets(data, 256, file))
	{
		
		lenusername = sizeof(username);
		//the line above goes through each character in a line. It can be seen that
		//some of the code overlaps, so the array data needs to be reset each time.
		printf("\n Here is the string %s", data);
		if(strncmp(data, username, lenusername) == 0){break;}
		else if(strncmp(data, username, lenusername) < 0 || strncmp (data, username, lenusername) > 0){printf("Looping...");}
	}
	return already_existing;
}


//THIS PROGRAM DOESN'T CURRENTLY WORK, AS IT SAYS THAT ALL THE INPUTS HAVE ALREADY BEEN INPUTTED

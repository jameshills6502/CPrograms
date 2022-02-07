#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int home_selection();
char revised_string_check();
char decrypt();
char revised_upper();
char encrypt();
char DEBUG();
char Input();
// when passing strings, they have to be passed with pointers!!! hence the *
// defining of functions
int main()
{
	char plaintext[100] = "", ciphertext[100] = "", space[] = " ", upper_string[100] = "";
	int shiftvalue, asciivalue, lenplaintext;

	printf("\nWelcome to the Caesar cipher program! \n");
	//home_selection();
	home_selection();
}

int home_selection()
{	
	char home_choice;
	int home_choice_length;
	printf("\n----HOME----\n");
	do{
		printf("\n Please select one of the following options \n");
		printf("\n	1. Encrypt	\n");
		printf("\n	2. Decrypt	\n");
		printf("\n	3. Quit		\n");
		printf("\n:");	
		Input(home_choice);	// gets input //
		printf("%d", home_choice);
		//buffer needs to be cleared!!!
		int home_choice_ascii = home_choice;
		if(home_choice_ascii >= 49 && home_choice_ascii<= 51)
		// the ascii values of number 1-3
		{
			if(home_choice_ascii == 49) // user chooses 1 //
			{
				printf("\n Starting encryption");					
				encrypt();
			}
			else if(home_choice_ascii == 50) // user chooses 2 //
			{
				printf("\n Starting decryption");
				decrypt();
			}
			else // user chooses 3 //
			{
				printf("\n Quitting");
				break;
			}
		}
		else // user inputs invalid option //
		{
			printf("\n Please select a valid option");
		}
	}while(1);
	// this repeats until the user chooses to quit the program //
}

char encrypt(char *plaintext, char *ciphertext, int lenplaintext, int shiftvalue, char *space, char *upper_string)
{
	printf("\n Please input the sentence you would like to encrypt:");
	DEBUG(plaintext); 	// takes in blank space as well to allow for sentences //
	printf("\n Please input the shift amount: ");
	shiftvalue = getchar(); // stores the shift amount in shiftvalue //
	lenplaintext = strlen(plaintext); // length of plaintext found //
	revised_upper(lenplaintext, plaintext, upper_string); // calls revised_upper function //
	revised_string_check(space, upper_string, ciphertext, shiftvalue); // calls revised_string_check function // 
	printf("\n The correct ciphertext should appear to be %s", ciphertext);
	return 0;
}

char decrypt(char *upper_string, char *space)
{
	char encrypted[100] = "", decrypted[100] = "";
	int loop, len_encrypted;

	printf("\nTHIS IS THE DECRYPT FUNCTION\n");
	// should take user input and decode from caesar cipher //
	printf("\n Please input the sentence you would like to decrypt:");
	scanf("%[^\n]%*c", encrypted); // gets user input for the sentence to be decrypted //
	len_encrypted = strlen(encrypted); // gets length of string //
	revised_upper(len_encrypted, encrypted, upper_string); // calls the upper function //
	printf("\n string is now %s", upper_string);
	for(loop=0;loop<25;loop++) // this loops through for every single possible combination //
	{
		//NEEDS TO BE REVERSIBLE SO DOUBLE CHECK THIS
		revised_string_check(space, upper_string, decrypted, loop);
		printf("\n String at shift value %d: %s \n", loop, decrypted);
		memset(decrypted, 0, len_encrypted); // resets value in decrypted so it doesn't append new values to previous string values //
	}
}

char revised_string_check(char *space, char *string, char *new_string, int shiftvalue)
{
	int loop, string_length, newshiftedvalue;

	// this algorithm checks the bounds of string and makes sure these
	// are in line with the bounds of the alphabet
	string_length = strlen(string);
	for(loop=0;loop<string_length;loop++)
	{
		char tempchar;

		tempchar = string[loop];
		if(tempchar == 32)
		// ASCII value of space
		{
			strncat(new_string, space, 1);
		}
		else if(tempchar >= 65 && tempchar <= 90){
			//ASCII values of alphabet
			newshiftedvalue = shiftvalue % 26; // finds the new shift value incase user inputted a very large value such as 1000 //
			newshiftedvalue = tempchar + newshiftedvalue; // this calculates ciphertext //
			if(newshiftedvalue >= 65 && newshiftedvalue <= 90){
				char tempchar_2 = newshiftedvalue;

				strncat(new_string, &tempchar_2, 1); // appends if an in alphabetical range //
			}
			else if(newshiftedvalue > 90){
				//this means final output would be out of alphabet bounds // 
				newshiftedvalue = 64 + (newshiftedvalue - 90);
				char tempchar_2 = newshiftedvalue;

				strncat(new_string, &tempchar_2, 1);
			}
			else
			// final output would be lower than alphabet
			// this is incase shiftvalue is a negative value
			{
				newshiftedvalue = 64 - (newshiftedvalue);
				char tempchar_2 = newshiftedvalue;

				strncat(new_string, &tempchar_2, 1);
			}
		}
		else
		{
			printf("\n Current character %c isn't supported \n", tempchar);
			strncat(new_string, space, 1);	
		}
	}
	memset(string, 0, string_length); //re-initialises string so it can be used again //
}

char revised_upper(char *string,char *upper_string)
{
	int loop, string_length;

	string_length = strlen(string); // gets length of string // 
	//this re-initialises upper_string so it the variable can be re-used // 
	for(loop=0;loop<string_length;loop++) // Creates loop which
	{
		char tempchar;
		if(string[loop] >= '0' && string[loop] <= '9'){ // This removes numbers from input // 
			printf("\n Character %d isn't supported", string[loop]);} // shows the user what character isn't supported
		else{
			tempchar = toupper(string[loop]); // this makes the character and upper character // 
			strncat(upper_string, &tempchar, 1);}
	}
	return *upper_string;
	memset(upper_string, 0, string_length); // re-initialises upper_string so it can be used again //
}

char Input(int input)
{
	char *buffer, h;
	int input_length;
	size_t bufsize = 32;
	input_length = sizeof input;
	buffer = (char *)malloc(bufsize * sizeof(char));
	if(buffer == NULL)
	{
		perror("\n Unable to allocate buffer");
		exit(1);
	}
	while((input = getchar()) != '\n' && input != EOF)
	{
		fflush(stdin);
	}
	printf("\n %d", input);
	h = input;
	memset(&input, 0, input_length);
	return input;

}


char DEBUG(char *output)
{
	char *buffer;
	size_t input;
	size_t bufsize = 32;
	buffer = (char *)malloc(bufsize * sizeof(char));
	if(buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	input = getline(&buffer, &bufsize, stdin);
	return *output;
}

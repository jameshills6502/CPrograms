#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
int upper(char plaintext[200],int lenplaintext);
int main(char plaintext_upper[200]);
int main(char plaintext_upper[200])
{
	int lenplaintext, lenciphertext, i;
	char plaintext[200] = "", ciphertext[200] = "";
	//here, we are defining plaintext and ciphertext as strings, and including
	//variables for their length
	int shiftvalue, asciivalue;
	printf("Welcome to the Caesar cipher program!\n");
	printf("\nPlease input your sentence you would like to encrypt: ");
	scanf("%[^\n]%*c", plaintext);
	printf("This is the sentence you are encrypting%s", plaintext);
	printf("\nPlease input the shift amount:");
	scanf("%d", &shiftvalue);
	//The & is the address of shiftvalue
	printf("\nThis is the shift amount%d", shiftvalue);
	printf("\nThis is what you're gonna encrypt %s", plaintext);
	lenplaintext = strlen(plaintext);
	printf("\nThis is the length %d", lenplaintext);
	i = 0;
	//defines the length of the plain text under variable name lenplaintext
	upper(plaintext, lenplaintext);
	//while i is not greater than lenplaintext
	while (i<lenplaintext)
	{
			char tempchar;
			int shiftedvalue, tempshiftedascii;
			printf("\nThis is the character %c", plaintext_upper[i]);
			//NOT FINAL CODE ^^^^^^^ CURRENTLY BEING TESTED
			printf("\nThis is the value for i %d", i);
			tempchar = plaintext_upper[i];
			printf("\nThis is temp char %c", tempchar);
			//this is testing^^^^^^^^
			//stores the individual letter from plaintext under a temporary
			//variable
			if (tempchar == 32)
			{
				char space[] = " ";
				strncat(ciphertext, space, 1);
				i = i + 1;
			}
			//this above should convert the temporary character found
			//in the string to ascii so we can shift it up
			else
			{
				shiftedvalue = tempchar + shiftvalue;
				printf("\nThis is the shifted value %d", shiftedvalue);
			//adds the shiftvalue to the ascii value
				char tempcipherchar = shiftedvalue;
				printf("\nThis is the tempcipherchar %c", shiftedvalue);
			//this should convert back from ascii value to the new
			//ciphertext
				strncat(ciphertext, &tempcipherchar, 1);
				printf("\nThis is the cipher text so far %s", ciphertext);
				i = i + 1;
			}

	}
	printf("\nThe correct ciphertext should now appear to be %s", ciphertext);
	return 0;
	//CURRENT PROBLEMS INCLUDE:
	// -ASCII ALSO GOES HIGHER THAN z, THEREFORE IF SHIFT VALUE IS GREATER THAN
	// z, IT WILL DISPLAY CHARACTERS UNCHARACTERISTIC OF A CAESAR CIPHER
}

int upper(char plaintext[200], int lenplaintext)
{
	int i;
	i = 0;
	char plaintext_upper[200] = "";
	while (!(i>lenplaintext))
	{
		char tempchar;
		tempchar = toupper(plaintext[i]);
		strncat(plaintext_upper, &tempchar, 1);
		i = i + 1;
	}
	return plaintext_upper[200];
	return 0;
}

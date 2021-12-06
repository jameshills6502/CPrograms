#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
char upper(char *plaintext, char *plaintext_upper, int lenplaintext);
char range(int shiftvalue, char *ciphetext, int lenplaintext, char *intermediate_ciphertext);
// when passing strings, they have to be passed with pointers!!! hence the *
int main()
{
	char plaintext[100] = "", ciphertext[100] = "", plaintext_upper[100] = "", intermediate_ciphertext[100]= "";
	//all these strings correspond to different parts of the algorithm i.e. plaintext_upper
	//corresponds to the upper function. 100 is currently the default max size setting, and
	//unfortunately I cannot define an array with a random value, as I can only currently
	//calculate length after having taken in the actual string, in this case 'plaintext'
	int shiftvalue, asciivalue, lenplaintext, lenciphertext, i;
	printf("Welcome to the Caesar cipher program! \n");
	printf("\nPlease input your sentence you would like to encrypt: ");
	scanf("%[^\n]%*c", plaintext);
	//this line essentially means "take in input including blank space"
	printf("\nPlease input the shift amount: ");
	scanf("%d", &shiftvalue);
	lenplaintext = strlen(plaintext);
	//here calculating length of the base user input, referenced now as 'lenplaintext'
	i = 0;
	//forming the while loop here. I know it would be better to use a for loop, but for
	//simplicity's sake, I'm using a while loop here
	upper(plaintext, plaintext_upper, lenplaintext);
	//calling the upper function here, taking the base user input and its length as inputs
	//and returning plaintext_upper, which is just the base user input in all uppercase
	while(i<lenplaintext)
	{
		char tempchar;
		int shiftedvalue, tempshiftedascii;
		tempchar = plaintext_upper[i];
		//here, the program is taking out the character in the string location of 'i'
		//and designating it as a temporary character
		if(tempchar == 32)
		//if the temporary character has the ASCII value of 32, which is the value of 
		//a space, a space will be appended to the intermediate_ciphertext string
		{
			char space[] = " ";
			strncat(intermediate_ciphertext, space, 1);
			//strncat takes 3 arguments. The first takes in where to add the
			//wanted input. The second is the input that is wanted to be taken.
			//The last is how big we expect the input to be
			i = i + 1;
		}
		else
		{
			shiftedvalue = tempchar + shiftvalue;
			//here, we are adding any other character to the intermediate_ciphertext
			//array. The shiftedvalue variable is essentially the new ASCII value
			//after the shift has been applied to the temporary character
			char tempcipherchar = shiftedvalue;
			//this converts the ASCII value into a character
			strncat(intermediate_ciphertext, &tempcipherchar, 1);
			i = i + 1;
		}
	}
	range(shiftvalue, intermediate_ciphertext, lenplaintext, ciphertext);
	//here, the range function is called. This essentially calculates the range of
	//the alphabet and keeps the output inside this range. 
	//This needs to exist as obviously ASCII includes more than just the english alphabet
	//and so range makes sure this isn't the case for ASCII shifted values. This is also
	//why I needed to make the user input all upper case
	printf("\nThe correct ciphertext should now appear to be %s", ciphertext);
	return 0;
}

char upper(char *plaintext, char *plaintext_upper, int lenplaintext)
{
	int i;
	i = 0;
	while(i<lenplaintext)
	{
		char tempchar;
		// here the indiviual characters are put into upper case
		// and appended to a new array
		tempchar = toupper(plaintext[i]);
		strncat(plaintext_upper, &tempchar, 1);
		i = i + 1;
	}
	return *plaintext_upper;
	//returns the pointer to the plaintext_upper array
}

char range(int shiftvalue, char *intermediate_ciphertext, int lenplaintext, char *ciphertext)
{
	//this function is supposed to keep the letters in the range of the alphabet, which
	//is 26
	int ranges_of_alphabet, i;
	//in order to keep shifted values in range of alphabet, we need to look at the sentence
	//as if z is used and shifted, it has to stay in range
	//as alphabet is 26 long, and A = 65, then 65-91 is range
	for(i=0; i<lenplaintext; i++)
	{
		char tempchar, newinput;
		tempchar = intermediate_ciphertext[i];
		int asciivalue = tempchar;
		if(asciivalue > 90)
		{
			int tempno;
			tempno = 64 + (asciivalue - 90);
			char newinput = tempno;
			strncat(ciphertext, &newinput, 1);
		}
		else if(asciivalue < 65 && asciivalue != 32)
		//here if the ascii value is less than 65, it could include spaces, as these
		//have an ASCII value of 32
		{
			int tempno;
			tempno = 65 - (shiftvalue);
			char newinput = tempno;
			strncat(ciphertext, &newinput, 1);
		}
		else
		{
			strncat(ciphertext, &tempchar, 1);
		}
	}
}


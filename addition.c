#include <stdio.h>
int main(void)
{
	int number1;
	int number2;
	printf("Enter a number between 1 and 10");
	scanf("%d", &number1);
	printf("Enter a number between 1 and 10");
	scanf("%d", &number2);
	printf("The sum of %d and %d is %d", number1, number2, (number1+number2));
	return 0;
}
	

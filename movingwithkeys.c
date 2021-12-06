#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char ch, entry[200] = "";
	printf("Enter keys (ESC to exit)\n");
	while(1)
	{
		ch = getchar();
		printf("\n Here is the decimal value %d", ch);
		printf("\n You have entered: %c\n", ch);
		strncat(entry, ch, 10);
		if(ch == 27){printf("\n ESCAPE");}
		else if(ch == 10){printf("\n ENTER");}
		else if(ch == 66 && ch == 27){printf("\n MOVE DOWN");}
		else if(ch == 68 && ch == 27){printf("\n MOVE LEFT");}
		else if(ch == 67 && ch == 27){printf("\n MOVE RIGHT");}
		else if(ch == 65 && ch == 27){printf("\n MOVE UP");}
		strlen()
		for(int i; i=0; i<lenentry; i++)
	}	
	printf("You have entered: %c\n", ch);
}

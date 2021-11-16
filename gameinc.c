#include <stdio.h>
#include <unistd.h>
#include <string.h>
int themaingame(void);
int main(void)
{
	while (1)
	{	
		char yesorno;
		printf("\nHello and welcome to The Game");		
		printf("\nWould you like to play? (Y/N)");
		scanf("%c", &yesorno);
		if (yesorno == 'Y')
		//because the variable yesorno has a character datatype			
		////in the comparison, the statement MUST BE IN SINGLE QUOTES 
		{
			printf("\nYou've chosen to play");
			themaingame();
			break;
		}
		else if (yesorno == 'N')
		{
			printf("\nYou've chosen to not play, bye bye!");
			break;
		}
		else
		{
			printf("\nPlease select again");
		}
	}
	
}
int themaingame(void)
{
	while (1)
	{
		char firstmove[200];
		printf("\nThe way the game works is you choose an item that could be in the room, such as (door)which will then let you interact with that item.");
		sleep(8);
		printf("\n---BEGIN---");
		sleep(1);
		printf("\nShrouded in the world's worst hangover, you pull yourself up off the wet floor");
		sleep(3);
		printf("\nGetting your bearings, you notice that you're in a bathroom cubicle, your hand sat soaking in a very used toilet bowl");
		sleep(4);
		printf("\nDisgusted, you pull yourself up and grab some single ply toilet paper to attempt to dry it off");
		sleep(4);
		printf("\nAs your head pounds, you look towards the door and notice that, even though it won't budge, there is no lock on your side");
		sleep(4);
		printf("\nYou then.......");
		scanf("%s", firstmove);
		if (strcmp(firstmove, "toilet") == 0)
		{
			printf("\nYou stand on the edge of the toilet seat, peering over the cubicle door");
			break;
			sleep(3);
		}
		else if (strcmp(firstmove, "door") == 0)
		{
			printf("\nYou attempt to open the door again, it moves a little");
			break;
		}
		else if (strcmp(firstmove, "under") == 0)
		{
			printf("\nYou realise there are other cubicles next to you, and decide to try and climb underneath the stall walls to the one next to you");
			break;
		}
		else
		{
			printf("You stand there, contemplating what to do next");
		}
	}
}


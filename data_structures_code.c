#include <stdio.h>		//Importing the necessary modules needed for the program to run//
#include <string.h>

static struct { char strVal[21]; int intVal; } tuple[11];		//This creates a data structure that takes two values one string and one integer. It then calls this structure tuple//
static int tupleCount = 0;		//This sets a global variable which records how many tuples there currently are//

static void listTuples(void) {		//The function of this procedure is to print the information stored in each tuple//
	printf("There are %d tuples\n", tupleCount);		//Prints the amount of tuples there are//
	for (int i = 0; i < tupleCount; ++i) {		//This is set up in such a way that it will 
		printf("[%s] -> %d\n", tuple[i].strVal, tuple[i].intVal);		//Prints the value stored in the data structure, both the string value and the ineger value//
	}
}

static void addTuple(char *str, int val) {		//The purpose of this function is to be able to make an new tuple and add it to the tuple list//
	printf("Adding '%s, %d' \n", str, val);		//Prints out exactly what the program intends to add to the tuple list//
	strcpy(tuple[tupleCount].strVal, str);		//Copies the string value you said into the string section of the tuple//
	tuple[tupleCount++].intVal = val;		//Makes it so that the integer value of the next avalible tuple becomes what you entered//
}

static void deleteTuple(char *str) {		//The purpose of this function is to be able to delete specific tuple sets based on the string value it contains//
	int index = 0, i = 0;		//This sets the necessary variables needed within this function// 
	while (index < tupleCount) {		//Checks to make sure we don't go looking outside of the boundries of the tuple array//
		if (strcmp(str, tuple[index].strVal) == 0) break;		//If what the user entered is the same as that tuples string value then//
		++index;		//Otherwise increase the value of index//
	}
	if (index == tupleCount) {		//This only is true if the length of the tuple list is zero//
		printf("The tuple list is empty.\n");		//Tells the user the list is empty//
		return;
	}
	printf("Deleting '%s, %d' \n", str, tuple[index].intVal);		//Tells the user which tuple it is deleting//
	for (i = index; i < tupleCount - 1; i++) {		//This will only look at the values after th eone the user has said they want to delete//
		strcpy(tuple[i].strVal, tuple[i + 1].strVal);		//Replaces the previous location in the tuple list with the information that follows it. Effectively, geting rid of the tuple set at the index of index//
		tuple[i].intVal = tuple[i + 1].intVal;		//Same as the previous line but for the integer value instead//
	}
	--tupleCount;		//After getting rid of a tuple set then reduce the length of the tuple list by one to prevent unecessary complications//
}

static void swap(int index) {		//The purpose of this is to swap two tuples that are located next to each other//
	++tupleCount;		//Need temporary space to be able to swap two values//
	strcpy(tuple[tupleCount - 1].strVal, tuple[index].strVal);		//Copy the string at index to the temporary space//
	tuple[tupleCount - 1].intVal = tuple[index].intVal;		//Copy the integer at index to the temporary space//
	strcpy(tuple[index].strVal, tuple[index + 1].strVal);		//Replace the integer value of the tuple at index with the one at the tuple after index//
	tuple[index].intVal = tuple[index + 1].intVal;		//Replace the string value of the tuple at index with the one at the tuple after index//
	strcpy(tuple[index + 1].strVal, tuple[tupleCount - 1].strVal);		//Copy the string value stored in the temporary location to the tuple after index//
	tuple[index + 1].intVal = tuple[tupleCount - 1].intVal;		//Copy the integer value stored in the temporary location to the tuple after the index//
	--tupleCount;		//Remove the temporary storage spot//
}

static int tupleSort(int q, int w) {		//The purpose of this function is to check the integer values in each tuple set to see if they need swapping in order to be sorted//	
	if (tuple[w].intVal > tuple[w+1].intVal) {		//This checks if the integer value at index is greater then the integer value of the tuple after index//
		swap(w);		//If the one at index is bigger then go to swap//
	}
	w++;
	if (w == tupleCount - q) {		//If w is at the end of the list of tuples//
		w = 0;		//Reset w//
		q++;		//Increase q//
	}
	if (q == tupleCount) {		//If it has reached the end of the list of tuples//
		return 0;
	}
	tupleSort(q, w);		//Recursion//
}

int severity(int b) {		//The purpose of this function is to allow the user to enter a value for severity, had problems before as taking two inputs next to each other causes issues//
	printf("Please, enter the severity of the illness.\n");
	scanf("%d", &b);		//Gets the user input//
	return b;		//Returns the integer value the user entered//
}

int main(void) {		//Main function that runs the program//
	//Setting variables//
	int True = 1;
	char m[10], n[100], clear[10] = "";
	int b;
	listTuples();		//List the tuples right away just to make sure it's empty//
	while (True == 1) {		//Effectively, saying while the program is running//
		int q = 0, w = 0;		//Needed to set these here as they need to be reset after completing a sort//
		printf("Please, enter what action you would like to perform. Either a for add, r for remove or v for view.\n");		//Main prompt//
		scanf("%s[\n]", m);		//Asks the user for input//
		getchar();		//Gets the input as a char//
		if (strcmp(m, "a") == 0) {		//If the user entered a then//
			if (tupleCount == 10) {		//If the maximum amount of tuples are in use then//
				printf("There are too many tuples in play. You may only view or remove tuples at this time.");		//Tell the use they can't add anymore tuples//
			}
			else {
				printf("Please enter the name of the patient.\n");
				scanf("%s", n);		//Gets the user to enter the patient name//
				getchar();
				b = severity(b);		//Get the severity and save it in b//
				addTuple(n, b);		//Use the gathered information to add the information to the next avalible tuple set//
			}
		}
		else if (strcmp(m, "r") == 0) {		//If the user entered r then//
			printf("Please, enter the name of the patient to be removed from the list.\n");
			scanf("%s", n);		//Get the name of the patient to be removed//
			getchar();
			printf("Removing %s from the list.\n", n);
			deleteTuple(n);		//Removes the tuple relating to that patient from the tuple list//
		}
		else {		//If the user entered anything else then//
			printf("Showing patients:\n");
			listTuples();		//Show all current tuples//
		}
		strcpy(m, clear);		//Clear the user input in preparation for them doing something different next time//
		tupleSort(q, w);		//Sort the tuples that are currently in play based on severity//
		printf("\n\n");		//Spacing//

 	}

	return 0;		//Quit//
}

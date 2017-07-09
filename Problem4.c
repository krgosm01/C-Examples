/*******************
* Kaden R Gosman   * 
* CECS-130-02	   *
* Assignment 05-04 *
*******************/

#include <stdio.h>
#include <time.h>

//Lines 24-42 were not needed for assignment I was bored and wanted to practice 

int tossDice();

int main()
{
	srand(time(NULL));						//Seeds a random number **ONLY NEEDS TO BE SEEDED ONCE IN MAIN**
	
	int numOfDice, array[6], retry;

	printf("\tWelcome to my dice rolling program.\n");
	printf("Please enter the amount of dice you would like to roll:");
	scanf("%d", &numOfDice);

	if (numOfDice > 6)					//If else statement to make it so user can not roll more than 6 dice. 
	{
			printf("Please enter a number between 1 and 6.\n");
			printf("Would you like to retry?\n");
			printf("1. Retry\n");		//Menu for switch case
			printf("2. Exit\n");
			printf("Enter your selection: ");
			scanf("%d", &retry);
			
			switch(retry)				//Switch case to see if user wants to retry
			{
				case 1:
					main();
					break;
				case 2:
					break;
			}
	}
	else
		tossDice(array, numOfDice);  	//Calls the tossDice function established on like 46 
										//and paces the array and users numbers through the function		
}

int tossDice(int *dice, int amount)		//Passes the tossDice function an array and an amount (in this case amount of dice)
{
	int die, i;      
	
	for (i = 0; i < amount; i++)
	{      	
		die = (rand() % 6) + 1;			//Randomizes each dice inside a for loop 
		dice[i] = die;					//**EACH NUMBER WILL BE RANDOMLY GENERATED SEPERATELY OF LINE 18
		 								//Stores each dice in an array labled dice
	}
	
	printf("Your %d rolls were as follows.\n", amount);
	for (i = 0; i < amount; i++)
		printf("Roll %d was: %d \n", i+1, dice[i]);			//Prints the random rolls from the array
	printf("Thank you for playing.");
}

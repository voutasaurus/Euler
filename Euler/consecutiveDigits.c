#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>


void isdigitTest (int length)
{

	int a;

	/* Set the maximum random integer required */
	 int max = 80; 
		/* (rand() % max) now ranges from 1..max */

	 /* Seed for random values set using the OS time, time() needs argument */
	 srand(time(NULL)); 

	for (int i = 1; i <= length; i++)
	{
		a = rand() % max;
		if (isdigit(a))
			printf("%c is a digit \n", a);
		else
			printf("%c is NOT a digit \n", a);

	}
}

struct tempFive
{
	char temp[5];
	int next;
};

struct tempFive updateTemp (struct tempFive store, int newDigit)
{
	if (isdigit(newDigit))
	{
		store.temp[store.next] = newDigit;
//		printf("Stored %c in position %i \n", newDigit, store.next);

		store.next++;
		store.next %= 5;

		return store;
		//printf(" G ");
	}
	else
	{
		//printf(" E ");
		return store;
	}
}

int productTemp (struct tempFive store)
{
	int product = 1;
	for (int i = 0; i < 5; i++)
	{
		product *= store.temp[i] - '0';
	} 

	return product;
}

// Euler problem 8
int greatestProductConsecutiveDigits(char *digitString)
{
	struct tempFive tempStore;
	for (int i = 0; i < 5; i++)
		tempStore.temp[i] = '0';
	tempStore.next = 0;

	int product = 1;
	int largest = 0;

	// read five digits from digitString
	//   and calculate product

	while (*digitString != 'a') // more digits to test
	{

		tempStore = updateTemp(tempStore, *digitString);
		digitString++;

		product = productTemp(tempStore);

		if (product > largest)
		{
			largest = product;
			// printf("\n largest is now %i \n", largest);
		}
	}

	return largest;

}

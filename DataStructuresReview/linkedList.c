#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <string.h>
//#include <stddef.h>
//#include <ctype.h>
//#include <time.h>

struct linkedListEntry *newLL(void);
struct linkedListEntry *newLLwithvalue(int value);
struct linkedListEntry *consLL (struct linkedListEntry *front, int valueToInsert);
struct linkedListEntry *insertLL (struct linkedListEntry *front, int valueToInsert);
void printLL (struct linkedListEntry *front);

// Data Structure for Linked List
struct linkedListEntry
{
	int value;	// The value stored in this entry in the list
	struct linkedListEntry *next;	// pointer to the next entry of the list
};


// Function to create an empty list
struct linkedListEntry *newLL (void)
{
	return ((struct linkedListEntry *) 0);
}

// Function to make a new linked list given a single value
// The user should do
/* 
	struct linkedListEntry *listptr;
	listptr = newLL();
	listptr = &(consLL(listptr, value));

*/
struct linkedListEntry *newLLwithvalue (int val)
{
	struct linkedListEntry *listptr;
	listptr = newLL();
	listptr = consLL(listptr, val);

	return listptr;
}

// Function to add a value to the front of a list 
struct linkedListEntry *consLL (struct linkedListEntry *front, int valueToInsert)
{

	struct linkedListEntry newEntry; // The entry we want to insert (allocates memory)
	struct linkedListEntry *newFront = &newEntry; // Pointer to the entry

	newFront->value = valueToInsert; // The value of the entry from input
	newFront->next = front; // This new entry points to the old front of the list

	return newFront; // Return the new front of the list
	// Note that when this function is called, it should be newlist = &(consLL(listptr, val));
	// to get the address of the new list

}

// Function to insert a value into a sorted linked list
struct linkedListEntry *insertLL (struct linkedListEntry *front, int valueToInsert)
{

	struct linkedListEntry newEntrySpace;	// The entry we want to insert (allocates memory)
	struct linkedListEntry *newEntry = &newEntrySpace; // Pointer to the new entry
	newEntry->value = valueToInsert; // The value of that entry from input

	struct linkedListEntry *current = front; // To cycle through the list
	struct linkedListEntry *previous = (struct linkedListEntry *) 0; // follows behind current

	bool oldfront = true; // The front of the list will probably remain the same

	// Cycle to the first value greater than the insertion value
	// Linear (With an array binary search would be faster, but this is a list)
	while (newEntry->value >= current->value && current != (struct linkedListEntry *) 0)
	{
		// Keep track of the last entry we looked at
		// It will need to point to the inserted entry
		previous = current; 
		// Go to the next entry because the current entry is still <= the insertion value
		current = current->next;
	}

	// If there is a value in the list <= the insertion value
	if (previous != (struct linkedListEntry *) 0)
		previous->next = newEntry; // Make the highest one point to the new entry
	else
		oldfront = false; // The newEntry is now the front of the list	

	// Make the new entry point to the next largest entry
	// If the list was empty before, then current = front, and so pointing to NULL is correct
	newEntry->next = current;

	if (oldfront)
		return front; // Return the original front of the list (the new entry is internal)
	else	
		return newEntry; // Return the new front of the list

	// Note that when this function is called, it should be newlist = &(insertLL(listptr, val));
	// to get the new address of the new list

}

// Function to print the contents of a list
void printLL (struct linkedListEntry *front)
{
	struct linkedListEntry *current = front;

	while (current != (struct linkedListEntry *) 0)
	{
		printf("%i \n", current->value);
		current = current->next;
	}
}

// Function to test Linked Lists
void testLL (void)
{
	int i = 0;

	// NONSORTED

	// Initialise
	struct linkedListEntry *listptr = newLL();
	struct linkedListEntry *listptra;
	struct linkedListEntry *listptrb;

	printLL(listptr);

	printf("BREAK \n");

	// Add Data
	listptr = consLL(listptr, 1);
	listptr = consLL(listptr, 2);
//	for (i = 0; i <= 10; i++)
//		listptr = consLL(listptr, 10 - i);

	// Print
	printf("listptr: ");
	printLL(listptr);
//	printf("\n listptr: ");
//	printLL(listptra);
//	printf("\n listptrb: ");
//	printLL(listptrb);

	printf("BREAK \n");

	struct linkedListEntry n1, n2, n3;
	struct linkedListEntry *list_pointer = &n1;

	n1.value = 100;
	n1.next = &n2;
	n2.value = 200;
	n2.next = &n3;
	n3.value = 300;
	n3.next = (struct linkedListEntry *) 0; // end of the list - null pointer

	printLL(list_pointer);

	// Add More Data
//	for (i = 0; i <= 10; i++)
//		listptr = consLL(listptr, i);

	// Print again
//	printLL(listptr);

	// Remove Data (not implemented)
	// Print

	// SORTED
	// Initialise
	// Add Data
	// Print

	// Remove Data (not implemented)
	// Print

}

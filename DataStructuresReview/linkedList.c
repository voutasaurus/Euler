#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <string.h>
//#include <stddef.h>
//#include <ctype.h>
//#include <time.h>

struct linkedListEntry *newLL(void);
struct linkedListEntry *newLLwithvalue(int value);
struct linkedListEntry *consLL (struct linkedListEntry *front, struct linkedListEntry *newEntry, int valueToInsert);
struct linkedListEntry *insertLL (struct linkedListEntry *front, struct linkedListEntry *newEntry, int valueToInsert);
void printLL (struct linkedListEntry *front);

// Data Structure for Linked List
struct linkedListEntry
{
	int value;	// The value stored in this entry in the list
	struct linkedListEntry *next;	// pointer to the next entry of the list
};


// Function to create an empty list
// What does this do since the memory allocated for this struct is
// deallocated when this function returns?
// It's supposed to be a null pointer, and it seems to work anyway
// probably best to check this somehow
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

// THIS is difficult because the memory has to be allocated at the level it is being used
// The list pointer and the new entry pointer both have to be passed, and by that time
// you may as well do it the other way
// Repeat - Memory allocated within a function is fair game for the rest of the system when the function returns
struct linkedListEntry *newLLwithvalue (struct linkedListEntry *space_ptr, int val)
{
	space_ptr = newLL();
	space_ptr = consLL(space_ptr, , val);

	return listptr;
}
*/

// Function to add a value to the front of a list 
struct linkedListEntry *consLL (struct linkedListEntry *front, struct linkedListEntry *newEntry, int valueToInsert)
{
	newEntry->value = valueToInsert; // The value of the entry from input
	newEntry->next = front; // This new entry points to the old front of the list

	return newEntry; // Return the new front of the list
	// Note that when this function is called, it should be newlist = &(consLL(listptr, val));
	// to get the address of the new list
}

// Function to insert a value into a sorted linked list
struct linkedListEntry *insertLL (struct linkedListEntry *front, struct linkedListEntry *newEntry, int valueToInsert)
{
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

	// Test 1: manual list construction
	struct linkedListEntry n1, n2, n3;
	struct linkedListEntry *list_pointer_manual = &n1;

	n1.value = 100;
	n1.next = &n2;
	n2.value = 200;
	n2.next = &n3;
	n3.value = 300;
	n3.next = (struct linkedListEntry *) 0; // end of the list - null pointer

	printf("Manual list print: \n");
	printf("==================== \n");
	printf("Expected: \n");
	printf("==================== \n");
	printf("100 \n");
	printf("200 \n");
	printf("300 \n");
	printf("==================== \n");
	printf("Actual: \n");
	printf("==================== \n");
	printLL(list_pointer_manual);
	printf("==================== \n");

	// null test
	struct linkedListEntry *list_pointer_nullTest = (struct linkedListEntry *) 0;

	printf("Null list print (Manual version): \n");
	printf("==================== \n");
	printf("Expected: \n");
	printf("==================== \n");
	printf("==================== \n");
	printf("Actual: \n");
	printf("==================== \n");
	printLL(list_pointer_nullTest);
	printf("==================== \n");

	// Test 2: newLL()

	struct linkedListEntry *list_pointer_newLL = newLL();

	printf("Null list print (newLL version): \n");
	printf("==================== \n");
	printf("Expected: \n");
	printf("==================== \n");
	printf("==================== \n");
	printf("Actual: \n");
	printf("==================== \n");
	printLL(list_pointer_newLL);
	printf("==================== \n");


	// Test 3: consLL()

	struct linkedListEntry *list_pointer_consLL = newLL();
	
	// Add to new list
	// Must allocate space for the new entry at the level that the list is being used
	// Otherwise the memory will be collected and everything will be stuffed
	struct linkedListEntry newEntrySpace; 
	struct linkedListEntry *newEntry = &newEntrySpace;

	list_pointer_consLL = consLL(list_pointer_consLL, newEntry, 2);

	printf("Cons list print (consLL): \n");
	printf("==================== \n");
	printf("Expected: \n");
	printf("==================== \n");
	printf("2 \n");
	printf("==================== \n");
	printf("Actual: \n");
	printf("==================== \n");
	printLL(list_pointer_consLL);
	printf("==================== \n");

	struct linkedListEntry *list_pointer_consLL_mult = newLL();

	struct linkedListEntry newEntrySpaces[10]; 
	struct linkedListEntry *newEntrySpot = &(newEntrySpaces[0]);

	list_pointer_consLL_mult = consLL(list_pointer_consLL_mult, newEntrySpot, 0);
	
	for (i = 1; i < 10; i++)
	{
		newEntrySpot = &(newEntrySpaces[i]);
		list_pointer_consLL_mult = consLL(list_pointer_consLL_mult, newEntrySpot, i);
	}

	printf("Cons mult list print (consLL): \n");
	printf("==================== \n");
	printf("Expected: \n");
	printf("==================== \n");
	printf("9 \n");
	printf("8 \n");
	printf("7 \n");
	printf("6 \n");
	printf("5 \n");
	printf("4 \n");
	printf("3 \n");
	printf("2 \n");
	printf("1 \n");
	printf("0 \n");
	printf("==================== \n");
	printf("Actual: \n");
	printf("==================== \n");
	printLL(list_pointer_consLL_mult);
	printf("==================== \n");

	
	// Test 4: insertLL

	struct linkedListEntry *list_pointer_insertLL = newLL();


	// Remove Data (not implemented)
	// Print

	// SORTED
	// Initialise
	// Add Data
	// Print

	// Remove Data (not implemented)
	// Print

}

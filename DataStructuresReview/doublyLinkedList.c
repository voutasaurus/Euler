#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
//#include <string.h>
//#include <stddef.h>
//#include <ctype.h>
//#include <time.h>

struct doublyLinkedListEntry 
{
	int value;
	struct doublyLinkedListEntry *next;
	struct doublyLinkedListEntry *prev;
};

struct doublyLinkedListEntry insertDLL (struct doublyLinkedListEntry front, int valueToInsert)
{

	struct doublyLinkedListEntry newEntry;

	newEntry.value = valueToInsert;
	newEntry.next = &front;
	newEntry.prev = (struct doublyLinkedListEntry *) 0;
	front.prev = &newEntry;

	return newEntry;

}

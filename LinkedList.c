#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Node.h"

void m_Add(struct LinkedList *theList) {
	int bIsNum = 1;
	char *sTheInput = malloc(sizeof(char*)*20);

	printf("\n\nEnter the value\n>>>");

	gets(sTheInput);

	int inputLength = 0;
	while (inputLength < 20 && sTheInput[inputLength] != '\0') inputLength++;
	if (inputLength == 20) sTheInput[inputLength - 1] = '\0';

	for (int i = 0; sTheInput[i] != '\0'; i++) {
		if (!isdigit(sTheInput[i])) {
			bIsNum = 0;
			break;
		}
	}

	if (bIsNum) {
		struct NodeInt *theCurrentNode = malloc(sizeof(*theCurrentNode));
		theCurrentNode->pTheNextNode = (struct NodeInt*)0;

		if (!(*theList).iListSize) {
			(*theList).pTheHeadNode = theCurrentNode;
		}
		else {
			struct NodeInt *tempNodePointer = (*theList).pTheHeadNode;

			while (1) {
				if (tempNodePointer->pTheNextNode == (struct NodeInt*)0) {
					tempNodePointer->pTheNextNode = theCurrentNode;
					break;
				}
				tempNodePointer = tempNodePointer->pTheNextNode;
			}
		}

		(*theList).iListSize++;
		theCurrentNode->indicator = 1;
		theCurrentNode->iTheValue = atoi(sTheInput);
	}
	else {
		struct NodeString* theCurrentNode = malloc(sizeof(*theCurrentNode));
		theCurrentNode->pTheNextNode = (struct NodeInt*)0;

		if (!(*theList).iListSize) {
			(*theList).pTheHeadNode = (struct NodeInt*)theCurrentNode;
		}
		else {
			struct NodeInt* tempNodePointer = (*theList).pTheHeadNode;

			while (1) {
				if (tempNodePointer->pTheNextNode == (struct NodeInt*)0) {
					tempNodePointer->pTheNextNode = (struct NodeInt*)theCurrentNode;
					break;
				}
				tempNodePointer = tempNodePointer->pTheNextNode;
			}
		}

		(*theList).iListSize++;
		theCurrentNode->indicator = 2;
		theCurrentNode->sTheValue = sTheInput;
	}

	printf("\n\n");
}

void m_Display(struct LinkedList *theList) {
	printf("\n---\n");

	if (theList->iListSize == 0)
		printf("--The list is empty--\n");
	else {
		struct NodeInt* tempNodePointer = (*theList).pTheHeadNode;

		while (tempNodePointer != (struct NodeInt*)0) {
			if (tempNodePointer->indicator == 1)
				printf("%d\n", tempNodePointer->iTheValue);
			else
				printf("%s\n", (char*)(tempNodePointer->iTheValue));

			tempNodePointer = tempNodePointer->pTheNextNode;
		}
	}

	printf("---\n\n");
}

void m_Remove(struct LinkedList *theList) {
	if (theList->iListSize == 0);
	else {
		struct NodeInt* tempNodePointer = (*theList).pTheHeadNode;
		struct NodeInt* prevtempNodePointer = (struct NodeInt*)theList;

		while (1) {
			if (tempNodePointer->pTheNextNode == (struct NodeInt*)0) {
				if (tempNodePointer->indicator == 1)
					free(tempNodePointer);
				else
					free((struct NodeString*)tempNodePointer);
				prevtempNodePointer->pTheNextNode = (struct NodeInt*)0;
				break;
			}

			prevtempNodePointer = tempNodePointer;
			tempNodePointer = tempNodePointer->pTheNextNode;
		}

		theList->iListSize--;
	}

	printf("\n\n");
}

void m_Size(struct LinkedList* theList) {
	printf("\n---\nThe size of list is %d\n---\n\n", theList->iListSize);
}

void m_AddAtIndex(struct LinkedList* theList) {
	int bIsNum = 1;
	char* sTheInput = malloc(sizeof(char*) * 20);
	int indexToAdd;

	printf("\nEnter the index: ");
	scanf_s("%d", &indexToAdd);

	scanf_s("%*c");

	printf("\nEnter the Value\n>>>");
	
	gets(sTheInput);

	int inputLength = 0;
	while (inputLength < 20 && sTheInput[inputLength] != '\0') inputLength++;
	if (inputLength == 20) sTheInput[inputLength - 1] = '\0';

	for (int i = 0; sTheInput[i] != '\0'; i++) {
		if (!isdigit(sTheInput[i])) {
			bIsNum = 0;
			break;
		}
	}

	if (!(indexToAdd >= 1 && indexToAdd <= theList->iListSize))
		printf("\nEnter the corrent index please\n\n");
	else {
		struct NodeInt* theCurrentNode;

		if (bIsNum) {
			theCurrentNode = malloc(sizeof(struct NodeInt));
			theCurrentNode->iTheValue = atoi(sTheInput);
			theCurrentNode->indicator = 1;
		}
		else {
			theCurrentNode = malloc(sizeof(struct NodeString));
			theCurrentNode->iTheValue = sTheInput;
			theCurrentNode->indicator = 2;
		}

		struct NodeInt* prevtempNodePointer = (struct NodeInt*)theList;
		struct NodeInt* tempNodePointer = theList->pTheHeadNode;

		int counter = 1;

		while (counter < indexToAdd) {
			prevtempNodePointer = tempNodePointer;
			tempNodePointer = tempNodePointer->pTheNextNode;
			counter++;
		}

		prevtempNodePointer->pTheNextNode = theCurrentNode;
		theCurrentNode->pTheNextNode = tempNodePointer;
		theList->iListSize++;
	}
}

void m_RemoveAtIndex(struct LinkedList* theList){
	int indexToRemove;

	printf("\nEnter the index: ");
	scanf_s("%d", &indexToRemove);

	if (!(indexToRemove >= 1 && indexToRemove <= theList->iListSize))
		printf("\nEnter the corrent index please\n\n");
	else {
		struct NodeInt* tempNodePointer = theList->pTheHeadNode;
		struct NodeInt* prevtempNodePointer = (struct NodeInt*)theList;

		int counter = 1;

		while (counter < indexToRemove) {
			prevtempNodePointer = tempNodePointer;
			tempNodePointer = tempNodePointer->pTheNextNode;
			counter++;
		}

		prevtempNodePointer->pTheNextNode = tempNodePointer->pTheNextNode;
		free(tempNodePointer);
		theList->iListSize--;
	}
}
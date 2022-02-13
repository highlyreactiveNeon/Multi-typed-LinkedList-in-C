#include <stdio.h>

#include "LinkedList.h"
#include "Node.h"

int main() {

	int iUserChoice;
	int bIsExited = 0;

	struct LinkedList theList = {0, (struct NodeInt*)0};

	printf("The Linked List!\n\n");

	while (!bIsExited) {
	
		printf("1.Add\n2.Remove\n3.Add at Index\n4.Remove at Index\n5.Display\n6.Size\n7.Exit\n>>>");

		scanf_s("%d", &iUserChoice);
		scanf_s("%*c");

		switch (iUserChoice) {
		case 1:
			m_Add(&theList);
			break;
		case 2:
			m_Remove(&theList);
			break;
		case 3:
			m_AddAtIndex(&theList);
			break;
		case 4:
			m_RemoveAtIndex(&theList);
			break;
		case 5:
			m_Display(&theList);
			break;
		case 6:
			m_Size(&theList);
			break;
		case 7:
			return 0;
		default:
			printf("\n---\nPlease enter a correct choice\n---\n\n");
		}
	}

	return 0;
}
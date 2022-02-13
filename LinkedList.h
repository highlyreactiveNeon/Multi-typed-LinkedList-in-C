#pragma once

#include "Node.h"

struct LinkedList {
	struct NodeInt* pTheHeadNode;
	int iListSize;
};

void m_Add(struct LinkedList*);
void m_Display(struct LinkedList*);
void m_Remove(struct LinkedList*);
void m_Size(struct LinkedList*);
void m_AddAtIndex(struct LinkedList*);
void m_RemoveAtIndex(struct LinkedList*);

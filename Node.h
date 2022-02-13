#pragma once

struct NodeInt {
	struct NodeInt* pTheNextNode;
	char indicator;
	int iTheValue;
};

struct NodeString {
	struct NodeInt* pTheNextNode;
	char indicator;
	char* sTheValue;
};
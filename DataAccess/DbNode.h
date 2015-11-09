#pragma once
#include "Entry.h"

class DbNode
{
public:
	DbNode();
	DbNode(ENTRY* lpData);
	DbNode* lpLeftChild;
	DbNode* lpRightChild;
	~DbNode();
	ENTRY* lpData;
};


#pragma once
#include "DbNode.h"
#include "Entry.h"
#include "StringComparer.h"

class BinaryTreeSeeker
{
public:
	static BOOL Seek(DbNode* root, ENTRY* entry, std::string lastName);
	~BinaryTreeSeeker();
private:
	BinaryTreeSeeker();
};


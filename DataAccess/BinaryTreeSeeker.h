#pragma once
#include "DbNode.h"
#include "Entry.h"
#include "StringComparer.h"
#include <vector>

class BinaryTreeSeeker
{
public:
	static BOOL Seek(DbNode* root, std::vector<ENTRY>* entries, COMPAREFUNC compareFunc);
	~BinaryTreeSeeker();
private:
	BinaryTreeSeeker();
	static std::string getId(ENTRY*);
};


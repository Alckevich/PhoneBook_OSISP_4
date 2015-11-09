#pragma once
#include "Entry.h"
#include "DbNode.h"
#include "StringComparer.h"
#include <vector>

class DbBinTreeBuilder
{
public:
	DbBinTreeBuilder(std::vector<ENTRY>* entries);
	void Build(DbNode** root);
	~DbBinTreeBuilder();
private:
	std::vector<ENTRY>* entries;
	void insert(DbNode** root, ENTRY* entry);
};


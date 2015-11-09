#pragma once
#include <vector>
#include "Entry.h"
#include "PhoneBookTxtParser.h"
#include "DbBinTreeBuilder.h"
#include "BinaryTreeSeeker.h"

class PhoneBookDataBase
{
public:
	static void Initialize(const char*);
	static void FindByPhone(std::string name, std::vector<ENTRY>* entries);
	static void FindByStreet(std::string street, std::vector<ENTRY>* entries);
	static void FindByLastName(std::string lastName, std::vector<ENTRY>* entries);
	static void Get(std::vector<ENTRY>* entries);
	~PhoneBookDataBase();
private:
	PhoneBookDataBase(const char* fileName);
	std::vector<ENTRY> dbEntries;
	static PhoneBookDataBase* instance;
	PhoneBookTxtParser* parser;
	DbNode* root;
};


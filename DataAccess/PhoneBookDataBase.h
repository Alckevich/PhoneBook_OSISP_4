#pragma once
#include <vector>
#include "Entry.h"
#include "PhoneBookTxtParser.h"
#include "DbBinTreeBuilder.h"
#include "BinaryTreeSeeker.h"

class __declspec(dllexport) PhoneBookDataBase
{
public:
	static void Initialize(const char*);
	static void FindByLastName(std::string name, std::vector<ENTRY>* entries);
	static void FindPhone(std::string phone, std::vector<ENTRY>* entries);
	static void FindByAddress(std::string address, std::vector<ENTRY>* entries);
	static void Get(std::vector<ENTRY>* entries);
	~PhoneBookDataBase();
private:
	PhoneBookDataBase(const char* fileName);
	std::vector<ENTRY> dbEntries;
	static PhoneBookDataBase* instance;
	PhoneBookTxtParser* parser;
	DbNode* lastNameRoot;
	DbNode* phoneRoot;
	DbNode* addressRoot;
};


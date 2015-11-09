#include "stdafx.h"
#include "PhoneBookDataBase.h"
#include "StringComparer.h"


PhoneBookDataBase* PhoneBookDataBase::instance = 0;

PhoneBookDataBase::PhoneBookDataBase(const char* fileName)
{
	parser = new PhoneBookTxtParser(fileName);
	parser->Parse(&dbEntries);

	DbBinTreeBuilder treeBuilder(&dbEntries);
	treeBuilder.Build(&root);
}

void PhoneBookDataBase::Initialize(const char* fileName)
{
	if (instance == NULL){
		instance = new PhoneBookDataBase(fileName);
	}
}

void PhoneBookDataBase::FindByPhone(std::string name, std::vector<ENTRY>* entries){
	entries->clear();
	for (int i = 0; i < instance->dbEntries.size(); i++){
		if (StringComparer::iequal(instance->dbEntries[i].name, name)){
			entries->push_back(instance->dbEntries[i]);
		}
	}
}

void PhoneBookDataBase::FindByStreet(std::string street, std::vector<ENTRY>* entries){
	entries->clear();
	for (int i = 0; i < instance->dbEntries.size(); i++){
		if (StringComparer::iequal(instance->dbEntries[i].street, street)){
			entries->push_back(instance->dbEntries[i]);
		}
	}
}

void PhoneBookDataBase::FindByLastName(std::string lastName, std::vector<ENTRY>* entries){
	entries->clear();
	ENTRY entry;
	BinaryTreeSeeker::Seek(instance->root, &entry, lastName);
	entries->push_back(entry);
}

void PhoneBookDataBase::Get(std::vector<ENTRY>* entries){
	(*entries) = std::vector<ENTRY>(instance->dbEntries);
}

PhoneBookDataBase::~PhoneBookDataBase()
{
}

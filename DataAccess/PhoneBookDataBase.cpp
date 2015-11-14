#include "stdafx.h"
#include "PhoneBookDataBase.h"
#include "StringComparer.h"


PhoneBookDataBase* PhoneBookDataBase::instance = 0;

PhoneBookDataBase::PhoneBookDataBase(const char* fileName)
{
	parser = new PhoneBookTxtParser(fileName);
	parser->Parse(&dbEntries);

	DbBinTreeBuilder lastNameTreeBuilder(&dbEntries, [](ENTRY* a, ENTRY* b){ return StringComparer::icompare(a->lastname, b->lastname) >= 0; });
	lastNameTreeBuilder.Build(&lastNameRoot);

	DbBinTreeBuilder phoneTreeBuilder(&dbEntries, [](ENTRY* a, ENTRY* b){ return StringComparer::icompare(a->phone, b->phone) >= 0; });
	phoneTreeBuilder.Build(&phoneRoot);

	DbBinTreeBuilder addressTreeBuilder(&dbEntries, [](ENTRY* a, ENTRY* b){ return StringComparer::icompare(a->street, b->street) >= 0; });
	addressTreeBuilder.Build(&addressRoot);
}

void PhoneBookDataBase::Initialize(const char* fileName)
{
	if (instance == NULL){
		instance = new PhoneBookDataBase(fileName);
	}
}

void PhoneBookDataBase::FindByLastName(std::string lastName, std::vector<ENTRY>* entries){
	entries->clear();
	BinaryTreeSeeker::Seek(instance->lastNameRoot, entries, [=](ENTRY* a){ return StringComparer::icompare(lastName, a->lastname); });
}

void PhoneBookDataBase::FindPhone(std::string phone, std::vector<ENTRY>* entries){
	entries->clear();
	BinaryTreeSeeker::Seek(instance->phoneRoot, entries, [=](ENTRY* a){ return StringComparer::icompare(phone, a->phone); });
}

void PhoneBookDataBase::FindByAddress(std::string address, std::vector<ENTRY>* entries){
	entries->clear();
	BinaryTreeSeeker::Seek(instance->addressRoot, entries, [=](ENTRY* a){ return StringComparer::icompare(address, a->street); });
}

void PhoneBookDataBase::Get(std::vector<ENTRY>* entries){
	(*entries) = std::vector<ENTRY>(instance->dbEntries);
}

PhoneBookDataBase::~PhoneBookDataBase()
{
}

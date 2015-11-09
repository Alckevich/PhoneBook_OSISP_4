#pragma once
#include "PhoneBookDataBase.h"
#include "Entry.h"

class PhoneBookRepository
{
public:
	BOOL FindByPhone(std::string name, std::vector<ENTRY>* entries);
	BOOL FindByStreet(std::string street, std::vector<ENTRY>* entries);
	BOOL FindByLastName(std::string lastName, std::vector<ENTRY>* entries);
	BOOL Get(std::vector<ENTRY>* entries);
	PhoneBookRepository();
	~PhoneBookRepository();
private:
};


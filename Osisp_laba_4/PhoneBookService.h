#pragma once
#include "Entry.h"
#include "PhoneBookRepository.h"
#include "VectorExtensions.h"
#include <vector>

class PhoneBookService
{
public:
	PhoneBookService();
	BOOL GetByLastName(std::string lastName, std::vector<ENTRY>* entries);
	BOOL GetByPhone(std::string phone, std::vector<ENTRY>* entries);
	BOOL GetByAddress(std::string address, std::vector<ENTRY>* entries);
	BOOL GetEntries(std::string lastName, std::string phone, std::string address, std::vector<ENTRY>* entries);
	BOOL GetAllEntries(std::vector<ENTRY>* entries);
	~PhoneBookService();
private:
	PhoneBookRepository repository;
	PREDICATE entriesEqualityPredicate;
};


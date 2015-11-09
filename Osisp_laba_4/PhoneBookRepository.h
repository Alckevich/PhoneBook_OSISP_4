#pragma once
#include "Entry.h"
#include <vector>

typedef void(*INITFUNC)(const char*);
typedef void(*SEEKFUNC)(std::string, std::vector<ENTRY>*);
typedef void(*GETFUNC)(std::vector<ENTRY>*);

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
	HMODULE hDbLib;
	INITFUNC DbInit;
	SEEKFUNC DbFindByLastName;
	GETFUNC DbGet;
};


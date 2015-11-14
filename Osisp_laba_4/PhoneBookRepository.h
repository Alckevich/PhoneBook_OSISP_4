#pragma once
#include "Entry.h"
#include <vector>

typedef void(*INITFUNC)(const char*);
typedef void(*SEEKFUNC)(std::string, std::vector<ENTRY>*);
typedef void(*GETFUNC)(std::vector<ENTRY>*);

class PhoneBookRepository
{
public:
	BOOL FindByLastName(std::string lastName, std::vector<ENTRY>* entries);
	BOOL FindByPhone(std::string phone, std::vector<ENTRY>* entries);
	BOOL FindByAddress(std::string address, std::vector<ENTRY>* entries);
	BOOL Get(std::vector<ENTRY>* entries);
	PhoneBookRepository();
	~PhoneBookRepository();
private:
	HMODULE hDbLib;
	INITFUNC DbInit;
	SEEKFUNC DbFindByLastName;
	SEEKFUNC DbFindByPhone;
	SEEKFUNC DbFindByAddress;
	GETFUNC DbGet;
};


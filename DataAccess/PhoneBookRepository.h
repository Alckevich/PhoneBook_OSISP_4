#pragma once

#ifdef DATAACCESSDLL_EXPORTS
#define DATAACCESSDLL_API __declspec(dllexport) 
#else
#define DATAACCESSDLL_API __declspec(dllimport) 
#endif

#include "Entry.h"

class PhoneBookRepository
{
public:
	PhoneBookRepository();
	DATAACCESSDLL_API BOOL Get(ENTRY filter, ENTRY* lpEntry);
	~PhoneBookRepository();
private:
	Data
};


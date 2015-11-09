#include "stdafx.h"
#include "PhoneBookRepository.h"
#include <string>
#include <vector>

PhoneBookRepository::PhoneBookRepository()
{
	hDbLib = LoadLibrary(L"C:\\Users\\Alckevich\\Documents\\Visual Studio 2013\\Projects\\Osisp_laba_4\\Debug\\DataAccess.dll");
	if (hDbLib == NULL){
		throw std::exception("can't load dll");
	}
	
	DbInit = (INITFUNC)GetProcAddress(hDbLib, "?Initialize@PhoneBookDataBase@@SAXPBD@Z");
	DbFindByLastName = (SEEKFUNC)GetProcAddress(hDbLib, "?FindByLastName@PhoneBookDataBase@@SAXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV?$vector@UPHONEBOOK_ENTRY@@V?$allocator@UPHONEBOOK_ENTRY@@@std@@@3@@Z");
	DbGet = (GETFUNC)GetProcAddress(hDbLib, "?Get@PhoneBookDataBase@@SAXPAV?$vector@UPHONEBOOK_ENTRY@@V?$allocator@UPHONEBOOK_ENTRY@@@std@@@std@@@Z");

	DbInit("C:\\Users\\Alckevich\\Documents\\Visual Studio 2013\\Projects\\Osisp_laba_4\\phoneBook.txt");
}

BOOL PhoneBookRepository::Get(std::vector<ENTRY>* entries){
	DbGet(entries);
	return true;
}

BOOL PhoneBookRepository::FindByPhone(std::string name, std::vector<ENTRY>* entries){
	/*try{
		PhoneBookDataBase::FindByPhone(name, entries);
	}
	catch (std::exception e){
		return false;
	}
	*/
	return true;
}

BOOL PhoneBookRepository::FindByStreet(std::string street, std::vector<ENTRY>* entries){
	/*try{
		PhoneBookDataBase::FindByStreet(street, entries);
	}
	catch(std::exception e){
		return false;
	}
	*/
	return true;
}

BOOL PhoneBookRepository::FindByLastName(std::string lastName, std::vector<ENTRY>* entries){
	try{
		DbFindByLastName(lastName, entries);
	}
	catch (std::exception e){
		return false;
	}

	return true;
}

PhoneBookRepository::~PhoneBookRepository()
{
	FreeLibrary(hDbLib);
}

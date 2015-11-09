#include "stdafx.h"
#include "PhoneBookRepository.h"
#include <string>
#include <vector>

PhoneBookRepository::PhoneBookRepository()
{
	PhoneBookDataBase::Initialize("C:\\Users\\Alckevich\\Documents\\Visual Studio 2013\\Projects\\Osisp_laba_4\\phoneBook.txt");
}

BOOL PhoneBookRepository::Get(std::vector<ENTRY>* entries){
	PhoneBookDataBase::Get(entries);
	return true;
}

BOOL PhoneBookRepository::FindByPhone(std::string name, std::vector<ENTRY>* entries){
	try{
		PhoneBookDataBase::FindByPhone(name, entries);
	}
	catch (std::exception e){
		return false;
	}

	return true;
}

BOOL PhoneBookRepository::FindByStreet(std::string street, std::vector<ENTRY>* entries){
	try{
		PhoneBookDataBase::FindByStreet(street, entries);
	}
	catch(std::exception e){
		return false;
	}

	return true;
}

BOOL PhoneBookRepository::FindByLastName(std::string lastName, std::vector<ENTRY>* entries){
	try{
		PhoneBookDataBase::FindByLastName(lastName, entries);
	}
	catch (std::exception e){
		return false;
	}

	return true;
}

PhoneBookRepository::~PhoneBookRepository()
{
}

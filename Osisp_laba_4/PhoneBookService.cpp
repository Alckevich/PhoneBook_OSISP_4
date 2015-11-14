#include "stdafx.h"
#include "PhoneBookService.h"


PhoneBookService::PhoneBookService()
{
	entriesEqualityPredicate = [](ENTRY* a, ENTRY* b){ return a->lastname == b->lastname && a->street == b->street && a->phone == b->phone; };
}

BOOL PhoneBookService::GetByLastName(std::string lastName, std::vector<ENTRY>* entries){
	if (!lastName.empty()){
		return repository.FindByLastName(lastName, entries);
	}

	return false;
}

BOOL PhoneBookService::GetByPhone(std::string phone, std::vector<ENTRY>* entries){
	if (!phone.empty()){
		return repository.FindByPhone(phone, entries);
	}

	return false;
}

BOOL PhoneBookService::GetByAddress(std::string address, std::vector<ENTRY>* entries){
	if (!address.empty()){
		return repository.FindByAddress(address, entries);
	}

	return false;
}

BOOL PhoneBookService::GetEntries(std::string lastName, std::string phone, std::string address, std::vector<ENTRY>* entries){
	entries->clear();
	std::vector<ENTRY> foundedByLastNameEntries;
	std::vector<ENTRY> foundedByAddressEntries;
	std::vector<ENTRY> foundedByPhoneEntries;

	std::vector<std::vector<ENTRY>> vectors;
	if (this->GetByLastName(lastName, &foundedByLastNameEntries)){
		vectors.push_back(foundedByLastNameEntries);
	}
	
	if (this->GetByAddress(address, &foundedByAddressEntries)){
		vectors.push_back(foundedByAddressEntries);
	}

	if (this->GetByPhone(phone, &foundedByPhoneEntries)){
		vectors.push_back(foundedByPhoneEntries);
	}

	VectorExtensions::GetIntersectionOfMany<ENTRY>(vectors, entriesEqualityPredicate, entries);

	return true;
}

BOOL PhoneBookService::GetAllEntries(std::vector<ENTRY>* entries){
	return repository.Get(entries);
}

PhoneBookService::~PhoneBookService()
{
}

#pragma once
#include <string>
#include <functional>

typedef struct PHONEBOOK_ENTRY {
	std::string phone;
	std::string lastname;
	std::string name;
	std::string patronym;
	std::string street;
	std::string house;
	std::string housing;
	std::string apartment;
} ENTRY;

typedef std::function<bool(ENTRY*, ENTRY*)> PREDICATE;
typedef std::function<int(ENTRY*)> COMPAREFUNC;
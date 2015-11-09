#pragma once

#include <string>

#define PHONE_DB_MAX_LEN	30


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


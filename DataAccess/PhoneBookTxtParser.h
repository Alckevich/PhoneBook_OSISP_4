#pragma once

#include <vector>
#include "Entry.h"

class PhoneBookTxtParser
{
public:
	PhoneBookTxtParser(const char* file);
	BOOL Parse(std::vector<ENTRY>* entries);
	~PhoneBookTxtParser();
private:
	BOOL ParseDocumentWithEntries();
	BOOL ParseEntry(std::string line);
	BOOL ParseEntryFields(std::string line, std::vector<std::string>* fields);
	BOOL FillEntry(std::vector<std::string> fields, ENTRY* entry);

	std::vector<ENTRY> entries;
	const char* file;
};


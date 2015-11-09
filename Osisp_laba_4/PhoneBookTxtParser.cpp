#include "stdafx.h"
#include "PhoneBookTxtParser.h"
#include <fstream>
#include <sstream>
#include <string>


PhoneBookTxtParser::PhoneBookTxtParser(const char* file)
{
	this->file = file;
}

BOOL PhoneBookTxtParser::Parse(std::vector<ENTRY>* entries){
	
	if (this->ParseDocumentWithEntries()){
		*entries = std::vector<ENTRY>(this->entries);
		return true;
	}

	return false;
}

BOOL PhoneBookTxtParser::ParseDocumentWithEntries(){
	std::ifstream fs(this->file);
	std::string line;
	while (std::getline(fs, line)){
		if (!ParseEntry(line)){
			return false;
		}
	}

	return true;
}

BOOL PhoneBookTxtParser::ParseEntry(std::string line){
	std::vector<std::string> fields;
	ParseEntryFields(line, &fields);

	ENTRY entry;
	if (FillEntry(fields, &entry)){
		entries.push_back(entry);
	}
	else{
		return false;
	}

	return true;
}

BOOL PhoneBookTxtParser::ParseEntryFields(std::string line, std::vector<std::string>* fields){
	std::string field;
	std::istringstream iss(line);
	while (std::getline(iss, field, ';')) {
		fields->push_back(field);
	}

	return true;
}

BOOL PhoneBookTxtParser::FillEntry(std::vector<std::string> fields, ENTRY* entry){
	try{
		entry->phone = fields[0];
		entry->name = fields[1];
		entry->lastname = fields[2];
		entry->patronym = fields[3];
		entry->street = fields[4];
		entry->house = fields[5];
		entry->housing = fields[6];
		entry->apartment = fields[7];

		return true;
	}
	catch (std::exception e){
		return false;
	}
}

PhoneBookTxtParser::~PhoneBookTxtParser()
{
}

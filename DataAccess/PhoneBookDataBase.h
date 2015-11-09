#pragma once
#include <fstream>

class PhoneBookDataBase
{
public:
	static BOOL Initialize(const char* fileName);
	PhoneBookDataBase();
	~PhoneBookDataBase();
private:
	static std::ifstream memory;
};


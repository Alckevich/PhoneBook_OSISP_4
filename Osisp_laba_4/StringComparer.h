#pragma once
#include <string>

class StringComparer
{
public:
	static BOOL iequal(std::string a, std::string b);
	static int icompare(std::string a, std::string b);
	StringComparer();
	~StringComparer();
private:
	static int icompare_pred(unsigned char a, unsigned char b);
	static BOOL iequal_pred(unsigned char a, unsigned char b);
};


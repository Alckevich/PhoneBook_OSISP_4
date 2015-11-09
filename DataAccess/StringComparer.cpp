#include "stdafx.h"
#include "StringComparer.h"
#include <cctype>

StringComparer::StringComparer()
{
}

BOOL StringComparer::iequal(std::string a, std::string b){
	if (a.length() == b.length()) {
		return std::equal(b.begin(), b.end(),
			a.begin(), iequal_pred);
	}
	else {
		return false;
	}
}

BOOL StringComparer::iequal_pred(unsigned char a, unsigned char b)
{
	return std::tolower(a) == std::tolower(b);
}

int StringComparer::icompare(std::string a, std::string b){
	int length = 0;
	if (a.length() < b.length()){
		length = a.length();
	}
	else{
		length = b.length();
	}

	for (int i = 0; i < length; i++){
		if (icompare_pred(a[i], b[i]) == 1){
			return 1;
		}
		if (icompare_pred(a[i], b[i]) == -1){
			return -1;
		}
	}

	if (a.length() < b.length()){
		return -1;
	}
	else if (a.length() > b.length()){
		return 1;
	}

	return 0;
}

int StringComparer::icompare_pred(unsigned char a, unsigned char b)
{
	if (std::tolower(a) > std::tolower(b)){
		return 1;
	}

	if (std::tolower(a) < std::tolower(b)){
		return -1;
	}

	return 0;
}

StringComparer::~StringComparer()
{
}

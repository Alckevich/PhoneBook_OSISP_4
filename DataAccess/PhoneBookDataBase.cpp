#include "stdafx.h"
#include "PhoneBookDataBase.h"

std::ifstream memory;

PhoneBookDataBase::PhoneBookDataBase()
{
}

BOOL PhoneBookDataBase::Initialize(const char* fileName){
	memory = std::ifstream(fileName);
}

PhoneBookDataBase::~PhoneBookDataBase()
{
}

#pragma once

#include "stdafx.h"
#include "Entry.h"

class EntryComparer
{
public:
	EntryComparer();
	virtual BOOL compare(ENTRY* first, ENTRY* second) = 0;
	~EntryComparer();
};
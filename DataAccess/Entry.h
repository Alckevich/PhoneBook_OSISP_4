#pragma once

#define ENTRY_PHONE_LEN		8
#define ENTRY_LASTNAME_LEN	30
#define ENTRY_NAME_LEN		30
#define ENTRY_PATRONYM_LEN	30
#define ENTRY_STREET_LEN	30
#define ENTRY_HOUSE_LEN		5
#define ENTRY_HOUSING_LEN	5
#define ENTRY_APARTMENT_LEN	5

#define PHONE_DB_MAX_LEN	30


typedef struct PHONEBOOK_ENTRY {
	char phone[ENTRY_PHONE_LEN];
	char lastname[ENTRY_LASTNAME_LEN];
	char name[ENTRY_NAME_LEN];
	char patronym[ENTRY_PATRONYM_LEN];
	char street[ENTRY_STREET_LEN];
	char house[ENTRY_HOUSE_LEN];
	char housing[ENTRY_HOUSING_LEN];
	char apartment[ENTRY_APARTMENT_LEN];
} ENTRY;


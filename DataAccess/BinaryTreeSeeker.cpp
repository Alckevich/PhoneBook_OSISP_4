#include "stdafx.h"
#include "BinaryTreeSeeker.h"
#include <string>


BinaryTreeSeeker::BinaryTreeSeeker()
{
}

BOOL BinaryTreeSeeker::Seek(DbNode* root, ENTRY* entry, std::string lastName){
	if (!(root)) {
		return false;
	}
	if (StringComparer::icompare(lastName, root->lpData->lastname) < 0){
		return Seek(root->lpLeftChild, entry, lastName);
	}
	else if (StringComparer::icompare(lastName, root->lpData->lastname) > 0){
		return Seek(root->lpRightChild, entry, lastName);
	}
	else{
		(*entry) = (*root->lpData);
		return true;
	}
}

BinaryTreeSeeker::~BinaryTreeSeeker()
{
}

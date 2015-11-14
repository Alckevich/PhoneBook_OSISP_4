#include "stdafx.h"
#include "BinaryTreeSeeker.h"
#include <string>


BinaryTreeSeeker::BinaryTreeSeeker()
{
}

BOOL BinaryTreeSeeker::Seek(DbNode* root, std::vector<ENTRY>* entries, COMPAREFUNC compareFunc){
	if (!(root)) {
		return false;
	}
	if (compareFunc(root->lpData) < 0){
		return Seek(root->lpLeftChild, entries, compareFunc);
	}
	else if (compareFunc(root->lpData) > 0){
		return Seek(root->lpRightChild, entries, compareFunc);
	}
	else{
		entries->push_back(*root->lpData);
		Seek(root->lpRightChild, entries, compareFunc);
		return true;
	}
}

BinaryTreeSeeker::~BinaryTreeSeeker()
{
}

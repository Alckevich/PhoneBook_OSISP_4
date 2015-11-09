#include "stdafx.h"
#include "DbBinTreeBuilder.h"


DbBinTreeBuilder::DbBinTreeBuilder(std::vector<ENTRY>* enries){
	this->entries = enries;
}

void DbBinTreeBuilder::Build(DbNode** root){
	if (entries != NULL && entries->size() > 0){
		(*root) = new DbNode(&(*entries)[0]);
	}
	for (int i = 1; i < entries->size(); i++){
		this->insert(root, &(*entries)[i]);
	}
}

void DbBinTreeBuilder::insert(DbNode** root, ENTRY* entry){
	if (!(*root)) {
		*root = new DbNode(entry);
		return;
	}
	if (StringComparer::icompare(entry->lastname, (*root)->lpData->lastname) < 0){
		insert(&(*root)->lpLeftChild, entry);
	}
	else if (StringComparer::icompare(entry->lastname, (*root)->lpData->lastname) >= 0){
		insert(&(*root)->lpRightChild, entry);
	}
}

DbBinTreeBuilder::~DbBinTreeBuilder(){
}

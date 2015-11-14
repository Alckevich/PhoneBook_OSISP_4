#include "stdafx.h"
#include "DbBinTreeBuilder.h"

DbBinTreeBuilder::DbBinTreeBuilder(std::vector<ENTRY>* enries, PREDICATE predicate){
	this->entries = enries;
	this->predicate = predicate;
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

	if (predicate(entry, (*root)->lpData)){
		insert(&(*root)->lpRightChild, entry);
	}
	else{
		insert(&(*root)->lpLeftChild, entry);
	}
}

DbBinTreeBuilder::~DbBinTreeBuilder(){
}

#include "stdafx.h"
#include "DbNode.h"

DbNode::DbNode()
{
}

DbNode::DbNode(ENTRY* lpData)
{
	this->lpData = lpData;
}

DbNode::~DbNode()
{
}

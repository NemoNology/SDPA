#pragma once

using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
	
	T Value;

	BinaryTreeNode* Left;
	BinaryTreeNode* Right;

	BinaryTreeNode(T value)
	{
		Value = value;
	}
};

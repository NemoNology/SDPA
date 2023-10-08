#pragma once
#include <stack>

using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
	T Value;

	BinaryTreeNode *Left;
	BinaryTreeNode *Right;

	BinaryTreeNode(T value, BinaryTreeNode *left = nullptr, BinaryTreeNode *right = nullptr)
	{
		Value = value;
		Left = left;
		Right = right;
	}

	~BinaryTreeNode()
	{
		DisposeChildren();
	}

	void DisposeChildren()
	{
		stack<BinaryTreeNode *> s;
		if (Left != nullptr)
		{
			s.push(Left);
		}
		if (Right != nullptr)
		{
			s.push(Right);
		}

		this->Left = nullptr;
		this->Right = nullptr;

		while (!s.empty())
		{
			BinaryTreeNode *node = s.top();
			s.pop();

			if (node->Left != nullptr)
			{
				s.push(node->Left);
			}
			if (node->Right != nullptr)
			{
				s.push(node->Right);
			}

			node->Left = nullptr;
			node->Right = nullptr;

			delete node;
		}
	}

	string toString()
	{
		string l, r;

		l = Left == nullptr ? "NULL" : to_string(Left->Value);
		r = Right == nullptr ? "NULL" : to_string(Right->Value);

		return "Value: " + to_string(Value) + "; Left: " + l + "; Right: " + r;
	}
};

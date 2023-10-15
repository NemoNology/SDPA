#pragma once
#include <stack>

using namespace std;

template <typename T>
class BinarySearchTreeNode
{
public:
	T Value;

	BinarySearchTreeNode<T> *Left;
	BinarySearchTreeNode<T> *Right;

	BinarySearchTreeNode<T>(T value, BinarySearchTreeNode<T> *left = nullptr, BinarySearchTreeNode<T> *right = nullptr)
	{
		Value = value;
		Left = left;
		Right = right;
	}

	~BinarySearchTreeNode<T>()
	{
		DisposeChildren();
	}

	void DisposeChildren()
	{
		auto nd{[](stack<BinarySearchTreeNode<T> *> &s, BinarySearchTreeNode<T> *&node)
				{
					if (node->Left != nullptr)
					{
						s.push(node->Left);
						node->Left = nullptr;
					}
					if (node->Right != nullptr)
					{
						s.push(node->Right);
						node->Right = nullptr;
					}
				}};

		stack<BinarySearchTreeNode<T> *> s;
		auto root = this;
		nd(s, root);

		while (!s.empty())
		{
			BinarySearchTreeNode<T> *node = s.top();
			s.pop();
			nd(s, node);
			delete node;
		}
	}

	string ToString()
	{
		string l, r;

		l = Left == nullptr ? "NULL" : to_string(Left->Value);
		r = Right == nullptr ? "NULL" : to_string(Right->Value);

		return "Value: " + to_string(Value) + "; Left: " + l + "; Right: " + r;
	}

	static string ToString(BinarySearchTreeNode<T> *node)
	{
		if (node == nullptr)
			return "NULL";

		return node->ToString();
	}
};

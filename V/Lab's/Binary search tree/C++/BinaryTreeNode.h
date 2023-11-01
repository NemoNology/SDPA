#pragma once
#include <stack>

using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
	T Value;

	BinaryTreeNode<T> *Left;
	BinaryTreeNode<T> *Right;

	BinaryTreeNode<T>(T value, BinaryTreeNode<T> *left = nullptr, BinaryTreeNode<T> *right = nullptr)
	{
		Value = value;
		Left = left;
		Right = right;
	}

	void DisposeChildren()
	{
		auto nd{[](stack<BinaryTreeNode<T> *> &s, BinaryTreeNode<T> *&node)
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

		stack<BinaryTreeNode<T> *> s;
		auto root = this;
		nd(s, root);

		while (!s.empty())
		{
			BinaryTreeNode<T> *node = s.top();
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

	static void SetNew(BinaryTreeNode<T> *&oldNode, BinaryTreeNode<T> *newNode)
	{
		BinaryTreeNode<T> *nodeBufferForDelete = oldNode;
		oldNode = newNode;
		delete nodeBufferForDelete;
	}

	static string ToString(BinaryTreeNode<T> *node)
	{
		if (node == nullptr)
			return "NULL";

		return node->ToString();
	}
};

#pragma once
#include <stack>

using namespace std;

template <typename T>
class BinarySearchTreeNode
{
public:
	T Value;

	BinarySearchTreeNode *Left;
	BinarySearchTreeNode *Right;

	BinarySearchTreeNode(T value, BinarySearchTreeNode *left = nullptr, BinarySearchTreeNode *right = nullptr)
	{
		Value = value;
		Left = left;
		Right = right;
	}

	~BinarySearchTreeNode()
	{
		DisposeChildren();
	}

	void DisposeChildren()
	{
		auto nd{[](stack<BinarySearchTreeNode *> &s, BinaryTreeNode *&node)
				{
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
				}};

		stack<BinarySearchTreeNode *> s;
		auto root = this;
		nd(s, root);

		while (!s.empty())
		{
			BinarySearchTreeNode *node = s.top();
			s.pop();
			nd(s, node);
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

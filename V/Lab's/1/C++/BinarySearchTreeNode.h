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
		auto nd{[](stack<BinaryTreeNode *> &s, BinaryTreeNode *&node)
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

		stack<BinaryTreeNode *> s;
		auto root = this;
		nd(s, root);

		while (!s.empty())
		{
			BinaryTreeNode *node = s.top();
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

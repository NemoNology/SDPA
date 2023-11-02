#pragma once
#include <stack>

using namespace std;

template <typename T>
class AVLTreeNode
{
public:
	T Value;
	int Height;

	AVLTreeNode<T> *Left;
	AVLTreeNode<T> *Right;

	AVLTreeNode<T>(T value, int height, AVLTreeNode<T> *left = nullptr, AVLTreeNode<T> *right = nullptr)
	{
		Value = value;
		Height = height;
		Left = left;
		Right = right;
	}

	void DisposeChildren()
	{
		auto nd{[](stack<AVLTreeNode<T> *> &s, AVLTreeNode<T> *&node)
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

		stack<AVLTreeNode<T> *> s;
		auto root = this;
		nd(s, root);

		while (!s.empty())
		{
			AVLTreeNode<T> *node = s.top();
			s.pop();
			nd(s, node);
			delete node;
		}
	}

	int GetBalanceFactor()
	{
		int heightLeft = Left == nullptr ? 0 : Left->Height;
		int heightRight = Right == nullptr ? 0 : Right->Height;

		return 	heightRight - heightLeft;
	}

	string ToString()
	{
		string l, r;

		l = Left == nullptr ? "NULL" : to_string(Left->Value);
		r = Right == nullptr ? "NULL" : to_string(Right->Value);

		return "Value: " + to_string(Value) + ", Height: " + to_string(Height) + "; Left: " + l + "; Right: " + r;
	}

	static void SetNew(AVLTreeNode<T> *&oldNode, AVLTreeNode<T> *newNode)
	{
		AVLTreeNode<T> *nodeBufferForDelete = oldNode;
		oldNode = newNode;
		delete nodeBufferForDelete;
	}

	static string ToString(AVLTreeNode<T> *node)
	{
		if (node == nullptr)
			return "NULL";

		return node->ToString();
	}
};

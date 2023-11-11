#pragma once
#include <stack>

using namespace std;

/// <summary>
/// Binary tree node
/// </summary>
/// <typeparam name="T">Node value type</typeparam>
template <typename T>
class BinaryTreeNode
{
public:
	T Value;

	/// @brief Pointer to left child of current node
	BinaryTreeNode<T> *Left;
	/// @brief Pointer to right child of current node
	BinaryTreeNode<T> *Right;

	/// @brief Initialize new binary search tree node
	/// @param value Value for current node
	/// @param left Pointer to left child of current node
	/// @param right Pointer to right child of current node
	BinaryTreeNode<T>(T value, BinaryTreeNode<T> *left = nullptr, BinaryTreeNode<T> *right = nullptr)
	{
		Value = value;
		Left = left;
		Right = right;
	}

	/// <summary>
	/// Dispose all children with memory free
	/// </summary>
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

	/// <summary>
	/// Convert node into string
	/// </summary>
	/// <returns>Converted node</returns>
	string ToString()
	{
		string l, r;

		l = Left == nullptr ? "NULL" : to_string(Left->Value);
		r = Right == nullptr ? "NULL" : to_string(Right->Value);

		return "Value: " + to_string(Value) + "; Left: " + l + "; Right: " + r;
	}

	/// <summary>
	/// Setted old node into new node with memory free
	/// </summary>
	/// <param name="oldNode"> Setting node </param>
	/// <param name="newNode"> Setted node </param>
	static void SetNew(BinaryTreeNode<T> *&oldNode, BinaryTreeNode<T> *newNode)
	{
		BinaryTreeNode<T> *nodeBufferForDelete = oldNode;
		oldNode = newNode;
		delete nodeBufferForDelete;
	}

	/// <summary>
	/// Convert node into string
	/// </summary>
	/// <param name="node">Converting node</param>
	/// <returns>Converted node</returns>
	static string ToString(BinaryTreeNode<T> *node)
	{
		if (node == nullptr)
			return "NULL";

		return node->ToString();
	}
};

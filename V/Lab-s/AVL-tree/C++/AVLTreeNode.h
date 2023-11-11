#pragma once
#include <stack>

using namespace std;

template <typename T>
class AVLTreeNode
{
public:
	T Value;
	/// <summary>
	/// Height of current node (Tree depth; 1 - if node do not have children)
	/// </summary>
	int Height;

	/// @brief Pointer to left child of current node
	AVLTreeNode<T> *Left;
	/// @brief Pointer to right child of current node
	AVLTreeNode<T> *Right;

	/// @brief Initialize new AVL-tree node
	/// @param value Value for current node
	/// @param height Height for current node
	/// @param left Pointer to left child of current node
	/// @param right Pointer to right child of current node
	AVLTreeNode<T>(T value, int height = 1, AVLTreeNode<T> *left = nullptr, AVLTreeNode<T> *right = nullptr)
	{
		Value = value;
		Height = height;
		Left = left;
		Right = right;
	}

	/// <summary>
	/// Rotate right current node
	/// </summary>
	void RotateRight()
	{
		T valueBuffer = Value;
		T leftValueBuffer = Left->Value;
		AVLTreeNode<T> *leftBuffer = Left;
		AVLTreeNode<T> *rightBuffer = Right;
		Left = Left->Left;
		Right = new AVLTreeNode<T>(valueBuffer, 1,
								   leftBuffer != nullptr ? leftBuffer->Right : nullptr,
								   rightBuffer);
		SetNew(leftBuffer, nullptr);
		Right->UpdateHeight();
		Value = leftValueBuffer;
		if (Left != nullptr)
			Left->UpdateHeight();
		UpdateHeight();
	}

	/// <summary>
	/// Rotate left current node
	/// </summary>
	void RotateLeft()
	{
		T valueBuffer = Value;
		T rightValueBuffer = Right->Value;
		AVLTreeNode<T> *rightBuffer = Right;
		AVLTreeNode<T> *leftBuffer = Left;
		Right = Right->Right;
		Left = new AVLTreeNode<T>(valueBuffer, 1,
								  leftBuffer,
								  rightBuffer != nullptr ? rightBuffer->Left : nullptr);
		SetNew(rightBuffer, nullptr);
		Left->UpdateHeight();
		Value = rightValueBuffer;
		if (Right != nullptr)
			Right->UpdateHeight();
		UpdateHeight();
	}

	/// <summary>
	/// Balance current node <i>(Math...)</i>
	/// </summary>
	void Balance()
	{
		UpdateHeight();
		int BF = GetBalanceFactor();
		if (BF == 2)
		{
			if (Right->GetBalanceFactor() < 0)
				Right->RotateRight();
			RotateLeft();
		}
		else if (BF == -2)
		{
			if (Left->GetBalanceFactor() > 0)
				Left->RotateLeft();
			RotateRight();
		}
	}

	/// <summary>
	/// Balance all current tree node (Include children) starting from leafes
	/// </summary>
	void BalanceDeepRecursive()
	{
		if (Left != nullptr)
			Left->BalanceDeepRecursive();
		if (Right != nullptr)
			Right->BalanceDeepRecursive();
		Balance();
	}

	/// <summary>
	/// Recalculate all current tree node height (Include children) starting from children
	/// </summary>
	void UpdateHeightDeepRecursive()
	{
		if (Left != nullptr)
			Left->UpdateHeightDeepRecursive();
		if (Right != nullptr)
			Right->UpdateHeightDeepRecursive();
		UpdateHeight();
	}

	/// <summary>
	/// Dispose all children with memory free
	/// </summary>
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

	/// <summary>
	/// Calculate current node balance factor
	/// </summary>
	/// <returns>Balance factor</returns>
	int GetBalanceFactor()
	{
		int heightLeft = Left == nullptr ? 0 : Left->Height;
		int heightRight = Right == nullptr ? 0 : Right->Height;

		return heightRight - heightLeft;
	}

	/// <summary>
	/// Recalculate current node height
	/// </summary>
	void UpdateHeight()
	{
		int heightOfLeft = Left == nullptr ? 0 : Left->Height;
		int heightOfRight = Right == nullptr ? 0 : Right->Height;
		Height = (heightOfLeft > heightOfRight ? heightOfLeft : heightOfRight) + 1;
	}

	/// <summary>
	/// Convert node into string value
	/// </summary>
	/// <returns>Node as string value</returns>
	string ToString()
	{
		string l, r;

		l = Left == nullptr ? "NULL" : to_string(Left->Value);
		r = Right == nullptr ? "NULL" : to_string(Right->Value);

		return "Value: " + to_string(Value) + ", Height: " + to_string(Height) + "; Left: " + l + "; Right: " + r;
	}

	/// <summary>
	/// Setted old node into new node with memory free
	/// </summary>
	/// <param name="oldNode"> Setting node </param>
	/// <param name="newNode"> Setted node </param>
	static void SetNew(AVLTreeNode<T> *&oldNode, AVLTreeNode<T> *newNode)
	{
		AVLTreeNode<T> *nodeBufferForDelete = oldNode;
		oldNode = newNode;
		delete nodeBufferForDelete;
	}

	/// <summary>
	/// Convert inputted node into string
	/// </summary>
	/// <param name="node">Converting node</param>
	/// <returns>Converted node</returns>
	static string ToString(AVLTreeNode<T> *node)
	{
		if (node == nullptr)
			return "NULL";

		return node->ToString();
	}
};

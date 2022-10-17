#pragma once


using namespace std;


template <class T> class BinSTree;


template <class T> class TreeNode
{

private: 
	
	// Left and right nodes
	TreeNode * _left;
	TreeNode * _right;

public:

	// Data
	T _data;

	// Конструктор
	// Constuctor
	TreeNode(const T& data, TreeNode<T>* l = nullptr, TreeNode<T>* r = nullptr)
	{
		_data = data;
		_left = l;
		_right = r;
	}

	void SetChild(TreeNode<T>* l = nullptr, TreeNode<T>* r = nullptr)
	{
		_left = l;
		_right = r;
	}

	TreeNode<T> GetLeft()
	{
		return new TreeNode<T>(_left->_data, _left->_left, _right->_right);
	}

	TreeNode<T> GetRight()
	{
		return new TreeNode<T>(_right->_data, _left->_left, _right->_right);
	}



	friend class BinSTree<T>;

};

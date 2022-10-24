#pragma once


using namespace std;


template <class T> class BinTree;


template <class T> class TreeNode
{

private: 
	
	// Left and right nodes
	TreeNode<T> * _left;
	TreeNode<T> * _right;
	//TreeNode<T> * _parent;

public:

	// Data
	T _data;

	// Конструктор
	// Constuctor
	TreeNode(const T& data, TreeNode<T> * l = NULL, TreeNode<T> * r = NULL)//, TreeNode<T> * p = NULL)
	{
		_data = data;
		_left = l;
		_right = r;
		//_parent = p;
	}

	TreeNode(const T& data, TreeNode<T> l = NULL, TreeNode<T> r = NULL)//, TreeNode<T> * p = NULL)
	{
		_data = data;
		_left = new TreeNode<T>(l._data, l.Left(), l.Right());
		_right = new TreeNode<T>(r._data, r.Left(), r.Right());
		//_parent = new TreeNode<T>(p._data, p.Left(), p.Right());
	}

	TreeNode(const T& data, const T& ldata, const T& rdata)
	{
		_data = data;
		_left = new TreeNode<T>(ldata);
		_right = new TreeNode<T>(rdata);
	}

	
	TreeNode<T> * Left(void) const
	{
		return _left;
	}
	TreeNode<T> * Right(void) const
	{
		return _right;
	}
	// todo: parent
	/*TreeNode<T> * Parent(void) const
	{
		retunr _parent;
	}*/
	

	void SetChild(TreeNode<T> l = NULL, TreeNode<T> r = NULL)
	{
		_left = new TreeNode<T>(l._data, l.Left(), l.Right());
		_right = new TreeNode<T>(r._data, r.Left(), r.Right(), this);

	}

	void SetChild(TreeNode<T>* l = NULL, TreeNode<T>* r = NULL)
	{
		_left = new TreeNode<T>(l->_data, l->Left(), l->Right());
		_right = new TreeNode<T>(r->_data, r->Left(), r->Right());

	}

	void SetChild(T l = NULL, T r = NULL)
	{
		_left = new TreeNode<T>(l);
		_right = new TreeNode<T>(r);
	}


	// todo: delete/deconstuctor
	/*~TreeNode(TreeNode<T> TN)
	{
		while ((TN.Left() != nullptr) || (TN.Right() != nullptr))
		{
			while (TN.)
		}
	}*/


	friend class BinTree<T>;

};

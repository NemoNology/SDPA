#pragma once
#include <vector>
#include "MathModule.h"


using namespace std;
using uint = unsigned int;

template <class T> class BinTree;


template <class T> class TreeNode
{

private: 
	
	// Left and right nodes
	TreeNode<T> *_left;
	TreeNode<T> *_right;

public:

	// Data
	T _data;

	// Конструктор
	// Constuctor
	TreeNode(const T& data, TreeNode<T> *l = NULL, TreeNode<T> *r = NULL)
	{
		_data = data;
		_left = l;
		_right = r;
	}


	TreeNode<T> *Left(void) const
	{
		return _left;
	}
	TreeNode<T> *Right(void) const
	{
		return _right;
	}
	TreeNode<T> *This(void)
	{
		return this;
	}


	void SetChild(TreeNode<T> *l = NULL, TreeNode<T> *r = NULL)
	{
		_left = l;
		_right = r;

	}

	void ShowData()
	{
		cout << _data;
	}

	uint GetDepth(uint number = NULL)
	{
		TreeNode<T> *temp = this;
		uint counter = number, lc = 0, rc = 0;
		

		while ((temp->Left() != NULL) || (temp->Right() != NULL))
		{
			if (temp->Left() == NULL)
			{
				temp = temp->Right();
				counter++;
			}
			else if (temp->Right() == NULL)
			{
				temp = temp->Left();
				counter++;
			}
			else
			{
				lc = temp->Left()->GetDepth(counter + 1);
				rc = temp->Right()->GetDepth(counter + 1);

				break;
			}
		}
		
		return Max(lc, rc, counter);

		

	}

	void Free()
	{
		delete this;
		this->_left = NULL;
		this->_right = NULL;
		this->_data = NULL;
	}

	void Delete()
	{
		TreeNode<T> *temp = this;

		while ((temp->Left() != NULL) || (temp->Right() != NULL))
		{
			if (temp->Left() == NULL)
			{
				temp = temp->Right();
			}
			else if (temp->Right() == NULL)
			{
				temp = temp->Left();
			}
			else
			{
				temp->Left()->Delete();
				temp->Right()->Delete();
			}
		}

		temp->Free();
		temp = NULL;
		
	}


	friend class BinTree<T>;

};

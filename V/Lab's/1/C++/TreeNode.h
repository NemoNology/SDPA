#pragma once
#include <vector>
#include <queue>
#include <iomanip>
#include "MathModule.h"


using namespace std;

template <class T> class BinSTree;

template <class T> class TreeNode
{

private:

	// Left and right nodes
	TreeNode<T>* _left;
	TreeNode<T>* _right;

public:

	// Data
	T _data;

	// Constuctor
	TreeNode(const T data = NULL, TreeNode<T>* l = NULL, TreeNode<T>* r = NULL)
	{
		_data = data;
		_left = l;
		_right = r;
	}


	TreeNode<T>* Left(void) const
	{
		return _left;
	}
	TreeNode<T>* Right(void) const
	{
		return _right;
	}


	void SetChild(TreeNode<T>* l = NULL, TreeNode<T>* r = NULL)
	{
		_left = l;
		_right = r;
	}

	int GetDepth(int number = NULL)
	{
		TreeNode<T>* temp = this;
		int lc = 0, rc = 0;

		while ((temp->Left() != NULL) || (temp->Right() != NULL))
		{
			if (temp->Left() == NULL)
			{
				temp = temp->Right();
				number++;
			}
			else if (temp->Right() == NULL)
			{
				temp = temp->Left();
				number++;
			}
			else
			{
				lc = temp->Left()->GetDepth(number + 1);
				rc = temp->Right()->GetDepth(number + 1);

				break;
			}
		}

		return Max(lc, rc, number);

	}

	void Free()
	{
		this->_left = NULL;
		this->_right = NULL;
		this->_data = NULL;
		delete this;
	}

	void Delete()
	{
		TreeNode<T>* temp = this;

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


	friend class BinSTree<T>;

};



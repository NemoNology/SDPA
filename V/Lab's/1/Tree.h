#pragma once


using namespace std;


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

	void DeleteSimple()
	{
		delete this;
	}

	void Delete()
	{
		TreeNode<T> *root = this, *temp;

		temp = root;


		// todo: Change the algoritm

		while ((root->Left() != nullptr) || (root->Right() != nullptr))
		{
			while ((temp->Left() != nullptr) || (temp->Right() != nullptr))
			{
				if (temp->Left() != nullptr)
				{
					temp = temp->Left();
				}
				else if (temp->Right() != nullptr)
				{
					temp = temp->Right();
				}
				
			}

			// todo: invalid work of 'delete'
			// WISH: temp = 0x00000000000000... = NULL
			// REAL: temp = 0xdddddddddddddd... = ????? (Reading is impossible)
			temp->DeleteSimple();

			temp = root;

		}

		
	}



	friend class BinTree<T>;

};

#pragma once
#include <vector>
#include <queue>
#include <iomanip>
#include "MathModule.h"


using namespace std;

// todo: "using dt = temp->_data" || "dt = _data" is working?
// 
//using dt = _data;
//using lt = _left;
//using rt = _right;


template <class T> class BinSTree
{
private:
	
	TreeNode<T> * _root;
		
public:

	BinTree(TreeNode<T> * root = NULL)
	{
		_root = root;
	}
	
	int GetDepth(int number = NULL)
	{
		TreeNode<T>* temp = this;


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
				int lc = temp->Left()->GetDepth(counter + 1);
				int rc = temp->Right()->GetDepth(counter + 1);

				break;
			}
		}

		return Max(lc, rc, number);

	}

	int GetDepthByKey(T key)
	{
		TreeNode<T> * temp = _root;
		int D = 0;
		
		while (temp->_left != NULL || temp->_right != NULL)
		{
			if (temp->_data == key)
			{
				return D;
			}
			else if (temp->_data > key && temp->_left != NULL)
			{
				D++;
				temp = temp->_left;
			}
			else if (temp->_data < key && temp->_right != NULL)
			{
				D++;
				temp = temp->_right;
			}
			else 
			{
				return -1;
			}
		}
	}
	
	// todo: "temp = _root" is working?
	TreeNode<T> * FIND(T key, TreeNode<T> * temp = _root)
	{
		if (temp == NULL)
		{
			return NULL;
		}
		
		T dt = temp->_data;
		
		if (dt == key)
		{
			return temp;
		}
		else if (dt > key)
		{
			FIND(key, temp->_left)
		}
		else
		{
			FIND(key, temp->_right)
		}
		
	}
	
	void INSERT(T item)
	{
		if (_root == NULL)
		{
			_root = new TreeNode<T>;
			_root->_data = item;
			return;
		}
		
		TreeNode<T> * temp = _root;
		
		while (temp != NULL || temp->data != item)
		{
			if (temp->_data > item)
			{
				temp = temp->_left;
			}
			else
			{
				temp = temp->_right;
			}
		}
		
		TreeNode<T> * NewTreeNode = new TreeNode<T>(item, temp->_left, temp->_right);
		
		temp = NewTreeNode;
	}
	
	void REMOVE(T key)
	{
		if (_root == NULL)
		{
			return;
		}
		
		TreeNode<T> * temp = _root;
		T dt = temp->_data;
		
		while (temp != NULL || temp->data != item)
		{
			if (dt > key)
			{
				temp = temp->_left;
			}
			else if (dt < key)
			{
				temp = temp->_right;
			}
			else 
			{
				// Do not have children;
				if (temp->_right == NULL && temp->_left == NULL)
				{
					temp.Free();
				}
				// Do have 2 children;
				else if (temp->_right != NULL && temp->_left != NULL)
				{
					if (temp->_right->_left == NULL)
					{
						TreeNode<T> * tp = temp->_right;
						temp = new TreeNode<T>(temp->_right->data, temp->_left, NULL);
						tp.Free();
					}
					else
					{
						TreeNode<T> * tp = temp->_right->_left;
						
						while (tp->_left != NULL)
						{
							tp = tp->_left;
						}

						temp = new TreeNode<T>(tp->data, temp->_left, temp->_right);
						tp.Free();
					}
				}
				// Do have 1 children;
				else 
				{
					if (temp->_left != NULL)
					{
						TreeNode<T> * tp = temp->_left;
					}
					else 
					{
						TreeNode<T> * tp = temp->_right;
					}
					
					temp = new TreeNode<T>(tp->_data, tp->_left, tp->_right);
					tp.Free();
					
				}
			}
		}
	}
	
	vector<TreeNode<T> *> VisitWidth()
	{
		vector<TreeNode<T> *> res(Pow(2, _root.GetDepth() + 1));
		TreeNode<T> * temp;
		
		queue<TreeNode<T> *> q;
		
		q.push(_root);
		
		while (!q.empty())
		{
			res.append(q.front);
			temp = q.front();
			q.pop();
			
			if (temp->_left != NULL)
			{
				q.push(temp->_left);
			}
			else if (temp->_left == NULL && temp->_right != NULL)
			{
				q.push(NULL);
			}
			if (temp->_right != NULL)
			{
				q.push(temp->_right);
			}
			else if (temp->_right == NULL && temp->_left != NULL)
			{
				q.push(NULL);
			}
		}
		
		return res;
		
	}
	
	vector<int> GetData()
	{
		vector<int> res(Pow(2, _root.GetDepth() + 1));
		
		vector<TreeNode<T> *> nodes = _root->VisitWidth();
		
		for (int i = 0; i < res.size(); i++)
		{
			if (nodes[i] == NULL)
			{
				res[i] = 0;
			}
			else
			{
				res[i] = nodes[i]->_data;
			}
		}
		
		return res;
		
	}
	
	// NumberSymbolsAmount - max symbols size in max/min number in tree
	// Indent - indent between leaves in one leaves pair
	void PrintTreeV(int indent = 3, int NumberSymbolsAmount = 3)
	{
		if (_root == NULL)
		{
			return;
		}
		else
		{
			int D = _root.GetDepth() + 1, nasy = NumberSymbolsAmount / 2;
			ind indy = indent / 2;
			
			vector<int> iPair(D);
			
			vector<int> datas = _root->GetData();
			int counter = 0;
			
			iPair[0] = indent + NumberSymbolsAmount;
			
			vector<int> keys(D);
			keys[0] = 2;
			//keys[0] = keys[1] = 2;
			keys[1] = 2;
			
			for (int i = 1; i < D - 1; i++)
			{
				iPair[i] = iPair[i - 1] * 2 + indy;
				keys[i + 1] = keys[i] * 2 + 1;
			}
			
			if (D > 1)
			{
				iPair[D - 1] = iPair[D - 2] * 2 + indent;
			}
			
			
			for (int i = 1; i < D + 1; i++)
			{
				for (counter; counter < Pow(2, i - 1); counter++)
				{
					if (counter + 1 == keys[i - 1])
					{
						cout << setw(iPair[D - i] + nasy) << datas[counter] << setw(iPair[D - i] + indent) << " ";
					}
					else
					{
						cout << setw(iPair[D - i] + nasy) << datas[counter] << setw(iPair[D - i] + indy) << " ";
					}
					
				}
				
				cout << "\n";
				
			}
			
		}
		
	}
	
	
	// Indent - indent between levels
	void PrintTreeH(TreeNode<T> * node = _root, int indent = 6, int level = 0)
	{
		if (node != NULL)
		{
			PrintTreeH(node->_right, indent, level + 1);
			
			cout  << setw(indent * level) << node->_data << "\n";
		
			PrintTreeH(node->_left, indent, level + 1);
		}
	}
	
}


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
	TreeNode(const T& data, TreeNode<T>* l = NULL, TreeNode<T>* r = NULL)
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
	TreeNode<T>* This(void)
	{
		return this;
	}


	void SetChild(TreeNode<T>* l = NULL, TreeNode<T>* r = NULL)
	{
		_left = l;
		_right = r;
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


	friend class BinTree<T>;

};
#include <iostream>
#include "BinarySearchTreeNode.h"
#include <stack>

using namespace std;

template <typename T>
class BinarySearchTree
{
public:
    BinarySearchTreeNode<T> *Root;

    BinarySearchTree(BinarySearchTreeNode<T> *root = nullptr)
    {
        Root = root;
    }

    ~BinarySearchTree<T>()
    {
        Clear();
    }

    void Clear()
    {
        if (Root != nullptr)
        {
            DisposeRootChildren();
            delete Root;
            Root = nullptr;
        }
    }

    void DisposeRootChildren()
    {
        if (Root == nullptr)
            return;

        auto nd{[](stack<BinarySearchTreeNode<T> *> &s, BinarySearchTreeNode<T> *&node)
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

        stack<BinarySearchTreeNode<T> *> s;
        nd(s, Root);

        while (!s.empty())
        {
            BinarySearchTreeNode<T> *node = s.top();
            s.pop();
            nd(s, node);
            delete node;
        }
    }

    string ToString()
    {
        return "Root: [" + (Root == nullptr ? "NULL" : Root->ToString()) + "]";
    }
};

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

    void Add(T value)
    {
        auto addingNode = new BinarySearchTreeNode<T>(value);

        if (Root == nullptr)
        {
            Root = addingNode;
        }
        else
        {
            BinarySearchTreeNode<T> *nodeBuffer = Root;
            T valueBuffer;

            while (true)
            {
                valueBuffer = nodeBuffer->Value;
                bool isLess = value < valueBuffer;
                if (nodeBuffer->Left != nullptr && isLess)
                {
                    nodeBuffer = nodeBuffer->Left;
                }
                else if (nodeBuffer->Right != nullptr && !isLess)
                {
                    nodeBuffer = nodeBuffer->Right;
                }
                else
                {
                    if (isLess)
                        nodeBuffer->Left = addingNode;
                    else
                        nodeBuffer->Right = addingNode;
                    break;
                }
            }
        }
    }

    bool Contains(T value)
    {
        BinarySearchTreeNode<T> *nodeBuffer = Root;

        while (nodeBuffer != nullptr)
        {
            T valueBuffer = nodeBuffer->Value;
            if (value == valueBuffer)
                return true;
            else if (value < valueBuffer)
                nodeBuffer = nodeBuffer->Left;
            else
                nodeBuffer = nodeBuffer->Right;
        }

        return false;
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

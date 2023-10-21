#include <iostream>
#include "BinarySearchTreeNode.h"
#include <stack>
#include <queue>
#include <math.h>
#include <iomanip>

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
            Root = addingNode;
        else
        {
            BinarySearchTreeNode<T> *nodeBuffer = Root;

            while (true)
            {
                bool isMore = value > nodeBuffer->Value;
                bool isNotLeft = nodeBuffer->Left == nullptr;
                bool isNotRight = nodeBuffer->Right == nullptr;

                if (isMore && isNotRight)
                {
                    nodeBuffer->Right = addingNode;
                    break;
                }
                else if (!isMore && isNotLeft)
                {
                    nodeBuffer->Left = addingNode;
                    break;
                }
                else if (isMore && !isNotRight)
                    nodeBuffer = nodeBuffer->Right;
                else
                    nodeBuffer = nodeBuffer->Left;
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
            else if (value > valueBuffer)
                nodeBuffer = nodeBuffer->Right;
            else
                nodeBuffer = nodeBuffer->Left;
        }

        return false;
    }

    BinarySearchTreeNode<T> *Find(T value)
    {
        BinarySearchTreeNode<T> *nodeBuffer = Root;

        while (nodeBuffer != nullptr)
        {
            T valueBuffer = nodeBuffer->Value;
            if (value == valueBuffer)
                return nodeBuffer;
            else if (valueBuffer > value)
                nodeBuffer = nodeBuffer->Right;
            else
                nodeBuffer = nodeBuffer->Left;
        }

        return nullptr;
    }

    void PrintHorizontalRecursive(BinarySearchTreeNode<T> *node, int level = 0, int indent = 6)
    {
        if (node == nullptr)
            return;

        BinarySearchTreeNode<T> *r = node->Right;
        BinarySearchTreeNode<T> *l = node->Left;

        if (r != nullptr)
            PrintHorizontalRecursive(r, level + 1, indent);

        for (int i = 0; i < level; i++)
            for (int j = 0; j < indent; j++)
                cout << " ";
        cout << node->Value << "\n";

        if (l != nullptr)
            PrintHorizontalRecursive(l, level + 1, indent);
    }

    void PrintVertical(int dataLength = 2, int canvasWidth = 64)
    {
        if (Root == nullptr)
        {
            for (int i = 0; i < canvasWidth / 2; i++)
                cout << " ";
            cout << "NULL\n";
            return;
        }

        queue<pair<BinarySearchTreeNode<T> *, int>> q;
        int levelBuffer = 1;
        q.push(make_pair(Root, levelBuffer));

        while (q.size() > 0)
        {
            pair<BinarySearchTreeNode<T> *, int> item = q.front();
            q.pop();
            BinarySearchTreeNode<T> *node = item.first;
            int level = item.second;
            int indent = (int)(canvasWidth / pow(2, level));

            q.push(make_pair(node->Left, level + 1));
            q.push(make_pair(node->Right, level + 1));
            for (int i = 0; i < indent; i++)
                cout << " ";
            if (node != nullptr)
                cout << setw(dataLength) << node->Value;
            else
                cout << setw(dataLength) << " ";

            if (level != levelBuffer)
            {
                cout << "\n";
                levelBuffer++;
            }
        }
    }

    void Delete(T value)
    {
        BinarySearchTreeNode<T> *node = Root;

        while (node != nullptr)
        {
            BinarySearchTreeNode<T> *l = node->Left;
            BinarySearchTreeNode<T> *r = node->Right;
            bool isMore = value > node->Value;

            if (node->Value == value)
            {
                bool isNotRight = r == nullptr;
                bool isNotChildren = isNotRight && l == nullptr;
                if (!isNotChildren)
                {
                    BinarySearchTreeNode<T> *rl = r->Left;
                    if (rl == nullptr)
                    {
                        delete node;
                        node = r;
                    }
                    else
                    {
                        while (rl->Left != nullptr)
                            rl = rl->Left;
                        node->Value = rl->Value;
                        delete rl;
                        rl = nullptr;
                    }
                }
                else
                {
                    delete node;
                    if (isNotChildren)
                        node = nullptr;
                    else if (!isNotRight)
                        node = r;
                    else
                        node = l;
                }

                break;
            }
            else if (isMore)
                node = r;
            else
                node = l;
        }
    }

    int Count()
    {
        if (Root == nullptr)
            return 0;

        stack<BinarySearchTreeNode<T> *> s;
        int count = 1;
        s.push(Root);

        while (!s.empty())
        {
            BinarySearchTreeNode<T> *nodeBuffer = s.top();
            s.pop();
            auto left = nodeBuffer->Left;
            auto right = nodeBuffer->Right;
            if (left != nullptr)
            {
                s.push(left);
                count++;
            }
            if (right != nullptr)
            {
                s.push(right);
                count++;
            }
        }

        return count;
    }

    int CountLeaf()
    {
        if (Root == nullptr)
            return 0;

        stack<BinarySearchTreeNode<T> *> s;
        int count = 0;
        s.push(Root);

        while (!s.empty())
        {
            BinarySearchTreeNode<T> *nodeBuffer = s.top();
            s.pop();
            auto left = nodeBuffer->Left;
            auto right = nodeBuffer->Right;
            if (left != nullptr)
                s.push(left);
            if (right != nullptr)
                s.push(right);
            if (left == nullptr && right == nullptr)
                count++;
        }

        return count;
    }

    int GetDepth()
    {
        if (Root == nullptr)
            return -1;

        int depth = 0;

        stack<pair<BinarySearchTreeNode<T> *, int>> s;
        s.push(make_pair(Root, 0));

        while (!s.empty())
        {
            pair<BinarySearchTreeNode<T> *, int> bufferPair = s.top();
            s.pop();

            auto left = bufferPair.first->Left;
            auto currentDepth = bufferPair.second;
            auto right = bufferPair.first->Right;

            if (left != nullptr)
                s.push(make_pair(left, currentDepth + 1));
            if (right != nullptr)
                s.push(make_pair(right, currentDepth + 1));

            if (currentDepth > depth)
                depth = currentDepth;
        }

        return depth;
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

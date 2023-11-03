#include <iostream>
#include "BinaryTreeNode.h"
#include <stack>
#include <queue>
#include <math.h>
#include <iomanip>

using namespace std;

template <typename T>
class BinarySearchTree
{
public:
    BinaryTreeNode<T> *Root;

    BinarySearchTree(BinaryTreeNode<T> *root = nullptr)
    {
        Root = root;
    }

    void Add(T value)
    {
        auto addingNode = new BinaryTreeNode<T>(value);

        if (Root == nullptr)
            Root = addingNode;
        else
        {
            BinaryTreeNode<T> *nodeBuffer = Root;

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
        BinaryTreeNode<T> *nodeBuffer = Root;

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

    BinaryTreeNode<T> *Find(T value)
    {
        BinaryTreeNode<T> *nodeBuffer = Root;

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

    void PrintHorizontalRecursive(BinaryTreeNode<T> *node, int level = 0, int indent = 6)
    {
        if (node == nullptr)
            return;

        BinaryTreeNode<T> *r = node->Right;
        BinaryTreeNode<T> *l = node->Left;

        if (r != nullptr)
            PrintHorizontalRecursive(r, level + 1, indent);

        for (int i = 0; i < level; i++)
            for (int j = 0; j < indent; j++)
                cout << " ";
        cout << node->Value << "\n";

        if (l != nullptr)
            PrintHorizontalRecursive(l, level + 1, indent);
    }

    void PrintVertical(int dataWidth = 2, int canvasWidth = 64, string nullValue = "--")
    {
        queue<pair<BinaryTreeNode<T> *, pair<int, int>>> q;
        int currentLevel = 0, currentPosition = 0, currentIndent = canvasWidth / 4;
        q.push(make_pair(Root, make_pair(currentLevel, canvasWidth / 2)));

        while (q.size() > 0)
        {
            pair<BinaryTreeNode<T> *, pair<int, int>> nodeInfo = q.front();
            BinaryTreeNode<T> *node = nodeInfo.first;
            int level = nodeInfo.second.first;
            int position = nodeInfo.second.second;
            q.pop();

            if (currentLevel < level)
            {
                currentLevel = level;
                currentPosition = 0;
                currentIndent /= 2;
                cout << "\n";
            }

            while (currentPosition < position)
            {
                cout << " ";
                currentPosition++;
            }

            if (node == nullptr)
                cout << setw(dataWidth) << nullValue;
            else
            {
                auto l = node->Left;
                auto r = node->Right;

                if (l != nullptr || r != nullptr)
                {
                    int futureLevel = level + 1;
                    q.push(make_pair(l, make_pair(futureLevel, position - currentIndent)));
                    q.push(make_pair(r, make_pair(futureLevel, position + currentIndent - dataWidth)));
                }

                cout << setw(dataWidth) << node->Value;
            }
        }

        cout << "\n";
    }

    void Delete(T value)
    {
        BinaryTreeNode<T> **nodeBuffer = &Root;

        while (nodeBuffer != nullptr)
        {
            BinaryTreeNode<T> **leftBuffer = &((*nodeBuffer)->Left);
            BinaryTreeNode<T> **rightBuffer = &((*nodeBuffer)->Right);
            bool isMore = value > (*nodeBuffer)->Value;

            if ((*nodeBuffer)->Value == value)
            {
                bool isRight = *rightBuffer != nullptr;
                bool isLeft = *leftBuffer != nullptr;
                bool areBothChildren = isRight && isLeft;
                if (areBothChildren)
                {
                    BinaryTreeNode<T> **rl = &((*rightBuffer)->Left);
                    if (*rl == nullptr)
                    {
                        AVLTreeNode<T>::SetNew(*nodeBuffer, *rightBuffer);
                        AVLTreeNode<T>::SetNew((*nodeBuffer)->Left, *leftBuffer);
                    }
                    else
                    {
                        while ((*rl)->Left != nullptr)
                            rl = &((*rl)->Left);
                        (*nodeBuffer)->Value = (*rl)->Value;
                        BinaryTreeNode<T>::SetNew(*rl, (*rl)->Right);
                        BinaryTreeNode<T>::SetNew(*rl, nullptr);
                    }
                }
                else if (!isRight && !isLeft)
                    BinaryTreeNode<T>::SetNew(*nodeBuffer, nullptr);
                else if (isRight)
                    BinaryTreeNode<T>::SetNew(*nodeBuffer, *rightBuffer);
                else
                    BinaryTreeNode<T>::SetNew(*nodeBuffer, *leftBuffer);

                break;
            }
            else if (isMore)
                nodeBuffer = rightBuffer;
            else
                nodeBuffer = leftBuffer;
        }
    }

    int Count()
    {
        if (Root == nullptr)
            return 0;

        stack<BinaryTreeNode<T> *> s;
        int count = 1;
        s.push(Root);

        while (!s.empty())
        {
            BinaryTreeNode<T> *nodeBuffer = s.top();
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

        stack<BinaryTreeNode<T> *> s;
        int count = 0;
        s.push(Root);

        while (!s.empty())
        {
            BinaryTreeNode<T> *nodeBuffer = s.top();
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

        stack<pair<BinaryTreeNode<T> *, int>> s;
        s.push(make_pair(Root, 0));

        while (!s.empty())
        {
            pair<BinaryTreeNode<T> *, int> bufferPair = s.top();
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
            Root->DisposeChildren();
            delete Root;
            Root = nullptr;
        }
    }

    string ToString()
    {
        return "Root: [" + (Root == nullptr ? "NULL" : Root->ToString()) + "]";
    }
};

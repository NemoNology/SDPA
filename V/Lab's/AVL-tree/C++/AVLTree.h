#include <iostream>
#include "AVLTreeNode.h"
#include <stack>
#include <queue>
#include <iomanip>

using namespace std;

template <typename T>
class AVLTree
{
public:
    AVLTreeNode<T> *Root;

    AVLTree(AVLTreeNode<T> *root = nullptr)
    {
        Root = root;
    }

    void Add(T value)
    {
        auto addingNode = new AVLTreeNode<T>(value);

        if (Root == nullptr)
            Root = addingNode;
        else
        {
            AVLTreeNode<T> *nodeBuffer = Root;

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

            // TODO: Balance node buffer
        }
    }

    bool Contains(T value)
    {
        AVLTreeNode<T> *nodeBuffer = Root;

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

    AVLTreeNode<T> *Find(T value)
    {
        AVLTreeNode<T> *nodeBuffer = Root;

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

    void PrintHorizontalRecursive(AVLTreeNode<T> *node, int level = 0, int indent = 6)
    {
        if (node == nullptr)
            return;

        AVLTreeNode<T> *r = node->Right;
        AVLTreeNode<T> *l = node->Left;

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
        PrintVertical(Root, dataWidth, canvasWidth, nullValue);
    }

    static void PrintVertical(AVLTreeNode<T> *node, int dataWidth = 2, int canvasWidth = 64, string nullValue = "--")
    {
        queue<pair<AVLTreeNode<T> *, pair<int, int>>> q;
        int currentLevel = 0, currentPosition = 0, currentIndent = canvasWidth / 4;
        q.push(make_pair(node, make_pair(currentLevel, canvasWidth / 2)));

        while (q.size() > 0)
        {
            pair<AVLTreeNode<T> *, pair<int, int>> nodeInfo = q.front();
            AVLTreeNode<T> *nodeBuffer = nodeInfo.first;
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
                currentPosition += 1;
            }

            if (nodeBuffer == nullptr)
                cout << setw(dataWidth) << nullValue;
            else
            {
                auto l = nodeBuffer->Left;
                auto r = nodeBuffer->Right;

                if (l != nullptr || r != nullptr)
                {
                    int futureLevel = level + 1;
                    q.push(make_pair(l, make_pair(futureLevel, position - currentIndent)));
                    q.push(make_pair(r, make_pair(futureLevel, position + currentIndent - dataWidth)));
                }

                cout << setw(dataWidth) << nodeBuffer->Value;
            }
        }

        cout << "\n";
    }

    static AVLTreeNode<T> *RotateLeft(AVLTreeNode<T> *node)
    {
        // TODO: this
    }

    static AVLTreeNode<T> *RotateRight(AVLTreeNode<T> *node)
    {
        // TODO: this
    }

    static AVLTreeNode<T> *Balance(AVLTreeNode<T> *node)
    {
        // TODO: this
    }

    void Delete(T value)
    {
        AVLTreeNode<T> **nodeBuffer = &Root;

        // TODO: add balancing

        while (nodeBuffer != nullptr)
        {
            AVLTreeNode<T> **leftBuffer = &((*nodeBuffer)->Left);
            AVLTreeNode<T> **rightBuffer = &((*nodeBuffer)->Right);
            bool isMore = value > (*nodeBuffer)->Value;

            if ((*nodeBuffer)->Value == value)
            {
                bool isRight = *rightBuffer != nullptr;
                bool isLeft = *leftBuffer != nullptr;
                bool areBothChildren = isRight && isLeft;
                if (areBothChildren)
                {
                    AVLTreeNode<T> **rl = &((*rightBuffer)->Left);
                    if (*rl == nullptr)
                    {
                        (*nodeBuffer)->Value = (*rightBuffer)->Value;
                        AVLTreeNode<T>::SetNew(*rightBuffer, nullptr);
                    }
                    else
                    {
                        while ((*rl)->Left != nullptr)
                            rl = &((*rl)->Left);
                        (*nodeBuffer)->Value = (*rl)->Value;
                        AVLTreeNode<T>::SetNew(*rl, (*rl)->Right);
                        AVLTreeNode<T>::SetNew(*rl, nullptr);
                    }
                }
                else if (!isRight && !isLeft)
                    AVLTreeNode<T>::SetNew(*nodeBuffer, nullptr);
                else if (isRight)
                    AVLTreeNode<T>::SetNew(*nodeBuffer, *rightBuffer);
                else
                    AVLTreeNode<T>::SetNew(*nodeBuffer, *leftBuffer);

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

        stack<AVLTreeNode<T> *> s;
        int count = 1;
        s.push(Root);

        while (!s.empty())
        {
            AVLTreeNode<T> *nodeBuffer = s.top();
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

        stack<AVLTreeNode<T> *> s;
        int count = 0;
        s.push(Root);

        while (!s.empty())
        {
            AVLTreeNode<T> *nodeBuffer = s.top();
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

        stack<pair<AVLTreeNode<T> *, int>> s;
        s.push(make_pair(Root, 0));

        while (!s.empty())
        {
            pair<AVLTreeNode<T> *, int> bufferPair = s.top();
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

    ~AVLTree<T>()
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

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

    void PrintVertical(int dataWidth = 2, int canvasWidth = 64, string nullValue = "--")
    {
        queue<pair<BinarySearchTreeNode<T> *, int>> q;
        int currentLevel = 0, currentIndent = canvasWidth / 2;
        q.push(make_pair(Root, currentLevel));

        while (q.size() > 0)
        {
            pair<BinarySearchTreeNode<T> *, int> nodeInfo = q.front();
            BinarySearchTreeNode<T> *node = nodeInfo.first;
            int level = nodeInfo.second;
            bool isNewLevel = currentLevel < level;
            q.pop();

            if (isNewLevel)
            {
                currentLevel = level;
                cout << "\n";
            }

            int newLeveledIndent = (isNewLevel ? currentIndent / 2 : currentIndent) - dataWidth;

            for (int i = 0; i < newLeveledIndent; i++)
                cout << " ";

            if (q.size() > 0 && currentLevel < q.front().second)
                currentIndent /= 2;

            if (node == nullptr)
                cout << setw(dataWidth) << nullValue;
            else
            {
                auto l = node->Left;
                auto r = node->Right;

                if (l != nullptr || r != nullptr)
                {
                    int futureLevel = level + 1;
                    q.push(make_pair(l, futureLevel));
                    q.push(make_pair(r, futureLevel));
                }

                cout << setw(dataWidth) << node->Value;
            }
        }

        cout << "\n";
    }

    void Delete(T value)
    {
        BinarySearchTreeNode<T> *&node = Root;

        while (node != nullptr)
        {
            BinarySearchTreeNode<T> *&l = node->Left;
            BinarySearchTreeNode<T> *&r = node->Right;
            bool isMore = value > node->Value;

            if (node->Value == value)
            {
                delete node;

                bool isRight = r != nullptr;
                bool isLeft = l != nullptr;
                bool areBothChildren = isRight && isLeft;
                if (areBothChildren)
                {
                    BinarySearchTreeNode<T> *&rl = r->Left;
                    if (rl == nullptr)
                        node = r;
                    else
                    {
                        while (rl->Left != nullptr)
                            rl = rl->Left;
                        node->Value = rl->Value;
                        r->Left = rl->Right;
                        delete rl;
                    }
                }
                else if (!isRight && !isLeft)
                    node = nullptr;
                else if (isRight)
                    node = r;
                else
                    node = l;

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
            Root->DisposeChildren();
            delete Root;
            Root = nullptr;
        }
    }

    string ToString()
    {
        return "Root: [" + (Root == nullptr ? "NULL" : Root->ToString()) + "]";
    }

    static BinarySearchTree<int> GetFilledIntegerTree()
    {
        int counter = 1;
        queue<BinarySearchTreeNode<int> *> q;
        BinarySearchTreeNode<int> *root = new BinarySearchTreeNode<int>(0);
        q.push(root);
        for (int i = 0; i < 7; i++)
        {
            BinarySearchTreeNode<int> *node = q.front();
            q.pop();
            BinarySearchTreeNode<int> *l = new BinarySearchTreeNode<int>(counter);
            node->Left = l;
            q.push(l);
            counter++;
            BinarySearchTreeNode<int> *r = new BinarySearchTreeNode<int>(counter);
            node->Right = r;
            q.push(r);
            counter++;
        }

        return BinarySearchTree<int>(root);
    }
};

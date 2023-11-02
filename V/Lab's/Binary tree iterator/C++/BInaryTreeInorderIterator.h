#include "BinarySearchTree.h"
#include <stack>

using namespace std;

template <typename T>
class BinaryTreeInorderIterator
{
private:
    BinarySearchTree<T> *_tree;
    BinaryTreeNode<T> *_current;
    stack<BinaryTreeNode<T> *> _history;

public:
    BinaryTreeInorderIterator(BinarySearchTree<T> *tree)
    {
        _tree = tree;
        Reset();
    }

    void SetBinarySearchTree(BinarySearchTree<T> *tree)
    {
        _tree = tree;
        Reset();
    }

    void Next()
    {
        if (IsIterationComplete())
            return;

        _current = _history.top();
        _history.pop();
        
        if (_current == nullptr)
            return;

        BinaryTreeNode<T> *bufferNode = _current->Right;

        while (bufferNode != nullptr)
        {
            _history.push(bufferNode);
            bufferNode = bufferNode->Left;
        }
    }

    void Reset()
    {
        while (!_history.empty())
            _history.pop();

        _history.push(nullptr);

        _current = _tree->Root;
        while (_current->Left != nullptr)
        {
            _history.push(_current);
            _current = _current->Left;
        }
    }

    BinaryTreeNode<T> *GetCurrentElement()
    {
        return _current;
    }

    T GetCurrentElementValue()
    {
        if (_current == nullptr)
            throw "Current pointer is null";
        return _current->Value;
    }

    bool TryGetCurrentElementValue(T &outValue)
    {
        if (_current == nullptr)
            return false;

        outValue = _current->Value;
        return true;
    }

    void SetCurrendElementValue(T value)
    {
        if (_current == nullptr)
            return;

        _current->Value = value;
    }

    bool IsIterationComplete()
    {
        return _history.empty();
    }
};
#include "BinarySearchTree.h"
#include <stack>

using namespace std;

/// <summary>
/// Binary tree iterator
/// </summary>
/// <typeparam name="T">Tree nodes value type</typeparam>
template <typename T>
class BinaryTreeInorderIterator
{
private:
    /// <summary>
    /// Pointer to tree that are we iterating
    /// </summary>
    BinarySearchTree<T> *_tree;
    /// <summary>
    /// Current tree node
    /// </summary>
    BinaryTreeNode<T> *_current;

public:
    /// @brief Initialize new binary search tree iterator
    /// @param tree Tree pointer for initializing tree iterator
    BinaryTreeInorderIterator(BinarySearchTree<T> *tree)
    {
        SetBinarySearchTree(tree);
    }

    /// <summary>
    /// Set new tree pointer for future tree iteration
    /// </summary>
    /// <param name="tree">- New tree pointer</param>
    void SetBinarySearchTree(BinarySearchTree<T> *tree)
    {
        _tree = tree;
        Reset();
    }

    /// <summary>
    /// Move to next tree node
    /// </summary>
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

    /// <summary>
    /// Move to first tree node
    /// </summary>
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

    /// <summary>
    /// Get current tree node
    /// </summary>
    /// <returns>Current tree node</returns>
    BinaryTreeNode<T> *GetCurrentElement()
    {
        return _current;
    }

    /// <summary>
    /// Get current tree node value
    /// </summary>
    /// <returns>Current tree node value</returns>
    T GetCurrentElementValue()
    {
        if (_current == nullptr)
            throw "Current pointer is null";
        return _current->Value;
    }

    /// <summary>
    /// Try to get current tree node value
    /// </summary>
    /// <param name="outValue">- Getted current tree value output</param>
    /// <returns><c>True</c> - if getting was success; <c>False</c> - otherside</returns>
    bool TryGetCurrentElementValue(T &outValue)
    {
        if (_current == nullptr)
            return false;

        outValue = _current->Value;
        return true;
    }

    /// <summary>
    /// Set new value for tree current node
    /// </summary>
    /// <param name="value">- New value for tree current node</param>
    void SetCurrendElementValue(T value)
    {
        if (_current == nullptr)
            return;

        _current->Value = value;
    }

    /// <summary>
    /// Examinate tree iteration competition (Passed the last tree node)
    /// </summary>
    /// <returns><c>True</c> - if tree iteration is complete; <c>False</c> - otherside</returns>
    bool IsIterationComplete()
    {
        return _history.empty();
    }
};
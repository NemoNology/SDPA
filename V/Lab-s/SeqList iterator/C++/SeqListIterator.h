#include "SeqList.h"

using namespace std;

/// <summary>
/// SeqList iterator
/// </summary>
/// <typeparam name="T">List nodes value type</typeparam>
template <typename T>
class SeqListIterator
{
private:
    /// <summary>
    /// List that are we iterating
    /// </summary>
    SeqList<T> *_list;
    /// <summary>
    /// Current list node
    /// </summary>
    SeqListNode<T> *_current;

public:
    /// @brief Initialize new seqList iterator
    /// @param root seqList pointer for initializing iterator
    SeqListIterator(SeqList<T> *list)
    {
        _list = list;
        Reset();
    }

    /// <summary>
    /// Set new list pointer for future list iteration
    /// </summary>
    /// <param name="tree">- New list pointer</param>
    void SetSeqList(SeqList<T> *list)
    {
        _list = list;
        Reset();
    }

    /// <summary>
    /// Move to next list node
    /// </summary>
    void Next()
    {
        if (IsIterationComplete())
            return;

        _current = _current->Next;
    }

    /// <summary>
    /// Move to first list node
    /// </summary>
    void Reset()
    {
        _current = _list->Head;
    }

    /// <summary>
    /// Get current list node
    /// </summary>
    /// <returns>Current list node</returns>
    SeqListNode<T> *GetCurrentElement()
    {
        return _current;
    }

    /// <summary>
    /// Get current list node value
    /// </summary>
    /// <returns>Current list node value</returns>
    T GetCurrentElementValue()
    {
        if (_current == nullptr)
            throw "Current pointer is null";
        return _current->Value;
    }

    /// <summary>
    /// Try to get current list node value
    /// </summary>
    /// <param name="outValue">- Getted current list value output</param>
    /// <returns><c>True</c> - if getting was success; <c>False</c> - otherside</returns>
    bool TryGetCurrentElementValue(T &outValue)
    {
        if (_current == nullptr)
            return false;

        outValue = _current->Value;
        return true;
    }

    /// <summary>
    /// Set new value for list current node
    /// </summary>
    /// <param name="value">- New value for list current node</param>
    void SetCurrendElementValue(T value)
    {
        if (_current == nullptr)
            return;

        _current->Value = value;
    }

    /// <summary>
    /// Examinate list iteration competition (Passed the last list node)
    /// </summary>
    /// <returns><c>True</c> - if list iteration is complete; <c>False</c> - otherside</returns>
    bool IsIterationComplete()
    {
        return _current == nullptr;
    }
};
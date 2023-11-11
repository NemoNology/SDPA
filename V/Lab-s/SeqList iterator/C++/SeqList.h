#include "SeqListNode.h"
#include <iostream>

using namespace std;

/// <summary>
/// SeqList
/// </summary>
/// <typeparam name="T">List node value type</typeparam>
template <typename T>
class SeqList
{
private:
    /// @brief SeqList nodes amount
    int _size = 0;

public:
    /// <summary>
    /// Pointer to list head (start)
    /// </summary>
    SeqListNode<T> *Head;

    /// @brief Initialize new seqList
    /// @param root Head pointer
    SeqList(SeqListNode<T> *head = nullptr)
    {
        Head = head;
    }

    /// <summary>
    /// Calculate list size
    /// </summary>
    /// <returns>List size</returns>
    int GetSize()
    {
        return _size;
    }

    /// <summary>
    /// Examinate if list is empty
    /// </summary>
    /// <returns><c>True</c> - if list is empty; <c>False</c> - otherside</returns>
    bool isEmpty()
    {
        return Head == nullptr;
    }

    /// <summary>
    /// Insert node with inputted value to list the end
    /// </summary>
    /// <param name="value">- Inserting value</param>
    void Append(T value)
    {
        SeqListNode<T> *appendedNode = new SeqListNode<T>(value);
        _size++;

        if (Head == nullptr)
        {
            Head = appendedNode;
            return;
        }

        SeqListNode<T> *nodeBuffer = Head;

        while (nodeBuffer->Next != nullptr)
            nodeBuffer = nodeBuffer->Next;

        nodeBuffer->Next = appendedNode;
    }

    /// <summary>
    /// Remove the last element from list
    /// </summary>
    /// <returns>Removed the last element</returns>
    T Pop()
    {
        if (Head == nullptr)
            throw "Trying to pop from empty seqList";

        SeqListNode<T> *nodeBuffer = Head;
        SeqListNode<T> *prevBuffer = Head;

        while (nodeBuffer->Next != nullptr)
        {
            prevBuffer = nodeBuffer;
            nodeBuffer = nodeBuffer->Next;
        }

        prevBuffer->Next = nullptr;
        T value = nodeBuffer->Value;
        delete nodeBuffer;
        _size--;
        return value;
    }

    /// <summary>
    /// Try to remove the last element of list
    /// </summary>
    /// <param name="outValue">- Removed the last element out value</param>
    /// <returns><c>True</c> - if try was successful; <c>False</c> - otherside</returns>
    bool TryPop(T &outValue)
    {
        if (Head == nullptr)
            return false;

        // **nodebuffer = &Head;
        SeqListNode<T> *nodeBuffer = Head;
        SeqListNode<T> *prevBuffer = Head;

        while (nodeBuffer->Next != nullptr)
        {
            prevBuffer = nodeBuffer;
            nodeBuffer = nodeBuffer->Next;
        }

        prevBuffer->Next = nullptr;

        _size--;
        outValue = nodeBuffer->Value;
        return true;
    }

    /// <summary>
    /// Remove the first element from list
    /// </summary>
    /// <returns>Removed the last element</returns>
    T Dequeue()
    {
        if (Head == nullptr)
            throw "Trying to dequeue from empty seqList";

        T value = Head->Value;
        SeqListNode<T> *nextBuffer = Head->Next;
        delete Head;
        Head = nextBuffer;
        _size--;
        return value;
    }

    /// <summary>
    /// Try to remove the first element of list
    /// </summary>
    /// <param name="outValue">- Removed the first element out value</param>
    /// <returns><c>True</c> - if try was successful; <c>False</c> - otherside</returns>
    bool TryDequeue(T &outValue)
    {
        if (Head == nullptr)
            return false;

        outValue = Head->Value;
        SeqListNode<T> *nextBuffer = Head->Next;
        delete Head;
        Head = nextBuffer;
        _size--;
        return true;
    }

    /// <summary>
    /// Clear all elements with memory free
    /// </summary>
    void Clear()
    {
        SeqListNode<T> *nodeBuffer = Head;

        while (nodeBuffer != nullptr)
        {
            nodeBuffer = nodeBuffer->Next;
            delete nodeBuffer->Previous;
        }

        Head = nullptr;
    }

    /// <summary>
    /// Count all list elements
    /// </summary>
    /// <returns>List elements amount</returns>
    int Count()
    {
        if (Head == nullptr)
            return 0;

        SeqListNode<T> *nodeBuffer = Head;
        int counter = 0;

        while (nodeBuffer->Next != nullptr)
        {
            counter++;
            nodeBuffer = nodeBuffer->Next;
        }

        return counter + 1;
    }

    /// <summary>
    /// Return list element by index
    /// </summary>
    /// <param name="index">- Index of outputed element</param>
    /// <returns>Element by index</returns>
    T GetElementAt(int index)
    {
        if (index >= _size)
            throw "Index (" + to_string(index) + ") was out of array size(" + to_string(_size) + ")";

        SeqListNode<T> *nodeBuffer = Head;
        int counter = 0;

        while (counter != index)
        {
            nodeBuffer = nodeBuffer->Next;
            counter++;
        }

        return nodeBuffer->Value;
    }

    /// <summary>
    /// Try to get element by index
    /// </summary>
    /// <param name="index">- Index of outputed element</param>
    /// <param name="outElement">- - Outputed element out value</param>
    /// <returns><c>True</c> - if try was successful; <c>False</c> - otherside</returns>
    bool TryGetElementAt(int index, int &outElement)
    {
        if (index >= _size)
            return false;

        SeqListNode<T> *nodeBuffer = Head;
        int counter = 0;

        while (counter != index)
        {
            nodeBuffer = nodeBuffer->Next;
            counter++;
        }

        outElement = nodeBuffer->Value;
        return true;
    }
};
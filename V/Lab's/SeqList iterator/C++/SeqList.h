#include "SeqListNode.h"
#include <iostream>

using namespace std;

template <typename T>
class SeqList
{
private:
    int _size = 0;

public:
    SeqListNode<T> *Head;

    SeqList(SeqListNode<T> *head = nullptr)
    {
        Head = head;
    }

    int size()
    {
        return _size;
    }

    bool isEmpty()
    {
        return Head == nullptr;
    }

    void Append(T value)
    {
        SeqListNode<T> *appendedNode = new SeqListNode<T>(value);

        if (Head == nullptr)
        {
            Head = appendedNode;
            return;
        }

        SeqListNode<T> *nodeBuffer = Head;

        while (nodeBuffer->Next != nullptr)
            nodeBuffer = nodeBuffer->Next;

        nodeBuffer->Next = appendedNode;
        appendedNode->Previous = nodeBuffer;
        ++_size;
    }

    // Remove last element from seqList and return it
    SeqListNode<T> *Pop()
    {
        if (Head == nullptr)
            return nullptr;

        SeqListNode<T> *nodeBuffer = Head;

        while (nodeBuffer->Next != nullptr)
            nodeBuffer = nodeBuffer->Next;

        if (_size > 1)
            nodeBuffer->Previous->Next = nullptr;
        nodeBuffer->Previous = nullptr;

        --_size;
        return nodeBuffer;
    }

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
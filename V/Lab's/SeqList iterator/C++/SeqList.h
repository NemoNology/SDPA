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
        _size++;
    }

    // Remove last element from seqList and return it
    SeqListNode<T> *Pop()
    {
        if (Head == nullptr)
            return nullptr;
        else if (Head->Next == nullptr)
        {
            SeqListNode<T> *nodeBuffer = Head;
            Head = nullptr;
            return nodeBuffer;
        }

        SeqListNode<T> *nodeBuffer = Head;
        SeqListNode<T> *prevBuffer;

        while (nodeBuffer->Next != nullptr)
        {
            prevBuffer = nodeBuffer;
            nodeBuffer = nodeBuffer->Next;
        }

        prevBuffer->Next = nullptr;

        _size--;
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
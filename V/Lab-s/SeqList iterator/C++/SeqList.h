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

    int GetSize()
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

    // Remove last element from seqList and return it
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
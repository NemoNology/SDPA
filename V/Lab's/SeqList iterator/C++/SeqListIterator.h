#include "SeqList.h"

using namespace std;

template <typename T>
class SeqListIterator
{
private:
    SeqList<T> *_list;
    SeqListNode<T> *_current;

public:
    SeqListIterator(SeqList<T> *list)
    {
        _list = list;
        Reset();
    }

    void SetSeqList(SeqList<T> *list)
    {
        _list = list;
        Reset();
    }

    void Next()
    {
        if (IsIterationComplete())
            return;

        _current = _current->Next;
    }

    void Reset()
    {
        _current = _list->Head;
    }

    SeqListNode<T> *GetCurrentElement()
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
        return _current == nullptr;
    }
};
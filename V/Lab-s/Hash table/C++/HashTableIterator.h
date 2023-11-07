#pragma once
#include "HashTable.h"
#include <vector>

using namespace std;

template <typename T>
class HashTableIterator
{
private:
    HashTable<T> *_table;
    vector<T> _tableValues;
    int _counter;

public:
    HashTableIterator(HashTable<T> *hashTable)
    {
        _table = hashTable;
        Reset();
    }

    T GetCurrent()
    {
        if (IsIterationComplete())
            throw "Index out of range: current value is not valid (Table is null or iteration is completed)";

        return _tableValues[_counter];
    }

    bool TryGetCurrent(T &outValue)
    {
        if (IsIterationComplete())
            return false;

        outValue = _tableValues[_counter];
        return true;
    }

    void Reset()
    {
        if (_table == nullptr || _table->GetSize() == 0)
        {
            _counter = 0;
            _tableValues = vector<T>();
            return;
        }

        _tableValues = _table->GetValues();
        _counter = 0;
    }

    void Next()
    {
        if (IsIterationComplete())
            return;

        _counter += 1;
    }

    bool IsIterationComplete()
    {
        return _table == nullptr || _counter >= _table->GetSize();
    }
};

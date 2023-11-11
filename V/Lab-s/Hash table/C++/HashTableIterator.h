#pragma once
#include "HashTable.h"
#include <vector>

using namespace std;

/// @brief Hash table iterator
/// @tparam ValueType Hash table values type
template <typename T>
class HashTableIterator
{
private:
    /// @brief Pointer to hash table that are we iterating
    HashTable<T> *_table;
    /// @brief Values of hash table
    vector<T> _tableValues;
    /// @brief Counter for iteration - Passed elements amount
    int _counter;

public:
    /// @brief Initialize new hash table iterator
    /// @param hashTable Hash table pointer for initializing table iterator
    HashTableIterator(HashTable<T> *hashTable)
    {
        SetHashTable(hashTable);
    }

    /// @brief Set hash table pointer for future table iteration
    /// @param hashTable Hash table pointer for table iterator
    void SetHashTable(HashTable<T> *hashTable)
    {
        _table = hashTable;
        Reset();
    }

    /// @brief Get current table element value
    /// @return Current table element value
    T GetCurrent()
    {
        if (IsIterationComplete())
            throw "Index out of range: current value is not valid (Table is null or iteration is completed)";

        return _tableValues[_counter];
    }

    /// @brief Try to get current table element value
    /// @param outValue Getted current table element value
    /// @return True - if getting was success; False - otherside
    bool TryGetCurrent(T &outValue)
    {
        if (IsIterationComplete())
            return false;

        outValue = _tableValues[_counter];
        return true;
    }

    /// @brief Move to first table element
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

    /// @brief Move to next table element
    void Next()
    {
        if (IsIterationComplete())
            return;

        _counter += 1;
    }

    /// @brief Examinate table iteration competition (Passed the last table element)
    /// @return True - if tree iteration is complete; False - otherside
    bool IsIterationComplete()
    {
        return _table == nullptr || _counter >= _table->GetSize();
    }
};

#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

// template <typename KeyT, typename ValueT>
template <typename ValueType>
class HashTableWithoutCollisionsResolving
{
private:
    int (*_hashFunction)(string, int);
    int _capacity;
    int _size = 0;
    ValueType **_data = nullptr;

    int GetHash(string key)
    {
        return _hashFunction(key, 0) % _capacity;
    }

public:
    HashTableWithoutCollisionsResolving(int capacity, int (*hashFunction)(string, int))
    {
        if (hashFunction == nullptr)
            throw "Hash function must be initialized\n";
        _capacity = capacity;
        _hashFunction = hashFunction;
        _data = new ValueType *[capacity];

        for (int i = 0; i < capacity; i += 1)
            _data[i] = nullptr;
    }

    /// @brief Set value in hash table
    /// @param value New value
    void SetValue(string key, ValueType value)
    {
        if (_data == nullptr)
            return;
        int index = _hashFunction(key, 0) % _capacity;
        if (_data[index] != nullptr)
            delete _data[index];
        else
            _size += 1;

        _data[index] = new ValueType(value);
    }

    void Delete(string key)
    {
        if (_data == nullptr)
            return;
        int index = GetHash(key);
        if (_data[index] != nullptr)
        {
            delete _data[index];
            _data[index] = nullptr;
            _size -= 1;
        }
    }

    ValueType Find(string key)
    {
        if (_data == nullptr)
            throw "Hash table is not initialized";
        int index = GetHash(key);
        if (_data[index] == nullptr)
            throw "Hash table does not contains " + key;
        return *_data[index];
    }

    bool TryFind(string key, ValueType &outValue)
    {
        if (_data == nullptr)
            return false;
        int index = GetHash(key);
        if (_data[index] == nullptr)
            return false;
        outValue = (*_data[index]);
        return true;
    }

    bool Contains(string key)
    {
        if (_data == nullptr)
            return false;
        if (_data[GetHash(key)] == nullptr)
            return false;
        return true;
    }

    vector<ValueType> GetValues()
    {
        vector<ValueType> values = vector<ValueType>(_size);
        int counter = 0;
        for (int i = 0; i < _capacity; i++)
            if (_data[i] != nullptr)
            {
                values[counter] = (*_data[i]);
                counter += 1;
            }
        return values;
    }

    operator[](string key)
    {
        return Find(key);
    }

    ~HashTableWithoutCollisionsResolving()
    {
        Clear();
        if (_data != nullptr)
        {
            delete[] _data;
            _data = nullptr;
        }
    }

    void Clear()
    {
        if (_data != nullptr)
        {
            for (int i = 0; i < _capacity; i++)
                if (_data[i] != nullptr)
                    delete _data[i];
        }

        _size = 0;
    }
};
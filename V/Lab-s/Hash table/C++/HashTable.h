#pragma once
#include <string>
#include <vector>
#include <stack>
#include "SeqListNode.h"

using namespace std;

/// @brief Hash table
/// @tparam ValueType Hash table values type
template <typename ValueType>
class HashTable
{
private:
    /// @brief Pointer to hash functioon
    int (*_hashFunction)(string, int);
    /// @brief Hash table capacity
    int _capacity;
    /// @brief Amount of hash table (not empty) elements
    int _size;
    SeqListNode<pair<string, ValueType>> **_data = nullptr;

    int GetHash(string key)
    {
        return _hashFunction(key, 0) % _capacity;
    }

public:
    /// @brief Initialize new hash table
    /// @param capacity Capacity (max size) for hash table
    /// @param hashFunction Hash function pointer for hash table
    HashTable(int capacity, int (*hashFunction)(string, int))
    {
        if (hashFunction == nullptr)
            throw "Hash function must be initialized\n";
        _capacity = capacity;
        _size = 0;
        _hashFunction = hashFunction;
        _data = new SeqListNode<pair<string, ValueType>> *[capacity];

        for (int i = 0; i < capacity; i += 1)
            _data[i] = nullptr;
    }

    /// @brief Set value in hash table
    /// @param value New value
    void SetValue(string key, ValueType value)
    {
        if (_data == nullptr || _size >= _capacity)
            return;
        SeqListNode<pair<string, ValueType>> *addingNode =
            new SeqListNode<pair<string, ValueType>>(make_pair(key, value));
        int index = _hashFunction(key, 0) % _capacity;
        if (_data[index] != nullptr)
        {
            SeqListNode<pair<string, ValueType>> *nodeBuffer = _data[index];
            while (nodeBuffer->Next != nullptr)
                nodeBuffer = nodeBuffer->Next;
            nodeBuffer->Next = addingNode;
        }
        else
            _data[index] = addingNode;

        _size += 1;
    }

    /// @brief Remove value from table by specified key
    /// @param key Key for specified value 
    void Delete(string key)
    {
        if (_data == nullptr)
            return;
        int index = GetHash(key);
        if (_data[index] != nullptr)
        {
            SeqListNode<pair<string, ValueType>> *nodeBuffer = _data[index];
            SeqListNode<pair<string, ValueType>> *nodeParentBuffer = _data[index];
            while (nodeBuffer->Value.first == key || nodeBuffer->Next != nullptr)
            {
                nodeParentBuffer = nodeBuffer;
                nodeBuffer = nodeBuffer->Next;
            }

            if (nodeBuffer == nullptr)
                return;

            nodeParentBuffer->Next = nodeBuffer->Next;
            delete nodeBuffer;
            _size -= 1;
        }
    }

    /// @return Capacity (Max size) of table
    int GetCapacity()
    {
        return _capacity;
    }

    /// @return Table (not empty) elements amount
    int GetSize()
    {
        return _size;
    }

    /// @brief Find value by specified key
    /// @param key Key that must bring to specified value in table
    /// @return Value by specified key 
    ValueType Find(string key)
    {
        if (_data == nullptr)
            throw "Hash table is not initialized";
        int index = GetHash(key);
        if (_data[index] == nullptr)
            throw "Hash table does not contains " + key;
        SeqListNode<pair<string, ValueType>> *nodeBuffer = _data[index];
        while (nodeBuffer != nullptr)
        {
            if (nodeBuffer->Value.first == key)
                return nodeBuffer->Value.second;
            nodeBuffer = nodeBuffer->Next;
        }
        throw "Hash table does not contains " + key;
    }

    /// @brief Try to find value by key
    /// @param key Key that must bring to specified value in table
    /// @param outValue Found value by specified key
    /// @return True - if try was successfull; False - otherside
    bool TryFind(string key, ValueType &outValue)
    {
        if (_data == nullptr)
            return false;
        int index = GetHash(key);
        if (_data[index] == nullptr)
            return false;
        SeqListNode<pair<string, ValueType>> *nodeBuffer = _data[index];
        while (nodeBuffer != nullptr)
        {
            if (nodeBuffer->Value.first == key)
            {
                outValue = nodeBuffer->Value.second;
                return true;
            }
            nodeBuffer = nodeBuffer->Next;
        }

        return false;
    }

    /// @brief Examinate if table contains value by specified key
    /// @param key Key that must bring to specified value in table
    /// @return True - if table contains value by specified key; False - otherside
    bool Contains(string key)
    {
        if (_data == nullptr)
            return false;
        int index = GetHash(key);
        if (_data[index] == nullptr)
            return false;
        SeqListNode<pair<string, ValueType>> *nodeBuffer = _data[index];
        while (nodeBuffer->Value.first == key || nodeBuffer->Next != nullptr)
            nodeBuffer = nodeBuffer->Next;

        if (nodeBuffer == nullptr)
            return false;
        return true;
    }

    /// @brief Return all table values
    /// @return All table values
    vector<ValueType> GetValues()
    {
        vector<ValueType> values = vector<ValueType>(_size);
        SeqListNode<pair<string, ValueType>> *nodeBuffer;
        int counter = 0;
        for (int i = 0; i < _capacity; i++)
            if (_data[i] != nullptr)
            {
                nodeBuffer = _data[i];
                while (nodeBuffer != nullptr)
                {
                    values[counter] = nodeBuffer->Value.second;
                    counter += 1;
                    nodeBuffer = nodeBuffer->Next;
                }
            }
        return values;
    }

    /// @brief Return all table keys
    /// @return All table keys
    vector<string> GetKeys()
    {
        vector<string> values = vector<string>(_size);
        SeqListNode<pair<string, ValueType>> *nodeBuffer;
        int counter = 0;
        for (int i = 0; i < _capacity; i++)
            if (_data[i] != nullptr)
            {
                nodeBuffer = _data[i];
                while (nodeBuffer != nullptr)
                {
                    values[counter] = nodeBuffer->Value.first;
                    counter += 1;
                    nodeBuffer = nodeBuffer->Next;
                }
            }
        return values;
    }

    /// @brief Get value by specified key
    /// @param key Key that must bring to specified value in table
    /// @return Value by specified key 
    ValueType operator[](string key)
    {
        return Find(key);
    }

    ~HashTable()
    {
        Clear();
        if (_data != nullptr)
        {
            delete[] _data;
            _data = nullptr;
        }
    }

    /// @brief Clear all table data with memory free 
    void Clear()
    {
        if (_data != nullptr)
        {
            for (int i = 0; i < _capacity; i++)
                if (_data[i] != nullptr)
                {
                    delete _data[i];
                    _data[i] = nullptr;
                }
        }

        _size = 0;
    }
};
#pragma once
#include <string>
#include <vector>
#include <stack>
#include "SeqListNode.h"

using namespace std;

// template <typename KeyT, typename ValueT>
template <typename ValueType>
class HashTable
{
private:
    int (*_hashFunction)(string, int);
    int _capacity;
    int _size;
    SeqListNode<pair<string, ValueType>> **_data = nullptr;

    int GetHash(string key)
    {
        return _hashFunction(key, 0) % _capacity;
    }

public:
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

    int GetCapacity()
    {
        return _capacity;
    }

    int GetSize()
    {
        return _size;
    }

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
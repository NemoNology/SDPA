using namespace std;

/// <summary>
/// Heap
/// </summary>
/// <typeparam name="T">Node value type</typeparam>
template <typename T>
class Heap
{
private:
    /// <summary>
    /// Data array pointer
    /// </summary>
    T *_data;
    /// @brief Heap capacity (max size)
    int _capacity;
    /// @brief Heap elements amount
    int _size;

public:
    /// <summary>
    /// Initialize new heap with inputted capacity
    /// </summary>
    /// <param name="capacity">- Heap capacity</param>
    Heap(int capacity)
    {
        _capacity = capacity;
        _size = 0;
        _data = new T[_capacity];
    }

    /// <summary>
    /// Initialize new heap and add elements to it from inputted array
    /// </summary>
    /// <param name="capacity">- Inputting array</param>
    Heap(T arr[])
    {
        int soe = sizeof(T);
        int fs = sizeof(arr);
        _capacity = _size = fs / soe;
        _data = new T[_size];
        for (int i = 0; i < _size; i++)
            Insert(arr[i]);
    }

    /// <summary>
    /// Add new value with inputted value at the end into heap
    /// </summary>
    /// <param name="value">- Inputted value</param>
    void Insert(T value)
    {
        if (_size == _capacity)
            return;
        else if (_size == 0)
        {
            _data[_size++] = value;
            return;
        }

        _data[_size] = value;
        int parendIndex = (_size - 1) / 2;

        while (parendIndex > 0)
        {
            Filter(parendIndex);
            parendIndex = (parendIndex - 1) / 2;
        }

        Filter(parendIndex);
        _size += 1;
    }

    /// <summary>
    /// Removed max (Heap head) value from heap and balance heap
    /// </summary>
    void RemoveMax()
    {
        if (_size == 0)
            return;

        _data[0] = _data[_size];
        int modifiedChildIndex = Filter(0);

        while (modifiedChildIndex > 0)
            modifiedChildIndex = Filter(modifiedChildIndex);

        _size -= 1;
    }

    /// <summary>
    /// Balance heap node
    /// </summary>
    /// <param name="parentIndex">- Balancing heap node index</param>
    /// <returns>Changed heap node index</returns>
    int Filter(int parentIndex)
    {
        if (_size < parentIndex)
            return -1;

        T parentValue = _data[parentIndex];
        int childOneIndex = 1 + 2 * parentIndex;
        if (_size < childOneIndex)
            return -1;
        else if (_size == childOneIndex)
        {
            T valueBuffer = _data[childOneIndex];
            if (valueBuffer > parentValue)
            {
                _data[childOneIndex] = parentValue;
                _data[parentIndex] = valueBuffer;
                return childOneIndex;
            }
        }
        else
        {
            bool isChildOneValueMoreThanChildTwoValue = _data[childOneIndex] > _data[childOneIndex + 1];
            T valueBuffer = isChildOneValueMoreThanChildTwoValue ? _data[childOneIndex] : _data[childOneIndex + 1];
            int indexBuffer = isChildOneValueMoreThanChildTwoValue ? childOneIndex : childOneIndex + 1;

            if (valueBuffer > parentValue)
            {
                _data[indexBuffer] = parentValue;
                _data[parentIndex] = valueBuffer;
                return indexBuffer;
            }
        }

        return -1;
    }

    /// <summary>
    /// Return max value
    /// </summary>
    /// <returns>Heap max value</returns>
    T GetMax()
    {
        if (_size < 1)
            throw "Index out of range";

        return _data[0];
    }

    /// <summary>
    /// Try get heap max value
    /// </summary>
    /// <param name="outValue">- Outputted heap max out value</param>
    /// <returns><c>True</c> - if getting was successful; <c>False</c> - otherside</returns>
    bool TryGetMax(T &outValue)
    {
        if (_size < 1)
            return false;

        outValue = _data[0];
        return true;
    }

    /// <summary>
    /// Return heap size
    /// </summary>
    /// <returns>Heap size</returns>
    int GetSize()
    {
        return _size;
    }

    /// <summary>
    /// Return heap capacity
    /// </summary>
    /// <returns>Heap capacity</returns>
    int GetCapacity()
    {
        return _capacity;
    }

    ~Heap()
    {
        Clear();
    }

    /// <summary>
    /// Clear heap values
    /// </summary>
    void Clear()
    {
        _size = _capacity = 0;
    }
};

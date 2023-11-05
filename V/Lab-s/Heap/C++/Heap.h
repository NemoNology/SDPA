using namespace std;

template <typename T>
class Heap
{
private:
    T *_data;
    int _capacity;
    int _size;

public:
    Heap(int capacity)
    {
        _capacity = capacity;
        _size = 0;
        _data = new T[_capacity];
    }

    Heap(T arr[])
    {
        int soe = sizeof(T);
        int fs = sizeof(arr);
        _capacity = _size = fs / soe;
        _data = new T[_size];
        for (int i = 0; i < _size; i++)
            Insert(arr[i]);
    }

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

    T GetMax()
    {
        if (_size < 1)
            throw "Index out of range";

        return _data[0];
    }

    bool TryGetMax(T &outValue)
    {
        if (_size < 1)
            return false;

        outValue = _data[0];
        return true;
    }

    int GetSize()
    {
        return _size;
    }

    int GetCapacity()
    {
        return _capacity;
    }

    ~Heap()
    {
        Clear();
    }

    void Clear()
    {
        if (_data != nullptr)
        {
            delete[] _data;
            _data = nullptr;
        }

        _size = _capacity = 0;
    }
};

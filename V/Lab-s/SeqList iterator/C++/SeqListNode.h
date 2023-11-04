using namespace std;

template <typename T>
class SeqListNode
{
public:
    T Value;

    SeqListNode<T> *Next;

    SeqListNode(T value, SeqListNode<T> *next = nullptr)
    {
        Value = value;
        Next = next;
    }
};
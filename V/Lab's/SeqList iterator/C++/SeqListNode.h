using namespace std;

template <typename T>
class SeqListNode
{
public:
    T Value;

    SeqListNode<T> *Next;
    SeqListNode<T> *Previous;

    SeqListNode(T value, SeqListNode<T> *next = nullptr, SeqListNode<T> *previous = nullptr)
    {
        Value = value;
        Next = next;
        Previous = previous;
    }
};
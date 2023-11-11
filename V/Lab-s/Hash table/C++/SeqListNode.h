using namespace std;

template <typename T>
class SeqListNode
{
public:
    T Value;

    /// @brief Pointer to next seqList node
    SeqListNode<T> *Next;

    /// @brief Initialize new seqList node
    /// @param value Value for current node
    /// @param next Pointer to next seqList node for current node
    SeqListNode(T value, SeqListNode<T> *next = nullptr)
    {
        Value = value;
        Next = next;
    }
};
using namespace std;

/// <summary>
/// SeqList node
/// </summary>
/// <typeparam name="T">Node value type</typeparam>
template <typename T>
class SeqListNode
{
public:
    T Value;

    /// <summary>
    /// Pointer to next node
    /// </summary>
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
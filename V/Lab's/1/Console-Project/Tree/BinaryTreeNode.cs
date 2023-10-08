public class BinaryTreeNode<T> : IDisposable
{
    public T Value;

    public BinaryTreeNode<T>? Left;
    public BinaryTreeNode<T>? Right;

    public BinaryTreeNode(T value, BinaryTreeNode<T>? left = null, BinaryTreeNode<T>? right = null)
    {
        Value = value;
        Left = left;
        Right = right;
    }

    ~BinaryTreeNode()
    {
        Dispose();
    }

    public void Dispose()
    {
        Stack<BinaryTreeNode<T>> nodes = new();
        if (Left is not null)
        {
            nodes.Push(Left);
        }
        if (Right is not null)
        {
            nodes.Push(Right);
        }

        while (nodes.Count > 0)
        {
            var node = nodes.Pop();

            if (node.Left is not null)
            {
                nodes.Push(node.Left);
            }
            if (node.Right is not null)
            {
                nodes.Push(node.Right);
            }

            GC.SuppressFinalize(node);
        }
    }
}

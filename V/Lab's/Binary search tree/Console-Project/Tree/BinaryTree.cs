namespace Console_Project.Tree
{
    public class BinaryTree<T> : IDisposable
    {
        public readonly BinaryTreeNode<T> Root;

        public BinaryTree(BinaryTreeNode<T> root)
        {
            Root = root;
        }

        ~BinaryTree()
        {
            Dispose();
        }

        public void Dispose() => Root.Dispose();
    }
}

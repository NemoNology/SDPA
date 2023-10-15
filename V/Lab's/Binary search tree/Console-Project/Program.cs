using Console_Project.Tree;

BinaryTreeNode<int> node = new(4, new(1), new(5));

System.Console.WriteLine(node);
node.Dispose();
System.Console.WriteLine(node);

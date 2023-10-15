#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

using type = int;
using TreeNode = BinarySearchTreeNode<type>;
using Tree = BinarySearchTree<type>;

int main()
{
    auto root = new TreeNode(4);
    auto tree = Tree(root);

    tree.Add(1);
    tree.Add(5);
    tree.Add(6);
    tree.Add(17);
    tree.Add(11);
    tree.Add(3);
    pair<int, float> test;

    // cout << "Leaf count: " << tree.CountLeaf() << endl;
    // cout << "Tree count: " << tree.Count() << endl;
    // cout << "Tree depth: " << tree.GetDepth() << endl;
    // cout << "Found node (11): " << tree.Find(11)->ToString() << endl;
    // cout << "Contains value 11 ? - " << boolalpha << tree.Contains(11) << endl;
    cout << "Found node (69): " << TreeNode::ToString(tree.Find(69)) << endl;

    system("pause");
    return 0;
}
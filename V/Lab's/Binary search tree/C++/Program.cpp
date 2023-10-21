#include <iostream>
#include "BinarySearchTree.h"
#include <time.h>

using namespace std;

using type = int;
using TreeNode = BinarySearchTreeNode<type>;
using Tree = BinarySearchTree<type>;

int GetRandomInteger(int max = 20)
{
    return rand() % max;
}

int main()
{
    srand((unsigned int)time(nullptr));

    auto root = new TreeNode(GetRandomInteger());
    auto tree = Tree(root);

    for (int i = 0; i < 10; i++)
        tree.Add(GetRandomInteger());

    cout << "Start:\n"; 
    tree.PrintVertical();
    // tree.PrintHorizontalRecursive(tree.Root);

    // for (int i = 0; i < 10; i++)
    // {
    //     cout << "Deleting " << i << "(look down) :\n";
    //     tree.Delete(i);
    //     tree.PrintHorizontalRecursive(tree.Root);
    // }

    // cout << "Found node (69): " << TreeNode::ToString(tree.Find(69)) << endl;

    system("pause");
    return 0;
}
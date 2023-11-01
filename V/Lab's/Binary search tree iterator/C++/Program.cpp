#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

using type = int;
using TreeNode = BinarySearchTreeNode<type>;
using Tree = BinarySearchTree<type>;

int main()
{
    Tree tree = Tree();

    int size = 15;
    int *numbers = new int[size]{50, 25, 75, 20, 30, 70, 80, 15, 23, 28, 40, 65, 72, 76, 85};

    for (int i = 0; i < size; i++)
        tree.Add(numbers[i]);

    cout << "Start:\n";
    tree.PrintVertical();

    system("pause");
    return 0;
}
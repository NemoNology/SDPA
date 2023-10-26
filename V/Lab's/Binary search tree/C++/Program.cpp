#include <iostream>
#include "BinarySearchTree.h"
#include <time.h>

using namespace std;

using type = int;
using TreeNode = BinarySearchTreeNode<type>;
using Tree = BinarySearchTree<type>;

int main()
{
    Tree tree = Tree();

    tree.Add(50);
    tree.Add(25);
    tree.Add(75);
    tree.Add(20);
    tree.Add(30);
    // cout << TreeNode::ToString(tree.Root) << " (Before)\n";
    tree.PrintVertical();
    // tree.Delete(0);
    // cout << TreeNode::ToString(tree.Root) << " (After)\n";
    // tree.PrintVertical();

    // int size = 15;
    // int *numbers = new int[size]{50, 25, 75, 20, 30, 70, 80, 15, 23, 28, 40, 65, 72, 76, 85};

    // for (int i = 0; i < size; i++)
    //     tree.Add(numbers[i]);

    // cout << "Start:\n";
    // tree.PrintVertical();

    // delete numbers;
    // size = 3;
    // numbers = new int[size]{65, 40, 15};

    // tree.Delete(65);
    // cout << "Delete 65:\n\n";
    // tree.PrintVertical();

    // for (int i = 0; i < size; i++)
    // {
    //     int delitingNumber = numbers[i];
    //     cout << "Delete " << delitingNumber << "(\\|/) :\n";
    //     tree.Delete(delitingNumber);
    //     tree.PrintVertical();
    // }

    system("pause");
    return 0;
}
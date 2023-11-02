#include <iostream>
#include <ctime>
#include "AVLTree.h"

using namespace std;

using type = int;
using TreeNode = AVLTreeNode<type>;
using Tree = AVLTree<type>;

// int GetRandomInt(int from, int to)
// {
//     return rand() % (to - from + 1) + from;
// }

int main()
{
    Tree tree = Tree();
    // srand(static_cast<unsigned int>(time(0)));

    // TODO: tests

    TreeNode *node = new TreeNode(2, 3, new TreeNode(1, 2, new TreeNode(0)));
    Tree::PrintVertical(node);
    cout << "Balanced: \n";
    // node->RotateRight();
    // Tree::PrintVertical(node);

    // int size = 15;
    // for (int i = 0; i < size; i++)
    // {
    //     cout << "Add " << i << "(\\|/) :\n";
    //     tree.Add(i);
    //     tree.PrintVertical();
    // }

    // cout << "Start:\n";
    // tree.PrintVertical();

    // size = 8;
    // numbers = new int[size]{76, 40, 15, 30, 20, 25, 28, 50};

    // cout << "\nDeleting test:\n\n";

    // for (int i = 0; i < size; i++)
    // {
    //     type delitingNumber = numbers[i];
    //     cout << "Delete " << delitingNumber << "(\\|/) :\n";
    //     tree.Delete(delitingNumber);
    //     tree.PrintVertical();
    // }

    // system("pause");
    return 0;
}
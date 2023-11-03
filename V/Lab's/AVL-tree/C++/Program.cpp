#include <iostream>
#include <ctime>
#include "AVLTree.h"

using namespace std;

using type = int;
using TreeNode = AVLTreeNode<type>;
using Tree = AVLTree<type>;

int main()
{
    Tree tree = Tree();

    int size = 15;
    for (int i = 0; i < size; i++)
        tree.Add(i);

    cout << "Start:\n";
    tree.PrintVertical();

    size += 3;
    type *numbers = new type[size]{4, 11, 3, 7, 13, 1, 10, 14, 0, 2, 5, 6, 99, 66, 121, 8, 9, 12};

    cout << "\nDeleting test:\n\n";

    for (int i = 0; i < size; i++)
    {
        type delitingNumber = numbers[i];
        cout << "Delete " << delitingNumber << "(\\|/) :\n";
        if (!tree.Contains(delitingNumber))
            cout << "(Tree doesn't contains " << delitingNumber << ")\n";
        tree.Delete(delitingNumber);
        tree.PrintVertical();
    }

    system("pause");
    return 0;
}
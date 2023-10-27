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
    delete numbers;
    size = 8;
    numbers = new int[size]{76, 40, 15, 30, 20, 25, 28, 50};

    cout << "\nContains test before deleting:\n\n";

    for (int i = 0; i < 100; i++)
        if (tree.Contains(i))
            cout << "Tree contains " << i << "\n";

    cout << "\nDeleting test:\n\n";

    for (int i = 0; i < size; i++)
    {
        int delitingNumber = numbers[i];
        cout << "Delete " << delitingNumber << "(\\|/) :\n";
        tree.Delete(delitingNumber);
        tree.PrintVertical();
    }

    cout << "\nContains test after deleting:\n\n";

    for (int i = 0; i < 100; i++)
        if (tree.Contains(i))
            cout << "Tree contains " << i << "\n";

    system("pause");
    return 0;
}
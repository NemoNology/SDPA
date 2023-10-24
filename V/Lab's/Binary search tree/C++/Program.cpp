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
    Tree tree = Tree();

    for (int i = 0; i < 11; i++)
        tree.Add(GetRandomInteger());

    cout << "Start:\n";
    tree.PrintVertical();
    int size = 3;

    for (int i = 0; i < size; i++)
    {
        int delitingNumber = GetRandomInteger();
        cout << "Delete " << delitingNumber << "(\\|/) :\n";
        tree.Delete(delitingNumber);
        tree.PrintVertical();
    }

    system("pause");
    return 0;
}
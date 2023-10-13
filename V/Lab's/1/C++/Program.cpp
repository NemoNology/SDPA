#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

using type = int;

int main()
{
    auto root = new BinarySearchTreeNode<type>(4);
    auto tree = BinarySearchTree<type>(root);

    tree.Add(1);
    tree.Add(5);
    tree.Add(6);

    for (int i = 0; i < 10; i++)
        cout << "Is there " << i << " in tree? - " << boolalpha << tree.Contains(i) << endl;

    // system("pause");
    return 0;
}
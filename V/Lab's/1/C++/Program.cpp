#include <iostream>
#include "BinaryTreeNode.h"

using namespace std;

using type = int;

int main()
{
    auto root = new BinaryTreeNode<type>(4, new BinaryTreeNode<type>(1), new BinaryTreeNode<type>(6));

    cout << "Root: " << root->toString() << endl;
    root->DisposeChildren();
    cout << "Root: " << root->toString() << endl;

    

    // system("pause");
    return 0;
}
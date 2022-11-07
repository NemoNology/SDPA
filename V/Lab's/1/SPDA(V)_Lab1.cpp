#include <iostream>
#include <string>
#include "Tree.h"

using namespace std;

using type = int;


int main()
{

    TreeNode<type> *tn0, *tn1, *tn2, *tn3, *tn4;

    tn4 = new TreeNode<type>(140);
    tn3 = new TreeNode<type>(60);

    tn2 = new TreeNode<type>(120, NULL, tn4);
    tn1 = new TreeNode<type>(80, tn3);

    tn0 = new TreeNode<type>(100, tn1, tn2);

    tn2->Delete();
    
    system("pause");
    return 0;
}
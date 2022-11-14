#include <iostream>
#include <string>
#include "Tree.h"

using namespace std;

using type = int;


int main()
{

    TreeNode<type> *tn0, *tn1, *tn2, *tn3, *tn4, *tn5, *tn6, *tn7;

    //tn7 = new TreeNode<type>(130);

    //tn5 = new TreeNode<type>(130);
    //tn6 = new TreeNode<type>(160, tn7);

    tn4 = new TreeNode<type>(140);  //, tn5, tn6);
    tn3 = new TreeNode<type>(60);

    tn2 = new TreeNode<type>(120, NULL, tn4);
    tn1 = new TreeNode<type>(80, tn3);

    tn0 = new TreeNode<type>(100, tn1, tn2);

    tn0->Delete();
    
    system("pause");
    return 0;
}
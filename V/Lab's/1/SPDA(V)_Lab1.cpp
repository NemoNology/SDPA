#include <iostream>
#include <string>
#include "TreeNode.h"
#include "BinSTree.h"

using namespace std;

using type = int;


int main()
{

    TreeNode<type> * root = NULL, * tn1 = NULL, 
        * tn2 = NULL, * tn3 = NULL, * tn4 = NULL, 
        * tn5 = NULL, * tn6 = NULL, * tn7 = NULL;
    

    //tn7 = new TreeNode<type>(130);

    tn5 = new TreeNode<type>(130);
    //tn6 = new TreeNode<type>(160, tn7);


    tn4 = new TreeNode<type>(140);  //, tn5, tn6);
    tn3 = new TreeNode<type>(60, NULL, tn5);

    tn2 = new TreeNode<type>(120, NULL, tn4);
    tn1 = new TreeNode<type>(80, tn3);

    root = new TreeNode<type>(100, tn1, tn2);


    BinSTree<type> * BS = new BinSTree<type>(root);

    BS->PrintTreeV();

    system("pause");
    return 0;
}
#include <iostream>
#include <string>
#include "Tree.h"

using namespace std;

using type = int;


int main()
{

    
    TreeNode<type> Tn1(25,  new TreeNode<type>(29), new TreeNode<type>(11));

    TreeNode<type> Tn1L = Tn1.GetLeft();
    TreeNode<type> Tn1R = Tn1.GetLeft();

    Tn1L.SetChild(nullptr, new TreeNode<int>(20));
    Tn1R.SetChild(new TreeNode<int>(22));

    
    system("pause");
    return 0;
}
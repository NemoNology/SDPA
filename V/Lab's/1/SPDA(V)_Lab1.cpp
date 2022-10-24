#include <iostream>
#include <string>
#include "Tree.h"

using namespace std;

using type = int;


int main()
{

    TreeNode<type> Tn1(25, new TreeNode<type>(21), new TreeNode<type>(22));

    Tn1.SetChild(392, 999);

    TreeNode<type> Tn2(70, new TreeNode<type>(20), new TreeNode<type>(10));

    Tn1.Left()->SetChild(Tn2, Tn2);

    //Tn1L->SetChild(NULL, 20);
    //Tn1R->SetChild(22);

    
    system("pause");
    return 0;
}
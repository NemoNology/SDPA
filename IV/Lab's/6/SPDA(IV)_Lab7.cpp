#include <iostream>
#include "Item.h"
#include "Stack.h"

using namespace std;

int main()
{
    Item TV("Television", 2000, 60);
    Item Phone("Phone", 700, 10);
    Item Toaster("Toaster", 1100, 40);

    Stack House(800);
    Stack Backpack(60);

    House.AddItem(TV);
    House.AddItem(Phone);
    House.AddItem(Phone);
    House.AddItem(Toaster);

    cout << "House (Before):\n";
    House.PrintInfo();

    for (int i = 0; i < House.GetItemsAmount(); i++)
    {
        if ((House.GetItem(i).GetPrice() == House.GetMaxPrice()) && 
            (House.GetItem(i).GetMass() <= (Backpack.GetBaseCapacity() - Backpack.GetCapacity())))
        {
            Backpack.AddItem(House.SubItem(i));
        }
    }

    cout << "House (Ather):\n";
    House.PrintInfo();

    cout << "Backpack (" << Backpack.GetBaseCapacity() << "kg):\n";
    Backpack.PrintInfo();



    system("pause");
    return 0;
}
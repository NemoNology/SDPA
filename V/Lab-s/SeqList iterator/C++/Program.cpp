#include <iostream>
#include "SeqListIterator.h"

using namespace std;

int main()
{
    SeqList<int> l = SeqList<int>();

    int size = 17;

    for (int i = 1; i < size; i++)
        l.Append(i);

    SeqListIterator<int> it = SeqListIterator<int>(&l);

    cout << "List output with list dequeue-s:\n";

    while (!l.isEmpty())
        cout << l.Dequeue() << ", ";

    cout << "\nList output with list iterator:\n";

    for (int i = 1; i < size; i++)
        l.Append(i);

    for (it.Reset(); !it.IsIterationComplete(); it.Next())
        cout << it.GetCurrentElementValue() << ", ";

    cout << "\n";

    system("pause");
    return 0;
}

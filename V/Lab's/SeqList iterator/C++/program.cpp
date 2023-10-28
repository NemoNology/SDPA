#include <iostream>
#include "SeqListIterator.h"

using namespace std;

int main()
{
    SeqList<int> l = SeqList<int>();

    int size = 17;

    for (int i = 1; i < size; i++)
        l.Append(i);

    for (int i = 0; i < l.size(); i++)
    {
        int el = 0;
        if (l.TryGetElementAt(i, el))
            cout << el << ", ";
    }

    cout << "\n"
         << l.Count() << " - size after appends\n";

    for (int i = 0; i < size; i++)
        l.Pop();

    cout << l.Count() << " - size after pop-s\n";

    for (int i = 0; i < l.size(); i++)
    {
        int el = 0;
        if (l.TryGetElementAt(i, el))
            cout << el << ", ";
    }

    system("pause");
    return 0;
}

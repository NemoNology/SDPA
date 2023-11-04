#include <iostream>
#include <ctime>
#include "Heap.h"

using namespace std;

using type = int;

int GetRandomInt(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int size = 16;
    Heap<type> heap = Heap<type>(size);

    cout << "Inserting numbers: ";
    for (int i = 0; i < size; i++)
    {
        int num = GetRandomInt(0, 100);
        cout << num << ", ";
        heap.Insert(num);
    }

    cout << "\nHeap max: " << heap.GetMax() << "\nRemoving maxes:\n";

    for (int i = 0; i < size; i++)
    {
        cout << heap.GetMax() << " (" << heap.GetSize() << ") -> ";
        heap.RemoveMax();
    }

    cout << "\n";

    // system("pause");
    return 0;
}
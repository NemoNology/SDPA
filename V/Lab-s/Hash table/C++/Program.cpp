#include <iostream>
#include "HashTable.h"
#include "HashFunctions.h"
#include "HashTableIterator.h"
#include <ctime>

using namespace std;

using type = int;
using HT = HashTable<type>;
using HF = HashFunctions;
using HTI = HashTableIterator<type>;

int main()
{
    int size = 100;
    HT ht = HT(size, HF::murmur3);
    for (int i = 1; i <= size; i += 1)
        ht.SetValue(to_string(i), i);

    // HTI hti = HTI(&ht);

    // for (hti.Reset(); !hti.IsIterationComplete(); hti.Next())
    //     cout << hti.GetCurrent() << ", ";

    // system("pause");
    return 0;
}

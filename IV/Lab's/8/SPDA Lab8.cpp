#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include "ArrayUnit.h"

using namespace std;

using uint = unsigned int;

int main()
{
    vector<double> A(10);
    fstream F;
    double key;

    // Varuables for time check
    chrono::steady_clock::time_point ST, ET;
    chrono::duration<double> FT;

    F.open("Result.txt");


    cout << "Input array [1..10] (using Enter):\n";

    // Input first array
    for (int i = 0; i < A.size(); i++)
    {
        cout << "a" << i + 1 << "] ";
        cin >> A[i];
    }

    // Input first key
    cout << "Input a key: ";
    cin >> key;

    // Write data to file: first array and key
    F << "Array [1..10]:\n";
    WriteArrayToFile(F, A);
    F << "\nKey: " << key;

    // Calculating time for first array linear search
    ST = chrono::high_resolution_clock::now();
    LinearSeach(A, key);
    ET = chrono::high_resolution_clock::now();

    // Calculating result/final time
    FT = chrono::duration<float>(ET - ST);

    // Write data to file: linear searching result and time for first array
    F << "\nLinear search result: " << LinearSeach(A, key);
    F << "\nLinear search time: " << setprecision(8) << FT.count() << " seconds";

    // Sort first array for binear search
    SelectionSort(A);

    // Write data to file: first array (sorted)
    F << "\nArray [1..10] (sorted):\n";
    WriteArrayToFile(F, A);

    // Calculating time for first array binear search
    ST = chrono::high_resolution_clock::now();
    BinSearch(A, key);
    ET = chrono::high_resolution_clock::now();

    // Calculating result/final time
    FT = chrono::duration<float>(ET - ST);

    // Write data to file: binear searching result and time for first array (sorted)
    F << "\nBinear search result: " << BinSearch(A, key);
    F << "\nBinear search time: " << setprecision(8) << FT.count() << " seconds\n\n";



    // Getting second array (Random, size = 500)
    A = GetRandomArray(500);

    // Input second key
    cout << "Input a key for second array: ";
    cin >> key;

    // Write data to file: second array and key
    F << "\nArray [1..500]:\n";
    WriteArrayToFile(F, A);
    F << "\nKey: " << key;

    // Calculating time for second array linear search
    ST = chrono::high_resolution_clock::now();
    LinearSeach(A, key);
    ET = chrono::high_resolution_clock::now();

    // Calculating result/final time
    FT = chrono::duration<float>(ET - ST);

    // Write data to file: linear searching result and time for second array
    F << "\nLinear search result: " << LinearSeach(A, key);
    F << "\nLinear search time: " << setprecision(8) << FT.count() << " seconds";
    
    // Sort second array for binear search
    SelectionSort(A);

    // Write data to file: second array (sorted)
    F << "\nArray [1..500] (sorted):\n";
    WriteArrayToFile(F, A);

    // Calculating time for second array binear search
    ST = chrono::high_resolution_clock::now();
    BinSearch(A, key);
    ET = chrono::high_resolution_clock::now();

    // Calculating result/final time
    FT = chrono::duration<float>(ET - ST);

    // Write data to file: binear searching result and time for second array (sorted)
    F << "\nBinear search result: " << BinSearch(A, key);
    F << "\nBinear search time: " << setprecision(8) << FT.count() << " seconds\n\n";



    F.close();

    system("pause");
    return 0;
}
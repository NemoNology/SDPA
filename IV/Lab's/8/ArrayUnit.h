#pragma once
#include <vector>
#include <fstream>
#include <iomanip>
#include "OtherUnit1.h"

using namespace std;

int LinearSeach(vector<double> arr, double key)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}


int BinSearch(vector<double> arr, double key)
{
    int low = 0, high = arr.size() - 1, mid;

    // Выполняем процедуру поиска, пока правая граница не упрётся в левую или наоборот
    while (low < high)
    {
        // Вычисляем середину, объеденив границы слева и справа и разделив на 2
        mid = (low + high) / 2;

        // Если мы нашли искомое значение - возвращаем индекс
        if (arr[mid] == key)
        {
            return mid;
        }
        // Если наше значение меньше значения из середины - переходим к проверке левого отрезка
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
        // Иначе - переходим к проверке правого отрезка
        else
        {
            low = mid + 1;
        }
    }

    // В случае отсутствия искомогов  массиве выдаём необходимый отрицательный результат
    return -1;
}


vector<double> GetRandomArray(int size)
{
    vector<double> A(size);

    for (int i = 0; i < size; i++)
    {
        A[i] = GetRandomDouble(0, 100);
    }

    return A;
}


void WriteArrayToFile(fstream & F, vector<double> A)
{
    const int numbersInLine = 10;

    if (F.is_open())
    {
        for (int i = 0; i < A.size(); i++)
        {

            F << setprecision(5) << setw(7) << A[i] << "  ";

            if ((i + 1) % numbersInLine == 0)
            {
                F << "\n";
            }

        }
    }
}


void SelectionSort(vector<double>& A) 
{
    double num = A[0], ind = 0;
    int n = A.size() - 1;

    while (n > 0)
    {
        for (int i = 0; i < n + 1; i++)
        {
            if (num < A[i])
            {
                num = A[i];
                ind = i;
            }
        }

        swap(A[n], A[ind]);

        num = A[0];
        ind = 0;

        n--;
    }

}

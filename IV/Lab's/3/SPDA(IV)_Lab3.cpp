#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "FileUnit.h"


using namespace std;


// Рекурсивная функция: вывод строки в обратной последовательности
string ReverseString(string s) 
{

	return "//todo:";

}


int main()
{
	// Строка введённых чисел и временная строка для I/O файла
	string Numbers, temp;

	// Наименования файлов для чтения
	string FInName, FOutname;

	FInName = "Data.txt";
	FOutname = "Res.txt";

	cout << FileRead(FInName);



	system("pause");
	return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include "FileUnit.h"


using namespace std;


// Рекурсивная функция: вывод строки в обратной последовательности
string ReverseString(string s) 
{
	// База
	if (s.empty()) {
		
		return "";

	}

	// Шаг
	return ReverseString(s.substr(1, s.size() - 1)) + s.front();

}


int main()
{
	// Строка введённых чисел и временная строка для I/O файла
	string Numbers, temp;

	// Наименования файлов для чтения
	string FInName, FOutname;

	FInName = "Data.txt";
	FOutname = "Res.txt";

	cout << "Data:\t" << FileRead(FInName) << "\n";
	cout << "Result:\t" << ReverseString(FileRead(FInName)) << "\n";


	system("pause");
	return 0;
}
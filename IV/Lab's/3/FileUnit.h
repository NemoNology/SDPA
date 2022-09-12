#pragma once
#include <fstream>
#include <string>
#include <exception>

using namespace std;


// Проверка существования файла
// Данная функция используется внутри других функций - 
// Файл закрывать не надо
void IsFileExist(string FileName)
{

	fstream F(FileName);

	// Если файла нет, то выводим ошибку
	if (!F.is_open())
	{
		throw invalid_argument("The file is not exist!");
	}

}


// Чтение из файла. Строка должна заканчиваться нулём
string FileRead(string FileName)
{
	string temp = "", res = "";
	fstream F(FileName);

	// Проверяем существование файла
	IsFileExist(FileName);

	// Считываем 1-ое слово
	F >> temp;

	// По первому слову проверяем пустоту файла или конечность последовательности чисел
	// Если файл не пуст и последовательность ещё не закончена, 
	// то к результирующей строке прибавляем Это число и продолжаем чтение
	while ((temp != "0") && (!F.eof()))
	{
		
		res.append(temp + " ");

		F >> temp;

	}

	// Закрываем файл
	F.close();

	// Возвращаем строку без лишнего в конце пробела
	return res.substr(0, res.size() - 1);

}



// Запись в файл
void FileRewrite(string FileName, string s)
{

	fstream F(FileName);

	// Проверяем существование файла
	IsFileExist(FileName);

	// Записываем строку
	F << s;

	// Закрываем файл
	F.close();

}

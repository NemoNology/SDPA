#pragma once
#include <fstream>
#include <string>
#include <exception>
#include <format>

using namespace std;


// ������ �� �����. ������ ������ ������������� ����
string FileRead(string FileName)
{
	string temp = "", res = "";
	fstream F;

	F.open(FileName);

	if (!F.is_open())
	{
		throw invalid_argument(_Printf_format_string_("The file by name {} is not exist!", FileName));
	}


	F >> temp;

	while ((temp != "0") && (!F.eof()))
	{

		res.append(temp + " ");

		F >> temp;

	}

}



// ������ � ����
void FileRewrite(string FileName, string s)
{



}

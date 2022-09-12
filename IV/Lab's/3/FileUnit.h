#pragma once
#include <fstream>
#include <string>
#include <exception>

using namespace std;


// �������� ������������� �����
// ������ ������� ������������ ������ ������ ������� - 
// ���� ��������� �� ����
void IsFileExist(string FileName)
{

	fstream F(FileName);

	// ���� ����� ���, �� ������� ������
	if (!F.is_open())
	{
		throw invalid_argument("The file is not exist!");
	}

}


// ������ �� �����. ������ ������ ������������� ����
string FileRead(string FileName)
{
	string temp = "", res = "";
	fstream F(FileName);

	// ��������� ������������� �����
	IsFileExist(FileName);

	// ��������� 1-�� �����
	F >> temp;

	// �� ������� ����� ��������� ������� ����� ��� ���������� ������������������ �����
	// ���� ���� �� ���� � ������������������ ��� �� ���������, 
	// �� � �������������� ������ ���������� ��� ����� � ���������� ������
	while ((temp != "0") && (!F.eof()))
	{
		
		res.append(temp + " ");

		F >> temp;

	}

	// ��������� ����
	F.close();

	// ���������� ������ ��� ������� � ����� �������
	return res.substr(0, res.size() - 1);

}



// ������ � ����
void FileRewrite(string FileName, string s)
{

	fstream F(FileName);

	// ��������� ������������� �����
	IsFileExist(FileName);

	// ���������� ������
	F << s;

	// ��������� ����
	F.close();

}

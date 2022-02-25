#pragma once
#include <iostream>
#include <exception>
#include <fstream>
#include <string>
#include "File_Unit.h"


using namespace std;



class Time
{


private:						// ������/���� ������ - Fields

	// Hour (0-23) - ���; Hinute (0-59) - ������; Second (0-59) - �������

	int Hour, Minute, Second;


public:							// ������ ������ - Methods



	// ����������� � �������� ����������
	Time(int h, const int& m, const int& s) {

		Set_hour(h);
		Set_minute(m);
		Set_second(s);

	}



	// ������� ���������� �������� ����� ������ - ������� - Setter:



	// ����� ���������� ���� - Set hour 
	void Set_hour(const int& h) {

		if (h < 0 || h > 23) {	// ������������ �������� �������� �����

			throw invalid_argument("Invalid argument: argument is out of range");

		}
		else {					// ���� �� ��������� - ����������� ��������

			this->Hour = h;

		}

	}


	// ����� ���������� ����� - Set minute
	void Set_minute(const int& m) {

		if (m < 0 || m > 59) {	// ������������ �������� �������� �����

			throw invalid_argument("Invalid argument: argument is out of range");

		}
		else {					// ���� �� ��������� - ����������� ��������

			this->Minute = m;

		}

	}


	// ����� ���������� ������ - Set second
	void Set_second(const int& s) {

		if (s < 0 || s > 59) {	// ������������ �������� �������� �����

			throw invalid_argument("Invalid argument: argument is out of range");

		}
		else {					// ���� �� ��������� - ����������� ��������

			this->Second = s;

		}

	}



	// ������� ��������� �������� ����� ������ - ������� - Getters:



	// ����� ��������� ����� - Get hour
	int Get_hour() {

		return this->Hour;

	}


	// ����� ��������� ����� - Get minute
	int Get_minute() {

		return this->Minute;

	}


	// ����� ��������� ������ - Get second
	int Get_second() {

		return this->Second;

	}


	// ����� ��������� ������� � ������
	string Get_string_time() {

		return "Hour:\t" + to_string(this->Hour) + ",\tMinute:\t" + to_string(this->Minute) + ",\tSecond:\t" + to_string(this->Second) + "\n";

	}


	// ����� ������� � ���� ������ � �������
	void Get_time_Console() {

		cout << Get_string_time();

	}

}

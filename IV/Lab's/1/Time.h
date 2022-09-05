#pragma once
#include <iostream>
#include <exception>
#include <fstream>
#include <string>
#include "File_Unit.h"


using namespace std;



class Time
{


private:						// Данные/Поля класса - Fields

	// Hour (0-23) - Час; Hinute (0-59) - Минуты; Second (0-59) - Секунды

	int Hour, Minute, Second;


public:							// Методы класса - Methods



	// Конструктор с входными значениями
	Time(int h, const int& m, const int& s) {

		Set_hour(h);
		Set_minute(m);
		Set_second(s);

	}



	// Функции назначения значений полей класса - сеттеры - Setter:



	// Метод назначения часа - Set hour 
	void Set_hour(const int& h) {

		if (h < 0 || h > 23) {	// Ограничиваем диапазон введённых чисел

			throw invalid_argument("Invalid argument: argument is out of range");

		}
		else {					// Если всё корректно - присваиваем значение

			this->Hour = h;

		}

	}


	// Метод назначения минут - Set minute
	void Set_minute(const int& m) {

		if (m < 0 || m > 59) {	// Ограничиваем диапазон введённых чисел

			throw invalid_argument("Invalid argument: argument is out of range");

		}
		else {					// Если всё корректно - присваиваем значение

			this->Minute = m;

		}

	}


	// Метод назначения секунд - Set second
	void Set_second(const int& s) {

		if (s < 0 || s > 59) {	// Ограничиваем диапазон введённых чисел

			throw invalid_argument("Invalid argument: argument is out of range");

		}
		else {					// Если всё корректно - присваиваем значение

			this->Second = s;

		}

	}



	// Функции получения значений полей класса - геттеры - Getters:



	// Метод получения часов - Get hour
	int Get_hour() {

		return this->Hour;

	}


	// Метод получения минут - Get minute
	int Get_minute() {

		return this->Minute;

	}


	// Метод получения секунд - Get second
	int Get_second() {

		return this->Second;

	}


	// Метод получения времени в строке
	string Get_string_time() {

		return "Hour:\t" + to_string(this->Hour) + ",\tMinute:\t" + to_string(this->Minute) + ",\tSecond:\t" + to_string(this->Second) + "\n";

	}


	// Вывод времени в виде строки в консоль
	void Get_time_Console() {

		cout << Get_string_time();

	}

}

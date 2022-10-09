#pragma once
#include <string> 
#include <iomanip>

using namespace std;

using uint = unsigned int;

class Item
{

private:

	string _name;
	uint _price;
	uint _mass;

public:

	Item()
	{
		_name = "Unknown";
		_price = 0;
		_mass = 0;
	}

	Item(string name, uint price, uint mass)
	{
		_name = name;
		_price = price;
		_mass = mass;
	}


	void SetParams(string name, uint price, uint mass)
	{
		_name = name;
		_price = price;
		_mass = mass;
	}

	string GetName()
	{
		return _name;
	}

	uint GetMass()
	{
		return _mass;
	}

	uint GetPrice()
	{
		return _price;
	}

	string GetInfo()
	{
		return _name + "\t["
			+ to_string(_mass) + "\tkg;\t"
			+ to_string(_price) + "\tgold]";
	}

	void PrintInfo()
	{

		cout << setw(14) << _name << "[" << setw(3) << _mass << " kg;"
			<< setw(5) << _price << " gold]\n";

	}
};


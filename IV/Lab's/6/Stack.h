#pragma once
#include "Item.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

using uint = unsigned int;

class Stack
{
	
private:

	uint _capacity;
	vector<Item> _store;


public:

	Stack()
	{
		_capacity = 0;
	}

	Stack(uint cap)
	{
		_capacity = cap;
	}

	uint GetCapacity()
	{
		uint res = 0;

		for (Item i : _store)
		{
			res += i.GetMass();
		}

		return res;
	}

	uint GetBaseCapacity()
	{
		return _capacity;
	}

	void AddItem(Item item)
	{
		if (GetCapacity() < _capacity)
		{
			_store.push_back(item);
		}
	}

	Item SubItem(uint index)
	{
		Item res;
		auto iter = _store.begin();

		if (GetCapacity() > 0)
		{
			res = _store[index];
			_store.erase(iter + index);
		}
		
		return res;
	}

	uint GetItemAmount(string name)
	{
		uint res = 0;

		for (Item i : _store)
		{
			if (i.GetName() == name)
			{
				res++;
			}
		}

		return res;
	}

	void RemoveItem(vector<Item> & items, Item item)
	{
		auto iter = items.cbegin();
		int i = 0;

		while (i < items.size())
		{
			if (items[i].GetInfo() == item.GetInfo())
			{
				items.erase(iter + i);
				iter = items.cbegin();
			}
			else
			{
				i++;
			}
		}

	}

	uint GetMaxPrice()
	{
		uint res = 0;

		for (Item i : _store)
		{
			if (i.GetPrice() > res)
			{
				res = i.GetPrice();
			}
		}

		return res;
	}

	uint GetItemsAmount()
	{
		uint res = 0;
		
		for (Item i : _store)
		{
			res++;
		}

		return res;

	}

	Item GetItem(uint index)
	{
		return _store[index];
	}

	uint GetWholePrice()
	{
		uint res = 0;

		for (Item i : _store)
		{
			res += i.GetPrice();
		}

		return res;
	}

	void PrintInfo()
	{
		cout << "\n";

		vector<string> infos;
		vector<uint> amounts;
		vector<Item> items = _store;

		while (items.size() > 0)
		{
			infos.push_back(items[0].GetInfo());
			amounts.push_back(GetItemAmount(items[0].GetName()));
			RemoveItem(items, items[0]);
		}

		for (int i = 0; i < infos.size(); i++)
		{
			cout << "\t" << infos[i] << "\t(" << amounts[i]
				<< ")\n";
			
		}

		cout << setw(16) << "Total price:" << setw(8) << GetWholePrice() << "\n";

	}


};


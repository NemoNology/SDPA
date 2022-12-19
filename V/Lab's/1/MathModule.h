#pragma once

using namespace std;
using uint = unsigned int;


template <class T> auto Max(T a, T b, T c)
{
	if ((a >= b) && (a >= c))
	{
		return a;
	}
	else if ((b >= a) && (b >= c))
	{
		return b;
	}
	else
	{
		return c;
	}
}

template <class T> auto Max(T a, T b)
{
	if (a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

template <class T> auto Pow(T a, int degree)
{
	if (degree == 0)
	{
		return 1;
	}
	
	auto res = a;
	
	res = 1;
	
	for (int i = 0; i < abs(degree); i++)
	{
		res *= a;
	}
	
	if (degree < 0)
	{
		return 1 / res;
	}

	return res;
	
}
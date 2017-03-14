#include <iostream>
#include <cmath>
#include <vector>
#include <boost/timer/timer.hpp>

using namespace std;

bool isSgonal(int, int);
bool isNatural(long double);

int main()
{
	boost::timer::auto_cpu_timer t;
	long llim, ulim = 0;

	cout << "Lower limit? ";
	cin >> llim;
	cout << "Upper limit? ";
	cin >> ulim;

	long range = (ulim - llim);
	long arraySize = range + 1;

	struct numProfile
	{
		long trueQuant;
		long value;
	};

	/*Classic dynamic array replaced with vectors I guess*/
	vector<numProfile> arr(arraySize);

	for(int s = 1; s <= ulim; s++)
	{
		for(int n = llim; n <= ulim; n++)
		{
			if(isSgonal(s, n))
			{
				(arr.at(n - llim)).trueQuant++;
				(arr.at(n - llim)).value = n;
			}
		}
	}

	int maxTrueQuant = 0;
	int maxNVal = 0;
	//tests be hither ↓↓↓

	/*
	for(int k = 0; k <= (range); k++)
	{
		cout << "(arr.at(" << k << ")).trueQuant = " << (arr.at(k)).trueQuant << endl;
		cout << "(arr.at(" << k << ")).value = " << (arr.at(k)).value << endl;
		cout << endl;
	}
	*/

	for(int k = 0; k <= range; k++)
	{
		if((arr.at(k)).trueQuant > maxTrueQuant && (arr.at(k)).value != 1)
		{
			maxTrueQuant = (arr.at(k)).trueQuant;
			maxNVal = (arr.at(k)).value;
		}
	}

	cout << "Most polygonal number between " << llim << " and " << ulim << " is " << maxNVal << " with a trueQuant of " << maxTrueQuant << endl;

	return 0;
}

bool isSgonal(int s, int n)
{
	double test = (sqrt((8 * s - 16) * n + pow((s - 4), 2)) + s - 4)/(2 * s - 4);
	return isNatural(test);
}

bool isNatural(long double u)
{
	return (round(u) == u && u != 0);
}

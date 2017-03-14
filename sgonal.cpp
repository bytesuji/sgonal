#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <boost/timer/timer.hpp>
#include <vector>
#include <cassert>

using namespace std;

bool isSgonal(int, int);
bool isNatural(long double);
void hyperpolygonal(void);

struct polyProfile
{
	long trueN;
	long value;
};


int main()
{
	int option, s, limit, num, counter;
	long maxVal, maxSgonal;

	cout << "   ____                            __  _______           __          \n  / __/ ____  ___ ____  ___  ___ _/ / / ___/ /  ___ ____/ /_____ ____\n _\\ \\  /___/ / _ `/ _ \\/ _ \\/ _ `/ / / /__/ _ \\/ -_) __/  '_/ -_) __/\n/___/        \\_, /\\___/_//_/\\_,_/_/  \\___/_//_/\\__/\\__/_/\\_\\\\__/_/   \n            /___/                                                    \n\n";
	/*
	cout << "\t*********************************\n"
		 << "\t*         SGONAL CHECKER        *\n"
		 << "\t*             v1.3              *\n"
		 << "\t*********************************\n\n";
	*/
	cout << "<1> Check s-gonality\n<2> Generate s-gonals\n<3> Determine s-values which validate n being s-gonal\n<4> Check hyperpolygonality \n\n";
	cout << "Option: ";
	cin >> option;

	switch(option)
	{
		case 1:
		{
			cout << "\nInput s-value: ";
			cin >> s;
			cout << "Input number: ";
			cin >> num;
			if(isSgonal(s, num))
			{
				cout << num << " is " << s << "-gonal\n";
			}
			else
			{
				cout << num << " is not " << s << "-gonal\n";
			}
			break;
		}

		case 2:
		{
			cout << "\n<1> Generate n s-gonals\n<2> Generate s-gonals to a limit\n\n";
			cout << "Option: ";
			int subOption;
			cin >> subOption;

			switch(subOption)
			{
				case 2:
				{
					counter = 0;
					cout << "Input s-value: ";
					cin >> s;
					cout << "Input limit: ";
					cin >> limit;

					for(int j = 1; j <= limit; j++)
					{
						if(isSgonal(s,j))
						{
							cout << j << endl;
							++counter;
						}
					}

					cout << "There are " << counter << " " << s << "-gonals below " << limit << ".\n";
					break;
				}

				case 1:
				{
					int n;
					cout << "\nInput N: ";
					cin >> n;
					cout << "Input s-value: ";
					cin >> s;

					for(int j = 1; counter < n; j++)
					{
						if(isSgonal(s,j))
						{
							cout << j << endl;
							counter++;
						}
					}
					break;
				}
			}
			break;
		}

		case 3:
		{
			cout << "\nInput number: ";
			cin >> num;
			cout << "Input s-value limit: ";
			cin >> limit;

			assert(!(limit >= num));

			for(int j = 1; j <= limit; j++)
			{
				if(isSgonal(j, num))
				{
					cout << j << endl;
				}
			}
			break;
		}

		case 4: //doesn't really work right now, not sure why
		{
			hyperpolygonal();
			break;
		}

			/* being worked on
		case 5:
			{
				cout << "Input values for polygonality checking. Input a # character when finished." << endl;
				int index, tmp = 0;
				vector<int> polygValues;

				do
				{
					cin >> tmp;
					polygValues.at(index) = tmp;
					++index;
				} while((char) tmp != '#') //this needs to be changed, because it prevents the user from testing the value of 35 (the ASCII value for #)
				cout << "To what limit do you want to test? ";
				cin >> limit;

				for(int k = 0; k <= polygValues.size(); k++)
				{
					for(int n = 0; n <= limit; n++)
					{
						if(isSgonal(polygValues.at(k),))
					}
				}
			}

/*
		case 8: //for testing purposes only at the moment
			{
				cout << "\nInput number: ";
				cin >> num;
				cout << "Input s-value limit: ";
				cin >> limit;

				for(int j = 1; j <= limit; j++)
				{
					if(isSgonal(j, num))
					{
						counter++;
					}
				}
				cout << counter << endl;
				break;
			}
*/

		default:
		{
			cout << "Invalid...\n";
			break;
		}
	}

	cout << "Go again? [y/n] ";
	char rerun;
	cin >> rerun;
	if(rerun == 121 || rerun == 89)
	{
		counter = 0;
		maxVal = 0;
		maxSgonal = 0;
		main();
	}

	else
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

void hyperpolygonal(void)
{
	boost::timer::auto_cpu_timer t;
	long nlim, slim = 0;
	cout << "Number limit? ";
	cin >> nlim;
	/*
	   cout << "S-val limit? ";
	   cin >> slim;
	   */
	slim = nlim;

	struct numProfile
	{
		long trueQuant;
		long value;
	};

	numProfile *arr = new numProfile[(nlim + 1)];

	//	cout << "Testing polygonality...\n\n";
	for(int s = 0; s <= slim; s++)
	{
		for(int n = 0; n <= nlim; n++)
		{
			if(isSgonal(s, n))
			{
				arr[n].trueQuant++;
				arr[n].value = n;
			}
		}
	}

	int maxTrueQuant = 0;
	int maxNVal = 0;
	//tests be hither

	/*
	   for(int k = 0; k <= nlim; k++)
	   {
	   cout << "arr[" << k << "].trueQuant = " << arr[k].trueQuant << endl;
	   cout << "arr[" << k << "].value = " << arr[k].value << endl;
	   cout << endl;
	   }
	   */
	//cout << "Determining number with most hits...\n\n";
	for(int k = 1; k <= nlim; k++)
	{
		if(arr[k].trueQuant > maxTrueQuant && arr[k].value != 1)
		{
			maxTrueQuant = arr[k].trueQuant;
			maxNVal = arr[k].value;
		}
	}

	cout << "Most polygonal number below " << nlim << " is " << maxNVal << " with a trueQuant of " << maxTrueQuant << endl;
	delete[] arr;
}

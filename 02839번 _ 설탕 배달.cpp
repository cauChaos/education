#include <iostream>
using namespace std;

int main()
{
	int number, five;
	int remain;

	cin >> number;

	if (number < 3 || number > 5000)
		return 0;

	five = number / 5;

	while (five >= 0)
	{
		remain = number - (5 * five);
		
		if (remain % 3 == 0)
		{
			cout << five + (remain / 3) << endl;
			return 0;
		}
		five--;
	}
	if (five < 0)
	{
		cout << "-1" << endl;
	}
	
	return 0;
}

by Junsuk Oh

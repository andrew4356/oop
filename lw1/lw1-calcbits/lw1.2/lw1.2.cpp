
#include <stdafx.h>
#include <iostream>

using namespace std;


bool ñheckingOnInteger(char *checkNumber)
{
	bool check = true;
	while (*checkNumber)
	{
		if (!isdigit(*checkNumber++))
		{
			check = false;
			return check;
		}
	}
	return check;
}
   
int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: calcbits.exe <input number>\n";
		return 1;
	}
	if (!ñheckingOnInteger(argv[1]))
	{
		cout << "input erorr" << endl;
		return 1;
	}
	
	int tenNumber = atoi(argv[1]);
	string binaryNumberStr = "";
	int binaryStringLength = 8 * sizeof(tenNumber);
	for (int i = binaryStringLength; i >= 0; --i)
	{
		if ((1 << i) & tenNumber)
		{
			binaryNumberStr = binaryNumberStr + "1";
		}
		else
		{
			binaryNumberStr = binaryNumberStr + "0";
		}
	}
	cout << "Binary Number \n" << binaryNumberStr << endl;
	return 0;
}
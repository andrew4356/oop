
#include <stdafx.h>
#include <iostream>
#include <string>

using namespace std;

void ToBinary(unsigned num)
{
	string binaryNumberStr = "";
	int binaryStringLength = 8 * sizeof(num);
	for (int i = binaryStringLength; i >= 0; --i)
	{
		if ((1 << i) & num)
		{
			binaryNumberStr = binaryNumberStr + "1";
		}
		else
		{
			binaryNumberStr = binaryNumberStr + "0";
		}
	}
    cout << binaryNumberStr;

}

bool ÑheckingOnInteger(char *checkNumber)
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
	if (!ÑheckingOnInteger(argv[1]))
	{
		cout << "input erorr" << endl;
		return 1;
	}
	
    unsigned number = atoi(argv[1]);
	
	cout << "Binary Number \n";
	ToBinary(number);
	cout << endl;
	return 0;
} 
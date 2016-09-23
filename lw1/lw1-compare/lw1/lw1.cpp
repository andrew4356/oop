#include "stdafx.h"


using namespace std;

int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: copyfile.exe <input file> <output file>\n";
		return 1;
	}

	ifstream f1(argv[1]);

	if (!f1.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}
	ifstream f2(argv[2]);
	if (!f2.is_open())
	{
		cout << "Failed to open " << argv[2] << " for reading\n";
		return 1;
	}

	char s1[256], s2[256];
	int j = 0;
	while (!f1.eof())
	{
		f1.getline(s1, 256);
		f2.getline(s2, 256);
		++j;
		if (strcmp(s1, s2) != 0)
		{
			cout << "Files are different. Line number is " << j;
			return 1;
		}

	};
	cout << "Files are equal \n";
	return 0;
}
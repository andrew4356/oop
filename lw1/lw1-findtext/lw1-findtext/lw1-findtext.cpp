#include "stdafx.h"
#include <string>

using namespace std;

void FindStringInFile(ifstream & input, const string & searchStr, bool & stringWasFound)
{
	string curentString;
	unsigned numberString = 1;

	while (getline(input, curentString))
	{
		if (curentString.find(searchStr) != string::npos)
		{
		cout << numberString << endl;
		stringWasFound = true;
		}
		++numberString; 
	}

}

int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: copyfile.exe <input file> <search text>\n";
		return 1;
	}

	ifstream input(argv[1]);

	if (!input.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}
	string searchQuery = argv[2];
	bool stringWasFound = false;
	
	FindStringInFile(input, searchQuery, stringWasFound);
	

	if (!stringWasFound)
	{
		cout << "According to this request, I found nothing " << endl;
	}
	return 0;
}
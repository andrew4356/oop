
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string HtmlEncode(string const & currentStr)
{
	string buffer = "";
	buffer.reserve(currentStr.size());
	for (size_t i = 0; i != currentStr.size(); ++i)
	{
		switch (currentStr[i])
		{
		case '&': buffer.append("&amp;"); break;
		case '\"': buffer.append("&quot;"); break;
		case '\'': buffer.append("&apos;"); break;
		case '<': buffer.append("&lt;"); break;
		case '>': buffer.append("&gt;"); break;
		default: buffer.append(&currentStr[i], 1); break;
		}
	}
	
	return buffer;
}

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: HTML Encode.exe <input file>\n";
		return 1;
	}

	ifstream input(argv[1]);

	if (!input.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	string currentStr = " ";

	/*while (getline(input, currentStr))
	{
		for (int i = currentStr.length; i != 0; --i)
		{
			currentSTR.replace(currentStr.find("<"), 2, "&lt;");
			currentSTR.replace(currentStr.find(">"), 2, "&gt;");
			currentSTR.replace(currentStr.find("\'"), 2, "&apos;");
			currentSTR.replace(currentStr.find("\""), 2, "&quot;");
		}
	}*/
	string timeStr;

	while (getline(input, currentStr))
	{
		currentStr.swap(HtmlEncode(currentStr));
		cout << currentStr <<  endl;
	}

	return 0;
}


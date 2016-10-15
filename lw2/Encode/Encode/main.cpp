
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

int main()
{

	string currentStr;

	while (getline(cin, currentStr))
	{
		
		cout << HtmlEncode(currentStr) <<  endl;
	}

	return 0;
}


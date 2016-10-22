#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string htmlencode(string const & currentstr)
{
	string buffer = "";
	buffer.reserve(currentstr.size());
	for (const auto ch : currentstr)
	{
		switch (ch)
		{
		case '&': buffer.append("&amp;"); break;
		case '\"': buffer.append("&quot;"); break;
		case '\'': buffer.append("&apos;"); break;
		case '<': buffer.append("&lt;"); break;
		case '>': buffer.append("&gt;"); break;
		default: buffer.append(&ch, 1); break;
		}
	}
	
	return buffer;
}

int main()
{

	string currentstr;

	while (getline(cin, currentstr))
	{
		
		cout << htmlencode(currentstr) <<  endl;
	}

	return 0;
}

//#include <iostream>
//#include <string>
// 
//using namespace std;
//void Decode(string & text)
//{
//	std::string ToReplace = "sda";
//	std::string ReplaceWith = "xd";
//	text.replace(text.find(ToReplace), ToReplace.length(), ReplaceWith);
//}
////---------------------------------------------------------------------------
//int main()
//{
//	std::string text = "sdadasdasdasdasdop";
//	
//	std::cout << "Original string: \t" << text << std::endl;
//	//size_t i = text.length();
//	for (size_t pos = 0; (pos = text.find(from, pos)) != std::string::npos; pos += to.size())
//	{  
//		++i;
//		Decode(text);
//	}
//	std::cout << "After replacing: \t" << text << std::endl << std::endl;
//
//	std::system("pause");
//	return 0;
//}


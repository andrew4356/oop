#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string HtmlEncode(string const & currentstr)
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

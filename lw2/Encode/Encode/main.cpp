#include "stdafx.h"
#include "unitForEncode.h"

using namespace std;


int main()
{

	string currentstr;

	while (getline(cin, currentstr))
	{
		
		cout << HtmlEncode(currentstr) <<  endl;
	}

	return 0;
}


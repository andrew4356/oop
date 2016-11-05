#include "stdafx.h"
#include <istream>
#include <string>
#include <map>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <wincon.h>

using namespace std;

void SaveNewWordInDictionary(const map <string, string> addingWordDictionary, ofstream & input)
{
	for (auto i = addingWordDictionary.begin(); i != addingWordDictionary.end(); ++i)
	{
		input << endl << i->first << '-' << i->second;
	}
}

bool Check�losing(string const& word, map <string, string> & addingWordDictionary, ofstream & input)
{
	string changes;
	if (word == "...")
	{
		if (addingWordDictionary.size() > 0)
		{
			cout << "� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������" << endl;
			cin >> changes;
			if (changes == "Y" || changes == "y"
				|| changes == "�" || changes == "�")
			{
				/*SaveNewWordInDictionary(addingWordDictionary, input);*/
				for (auto i = addingWordDictionary.begin(); i != addingWordDictionary.end(); ++i)
				{
					input << endl << i->first << '-' << i->second;
				}
				cout << "��������� ���� ���������" << endl;
				return true;
			}
			else
			{
				cout << "��������� �� ���� ���������" << endl;
				return true;
			}
		}
		else
		{
			return true;
		}
	}
	return false;
}
 

string TranslationSearch(string const& word, map <string, string> & dictionary, map <string, string> & addingWordDictionary)
{

	map <string, string>::iterator i;

	i = dictionary.find(word);

	for (auto i = dictionary.begin(); i != dictionary.end(); ++i)
	{
		if (i->first == word)
		{
			return i->second;
		}
	}

	for (auto i = addingWordDictionary.begin(); i != addingWordDictionary.end(); ++i)
	{
		if (i->first == word)
		{
			return i->second;
		}
	}

	return "";
}


void ProcessingDictionary(string const& word, map <string, string> & addingWordDictionary, map <string, string> dictionary)
{
	string foundWord;

	foundWord = TranslationSearch(word, dictionary, addingWordDictionary);

	string translate;

	if (foundWord != "")
	{
		cout << foundWord << endl;
	}
	else
	{
		cout << "����� ��� � �������. ������� ������� ��� ������ ������ ��� ������." << endl;
		getline(cin, translate);
		if (translate == "")
		{
			cout << "����� '" << word << "' �� ����� ��������" << endl;
		}
		else
		{
			map <string, string> temporaryDictionary;
			temporaryDictionary.insert(pair<string, string>(word, translate));
			addingWordDictionary = temporaryDictionary;
			cout << "����� '" << word << "' ��������� � ������� ��� '" << translate << "'." << endl;
		}
	}
}


int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		return 1;
	}

	ifstream input(argv[1]);

	if (!input.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}


	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	

	map <string, string> dictionary;
	map <string, string> addingWordDictionary;


	string firstWord;
	string word;
	string translationWord;
	string check; 
	string translate;

	while (getline(input, firstWord, '-') &&
		   getline(input, translate, '\n'))
	{
		dictionary[firstWord] = translate;
	}

	while (true)
	{
		cout << "������� ����� ��� ������ �� �������. ��� ������ �� ��������� ������� \"...\" :";

		getline(cin, word);
		ofstream input(argv[1], ofstream::app);
		if (Check�losing(word, addingWordDictionary, input))
		{
			break;
		}
		else
		{
			ProcessingDictionary(word, addingWordDictionary, dictionary);
		}
	}

    return 0;
}


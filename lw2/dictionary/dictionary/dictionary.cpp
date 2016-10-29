#include "stdafx.h"
#include <istream>
#include <string>
#include <map>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <wincon.h>

using namespace std;

bool CheckСlosing(string const& word, map <string, string> & addingWordDicrionary, ofstream & input)
{
	string changes = "";
	if (word == "...")
	{
		if (addingWordDicrionary.size() > 0)
		{
			cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом" << endl;
			cin >> changes;
			if (changes == "Y" || changes == "y"
				|| changes == "н" || changes == "Н")
			{
				for (auto i = addingWordDicrionary.begin(); i != addingWordDicrionary.end(); ++i)
				{
					input << endl << i->first << '-' << i->second;
				}
				cout << "Изменения были сохранены" << endl;
				return true;
			}
			else
			{
				cout << "Изменения не были сохранены" << endl;
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
 

string TranslationSearch(string const& word, map <string, string> & dictionary, map <string, string> & newWordsdictionary)
{

	for (auto i = dictionary.begin(); i != dictionary.end(); ++i)
	{
		if (i->first == word)
		{
			return i->second;
		}
	}

	for (auto i = newWordsdictionary.begin(); i != newWordsdictionary.end(); ++i)
	{
		if (i->first == word)
		{
			return i->second;
		}
	}

	return "";
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
	map <string, string> addingWordDicrionary;


	string firstWord = "";
	string word = "";
	string translationWord = "";
	string check = "";
	string translate = "";

	while (getline(input, firstWord, '-') &&
		   getline(input, translate, '\n'))
	{
		dictionary[firstWord] = translate;
	}

	while (true)
	{
		cout << "Введите слово для поиска по словарю. Для выхода из программы введите \"...\" :";

		getline(cin, word);
		ofstream input(argv[1], ofstream::app);
		if (CheckСlosing(word, addingWordDicrionary, input))
		{
			break;
		}
		else
		{
			string foundWord;

			foundWord = TranslationSearch(word, dictionary, addingWordDicrionary);
		
			string translate;
			
			if (foundWord != "")
			{
				cout << foundWord << endl;
			}
			else
			{
				cout << "Слова нет в словаре. Введите перевод или пустую строку для отказа." << endl;
				getline(cin, translate);
				if (translate == "")
				{
					cout << "Слово '" << word << "' не будет записано" << endl;
				}
				else
				{
					map <string, string> temporaryDictionary;
					temporaryDictionary.insert(pair<string, string>(word, translate));
					addingWordDicrionary = temporaryDictionary;
					cout << "Слово '" << word << "' сохранено в словаре как '" << translate << "'." << endl;
				}
			}
		}
	}

    return 0;
}


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

bool CheckСlosing(string const& word, map <string, string> & addingWordDictionary, ofstream & input)
{
	string changes;
	if (word == "...")
	{
		if (addingWordDictionary.size() > 0)
		{
			cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом" << endl;
			cin >> changes;
			if (changes == "Y" || changes == "y"
				|| changes == "н" || changes == "Н")
			{
				/*SaveNewWordInDictionary(addingWordDictionary, input);*/
				for (auto i = addingWordDictionary.begin(); i != addingWordDictionary.end(); ++i)
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
			addingWordDictionary = temporaryDictionary;
			cout << "Слово '" << word << "' сохранено в словаре как '" << translate << "'." << endl;
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
		cout << "Введите слово для поиска по словарю. Для выхода из программы введите \"...\" :";

		getline(cin, word);
		ofstream input(argv[1], ofstream::app);
		if (CheckСlosing(word, addingWordDictionary, input))
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


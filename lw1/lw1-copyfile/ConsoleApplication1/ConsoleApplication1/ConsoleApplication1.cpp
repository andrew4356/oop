#include <stdafx.h>

using namespace std;
string inputf(ifstream &f, char s[255])
{
	string a;
	f.open(s);
	if (f.fail()) {
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	f >> a;
	f.close();
	return a;
}

void outputf(ofstream &f, string a, char s[255])
{
	f.open(s);
	if (f.fail()) {
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	f << a;
	f.close();
}

int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: copyfile.exe <input file> <output file>\n";
		return 1;
	}
	
	setlocale(LC_ALL, "Russian");
	
	ifstream input(argv[1]);
	ofstream output(argv[2]);
	char ch1;
	//char str[255];
	//string a;

	if (!input.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	if (!output.is_open())
	{
		cout << "Failed to open " << argv[2] << " for writing\n";
		return 1;
	}

	while (input.get(ch1))
	{
		if (!output.put(ch1))
		{
			cout << "Ошибка записи в файл \n";
			return 1;
		}
	}

	if (!output.flush()) 
	{
		cout << "Failed to save data on disk\n";
		return 1;
	}

	return 0;
	
}

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

bool CheckOnTheCorrectnessOfTheArguments(int argc, char* argv)
{
	if (argc != 2)
	{
		cout << "Invalid arguments." << endl;
		cout << "primes.exe <Number>" << endl;
		return true;
	}

	if (atoi(argv) <= 0)
	{
		cout << "Invalid arguments." << endl;
		cout << "The number must be a range from 1 to 100000000" << endl;
		return true;
	}

	

	return false;
}

set<uint32_t> GeneratePrimeNumbersSet(int upperBound)
{
	vector<bool> numbers(upperBound + 1, true);
	set<uint32_t> primes;

	numbers[1] = false;

	if (upperBound > 1)
	{
		primes.emplace_hint(primes.end(), 2);
	}

	for (int i = 2; ((i*i) <= upperBound); i++)
	{
		if (numbers[i])
		{
			for (int j = (i*i); j <= upperBound; j += i)
			{
				 numbers[j] = false;
			}
		}
	}

	for (int i = 3; i <= upperBound; i += 2)
	{
		if (numbers[i])
		{
			primes.emplace_hint(primes.end(), i);
		}
	}

	return primes;
}

int main(int argc, char * argv[])
{
	if (CheckOnTheCorrectnessOfTheArguments(argc, argv[1]))
	{
		return 1;
	}

	int upperBound = atoi(argv[1]);
	auto primeNumbers = GeneratePrimeNumbersSet(upperBound);

	for (const auto primeNumber : primeNumbers)
	{
		cout << primeNumber << endl;
	}
	cout << "Total prime number in the range from 1 to " << upperBound << " : " << primeNumbers.size() << endl;
	return 0;
}
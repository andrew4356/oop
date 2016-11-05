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

	if (atoi(argv) < 0)
	{
		cout << "Invalid arguments." << endl;
		cout << "Numbers must be > 0" << endl;
		return true;
	}

	return false;
}

set<uint32_t> GeneratePrimeNumbersSet(int upperBound)
{
	vector<bool> numbers(upperBound + 1, false);
	set<uint32_t> primes;

	for (unsigned i = 1; i <= upperBound; i++)
	{
		numbers[i] = true;
	}

	if (upperBound > 1)
	{
		primes.emplace_hint(primes.end(), 2);
	}

	for (unsigned i = 2; ((i*i) <= upperBound); i++)
	{
		if (numbers[i])
		{
			for (unsigned j = (i*i); j <= upperBound; j += i)
			{
				if (numbers[j]) numbers[j] = false;
			}
		}
	}

	for (unsigned i = 3; i <= upperBound; i += 2)
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

	unsigned i = 0;
	auto upperBound = atoi(argv[1]);
	auto primes = GeneratePrimeNumbersSet(upperBound);

	for (const auto prime : primes)
	{
		cout << prime << endl;
		++i;
	}
	cout << "Total prime number in the range from 1 to " << upperBound << " : " << i << endl;
	return 0;
}
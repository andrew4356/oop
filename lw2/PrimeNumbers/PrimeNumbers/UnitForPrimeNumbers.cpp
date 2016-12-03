#include "stdafx.h"

using namespace std;
 
bool CheckOnTheCorrectnessOfTheArguments(int argc, char * argv[])
{
	if (argc != 2)
	{   
		string erorr = "Invalid arguments. \nprimes.exe <Number>";
		cout << erorr << endl;
		return true;
	}

	if (atoi(argv[1]) < 0)
	{
		string erorr = "Invalid arguments. \nThe number must be within a range from 1 to 100000000";
		cout << erorr << endl;
		return true;
	}

	return false;
}

set<uint32_t> GeneratePrimeNumbersSet(int upperBound)
{
	vector<bool> sieve(upperBound + 1, true); 
	set<uint32_t> primes;

	if (upperBound < 1)
	{
		return primes;
	}
	if (upperBound > 1)
	{
		primes.emplace_hint(primes.end(), 2);
	}

	for (int i = 2; (i * i <= upperBound); i++)
	{
		if (sieve[i])
		{
			for (int j = i * i; j <= upperBound; j += 2 * i)
			{
				sieve[j] = false; 
			}
		}  
	}

	for (int i = 3; i <= upperBound; i += 2)
	{
		if (sieve[i])
		{
			primes.emplace_hint(primes.end(), i);
		}
	}

	return primes;
}
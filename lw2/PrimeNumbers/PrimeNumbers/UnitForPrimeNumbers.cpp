#include "stdafx.h"

using namespace std;
 
bool CheckOnTheCorrectnessOfTheArguments(int argc, char* argv)
{
	if (argc != 2)
	{   
		string erorr = "Invalid arguments. \nprimes.exe <Number>";
		cout << erorr << endl;
		return true;
	}

	if (atoi(argv) <= 0)
	{
		string erorr = "Invalid arguments. \nThe number must be within a range from 1 to 100000000";
		cout << erorr << endl;
		return true;
	}



	return false;
}

set<uint32_t> GeneratePrimeNumbersSet(int upperBound)
{
	vector<bool> nums(upperBound + 1, true); // locationPrimes
	set<uint32_t> primes;

    nums[1] = false;

	if (upperBound > 1)
	{
		primes.emplace_hint(primes.end(), 2);
	}

	for (int i = 2; (i * i <= upperBound); i++)
	{
		if (nums[i])
		{
			for (int j = i * i; j <= upperBound; j += 2 * i)
			{
				nums[j] = false;
			}
		}
	}

	for (int i = 3; i <= upperBound; i += 2)
	{
		if (nums[i])
		{
			primes.emplace_hint(primes.end(), i);
		}
	}

	return primes;
}
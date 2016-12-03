#include "stdafx.h"
#include "UnitForPrimeNumbers.h"

using namespace std;

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
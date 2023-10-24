#include "CellOptions.h"
#include <cassert>
#include <stdlib.h>
using namespace std;

CellOptions::CellOptions()
{
	for (int i = 0; i < 9; i++) {
		options[i] = true;
	}

	totalOptions = 9;
}

/// <summary>
/// Removes an Option
/// </summary>
/// <param name="option">Option to remove (1-9)</param>
/// <returns>Total options remaining</returns>
int CellOptions::removeOption(int option)
{
	assert(option >= 1);
	assert(option <= 9);

	// if already false then just return totalOptions
	if (options[option - 1]) {
		options[option - 1] = false;
		totalOptions--;
	}

	return totalOptions;
}

/// <param name="option">Option to get (1-9)</param>
/// <returns>Option</returns>
bool CellOptions::getOption(int option) const
{
	if (option >= 1 && option <= 9)
		return options[option - 1];

	return false;
}

int CellOptions::setRandomOption(mt19937& gen)
{
	uniform_int_distribution<int> distribution(0, totalOptions - 1);
	int randomIndex = distribution(gen);
	int res = -1;

	// doing this roundabout loop thing cause i want all the other cells to be false
	for (int i = 0; i < 9; i++) {
		if (!options[i])
			continue;

		if (randomIndex != 0) {
			randomIndex--;
			options[i] = false;
			continue;
		}
		
		totalOptions = 1;
		options[i] = true;
		res = i + 1;
	}

	return res;
}

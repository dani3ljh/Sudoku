#include "CellOptions.h"
#include <cassert>
#include <stdlib.h>


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

int CellOptions::setRandomOption()
{
	// TODO: test this method :D
	int randomIndex = 1 + rand() % 9;
	int optionIndex = 0;
	while (randomIndex > 1) {
		optionIndex++;
		randomIndex--;
		options[optionIndex] = false;
	}
	totalOptions = 1;
	options[optionIndex] = true;
	return optionIndex;
}

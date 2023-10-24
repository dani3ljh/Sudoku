#pragma once
#include <random>
using namespace std;

class CellOptions
{
private:
	bool options[9];
	int totalOptions;
public:
	CellOptions();
	int removeOption(int option);
	bool getOption(int option) const;
	int setRandomOption(mt19937& gen);
};

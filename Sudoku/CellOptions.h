#pragma once

class CellOptions
{
private:
	bool options[9];
	int totalOptions;
public:
	CellOptions();
	int removeOption(int option);
	bool getOption(int option);
};

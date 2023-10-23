#pragma once
#include "CellOptions.h"
#include <ostream>
#include <vector>
using namespace std;

class SudokuBoard
{
private:
	int data[9][9];
	CellOptions options[9][9];
	bool updateOptions(int row, int col, int value);
	vector<pair<int, int>> findLeastOptions();
public:
	SudokuBoard();
	int getRows() const { return 9; }
	int getCols() const { return 9; }
	int getElement(int row, int col) const;
	bool generateBoard();
	friend ostream& operator<<(ostream& os, const SudokuBoard& board);
};

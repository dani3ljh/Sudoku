#include "SudokuBoard.h"
#include <vector>
using namespace std;

SudokuBoard::SudokuBoard()
{
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			data[row][col] = 0;
			options[row][col] = CellOptions::CellOptions();
		}
	}
}

int SudokuBoard::getElement(int row, int col) const
{
	if (row >= 0 && row < 9 && col >= 0 && col < 9)
		return data[row][col];
	else
		return -1;
}

bool SudokuBoard::generateBoard()
{
	while (true) {
		vector<pair<int, int>> leastOptionCells = findLeastOptions();

		if (leastOptionCells.empty())
			break;

		int randIndex = rand() % leastOptionCells.size();
		pair<int, int> randPoint = leastOptionCells[randIndex];
		
		
	}

	return true;
}

/// <summary>
/// Updates options of each cell
/// </summary>
/// <param name="row">Row of updated cell</param>
/// <param name="col">Column of updated cell</param>
/// <param name="value">Value of the updated cell</param>
/// <returns>Whether update is successful</returns>
bool SudokuBoard::updateOptions(int row, int col, int value)
{
	// value will be checked in the removeOption method
	for (int iCol = 0; iCol < 9; iCol++) {
		if (iCol == col)
			continue;

		if (options[row][iCol].removeOption(value) == -1)
			return false;
	}

	for (int iRow = 0; iRow < 9; iRow++) {
		if (iRow == row)
			continue;

		if (options[iRow][col].removeOption(value) == -1)
			return false;
	}

	return true;
}

/// <summary>
/// Finds cells with least options
/// </summary>
/// <returns>Vector of cell pairs</returns>
vector<pair<int, int>> SudokuBoard::findLeastOptions()
{
	vector<pair<int, int>> res;
	int minOptions = 9;

	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			if (data[row][col] != 0)
				continue;

			int optionsNum = 0;
			for (int option = 1; option <= 9; option++) {
				if (options[row][col].getOption(option))
					optionsNum++;
			}

			if (optionsNum > minOptions)
				continue;

			if (optionsNum < minOptions) {
				res.clear();
				res.emplace_back(row, col);
				minOptions = optionsNum;
			} else {
				res.emplace_back(row, col);
			}
		}
	}

	return res;
}

ostream& operator<<(ostream& os, const SudokuBoard& board)
{
	os << "{" << endl;
	for (int row = 0; row < 9; row++) {
		os << "\t{";
		for (int col = 0; col < 9; col++) {
			os << board.getElement(row, col) << (col < 8 ? ", " : "");
		}
		os << "}," << endl;
	}
	return os << "}";
}

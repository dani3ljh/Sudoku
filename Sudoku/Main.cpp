#include <iostream>
#include "SudokuBoard.h"
using namespace std;

int main()
{
	SudokuBoard board = SudokuBoard::SudokuBoard();

	CellOptions opts = CellOptions::CellOptions();

	opts.removeOption(1);
	opts.removeOption(3);
	opts.removeOption(7);

	cout << opts.setRandomOption() << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

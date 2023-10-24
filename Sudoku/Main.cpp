#include <iostream>
#include "SudokuBoard.h"
#include <cstdlib>
using namespace std;

int main()
{
	mt19937 gen(random_device{}());

	CellOptions opts = CellOptions::CellOptions();

	opts.removeOption(1);
	opts.removeOption(3);
	opts.removeOption(4);
	opts.removeOption(5);
	opts.removeOption(7);
	opts.removeOption(9);

	cout << opts.setRandomOption(gen) << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

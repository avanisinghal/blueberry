#include <bits/stdc++.h>
using namespace std;
#define missing 0
#define N 9
bool missinglocation(int sudoku[N][N],int& row, int& col);
bool check(int sudoku[N][N], int row,int col, int num);
bool Solver(int sudoku[N][N])
{
	int row, col;
	if (!missinglocation(sudoku, row, col))return true;
	for (int num = 1; num <= 9; num++)
	{
		if (check(sudoku, row, col, num))
		{
			sudoku[row][col] = num;
			if (Solver(sudoku))
				return true;
			sudoku[row][col] = missing;
		}
	}
	return false;
}
bool missinglocation(int sudoku[N][N],int& row, int& col)
{
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (sudoku[row][col] == missing)
				return true;
	return false;
}
bool Checkrow(int sudoku[N][N], int row, int num)
{
	for (int col = 0; col < N; col++)
		if (sudoku[row][col] == num)
			return true;
	return false;
}
bool Checkcol(int sudoku[N][N], int col, int num)
{
	for (int row = 0; row < N; row++)
		if (sudoku[row][col] == num)
			return true;
	return false;
}
bool Checkbox(int sudoku[N][N], int boxStartRow,
			int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (sudoku[row + boxStartRow]
					[col + boxStartCol] ==num)
				return true;
	return false;
}
bool check(int sudoku[N][N], int row, int col, int num)
{
	return !Checkrow(sudoku, row, num)
		&& !Checkcol(sudoku, col, num)
		&& !Checkbox(sudoku, row - row % 3,col - col % 3, num)
		&& sudoku[row][col] == missing;
}
void printGrid(int sudoku[N][N])
{
    cout << "=======" << endl;
    cout << "Solution : " << endl;
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
			cout << sudoku[row][col] << " ";
		cout << endl;
	}
}
int main()
{
    cout << "Hello! \nPlease enter the Sudoku to be solved.\nInput the blank boxes as 0. "<< endl;
	int sudoku[N][N];
	for(int i = 0;i < N;i++)for(int j = 0;j < N;j++)cin >> sudoku[i][j];
	if (Solver(sudoku) == true)printGrid(sudoku);
	else cout << "No solution exists" << endl;
	return 0;
}

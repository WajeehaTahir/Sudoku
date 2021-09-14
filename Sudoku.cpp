//8 Feb 2021
//day 4
// <0 wrong input, 1-9 system values, >9 user values
#include <iostream>
#include <ctime>
#include <fstream>
#include <windows.h>
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>
using namespace std;
void main();
void problemBoard(int[9][9], int);
void display(int[9][9], int[9][9], int);
void play(int[9][9], int[9][9], int);
void cont(int[9][9], int[9][9], int);
void saveGame(int[9][9], int[9][9], int);
void end(int);
bool fileExists()
{
	if (experimental::filesystem::exists("Solution.txt") && experimental::filesystem::exists("Problem.txt") 
		&& experimental::filesystem::exists("Moves.txt"))
	{
		return true;
	}
	else
	{
		return false;
	}
}
void loadGame()
{
	int solution[9][9], problem[9][9], count;
	fstream loadSolution;
	loadSolution.open("Solution.txt", ios::in);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			loadSolution >> solution[i][j];
		}
	}
	loadSolution.close();
	fstream loadProblem;
	loadProblem.open("Problem.txt", ios::in);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			loadProblem >> problem[i][j];
		}
	}
	loadProblem.close();
	fstream countMoves;
	countMoves.open("Moves.txt", ios::in);
	countMoves >> count;
	countMoves.close();
	display(problem, solution, count);
}
void solutionBoard()
{
	cout << "Enter your difficulty\n";
	cout << "1 - Easy\n";
	cout << "2 - Intermediate\n";
	cout << "3 - Hard\n";
	int diff, hint;
	cin >> diff;
	if (diff == 1)
	{
		int solution[9][9] =
		{
			{4,3,5,2,6,9,7,8,1},
			{6,8,2,5,7,1,4,9,3},
			{1,9,7,8,3,4,5,6,2},
			{8,2,6,1,9,5,3,4,7},
			{3,7,4,6,8,2,9,1,5},
			{9,5,1,7,4,3,6,2,8},
			{5,1,9,3,2,6,8,7,4},
			{2,4,8,9,5,7,1,3,6},
			{7,6,3,4,1,8,2,5,9}
		};
		cout << "Enter the number of hints (60-80)\n";
		cin >> hint;
		if (hint >= 60 && hint <= 80)
		{
			problemBoard(solution, hint);
		}
		else
		{
			cout << "Change difficulty or enter valid number of hints\n";
			solutionBoard();
		}
	}
	if (diff == 2)
	{
		int solution[9][9] =
		{
			{1,4,3,9,8,7,6,5,2},
			{8,2,9,6,1,5,4,7,3},
			{5,7,6,2,4,3,8,9,1},
			{2,5,1,4,6,9,7,3,8},
			{3,8,7,1,5,2,9,4,6},
			{6,9,4,7,3,8,2,1,5},
			{9,1,8,5,7,6,3,2,4},
			{4,3,2,8,9,1,5,6,7},
			{7,6,5,3,2,4,1,8,9}
		};
		cout << "Enter the number of hints (40-59)\n";
		cin >> hint;
		if (hint >= 40 && hint <= 59)
		{
			problemBoard(solution, hint);
		}
		else
		{
			cout << "Change difficulty or enter valid number of hints\n";
			solutionBoard();
		}
	}
	if (diff == 3)
	{
		int solution[9][9] =
		{
			{5,3,7,4,2,1,8,9,6},
			{6,9,4,8,3,7,2,1,5},
			{2,1,8,9,6,5,7,4,3},
			{1,6,9,3,8,4,5,2,7},
			{8,2,5,1,7,9,3,6,4},
			{7,4,3,6,5,2,1,8,9},
			{4,8,6,7,1,3,9,5,2},
			{9,7,2,5,4,8,6,3,1},
			{3,5,1,2,9,6,4,7,8}
		};
		cout << "Enter the number of hints (20-39)\n";
		cin >> hint;
		if (hint >= 20 && hint <= 39)
		{
			problemBoard(solution, hint);
		}
		else
		{
			cout << "Change difficulty or enter valid number of hints\n";
			solutionBoard();
		}
	}
}
void problemBoard(int solution[9][9], int hint)
{
	int problem[9][9], count = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			problem[i][j] = solution[i][j];
		}
	}
	srand(time(NULL));
	for (int i = 0; i < 81 - hint; i++)
	{
		int x = rand() % 9, y = rand() % 9;
		if (problem[x][y] != 0)
		{
			problem[x][y] = 0;
		}
		else
		{
			i--;
		}
	}
	display(problem, solution, count);
}
void display(int problem[9][9], int solution[9][9], int count)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "       * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "         1   2   3   4   5   6   7   8   9" << endl;
	cout << "       * * * * * * * * * * * * * * * * * * *" << endl;
	int n = 1;
	for (int i = 0; i < 9; i++)
	{
		cout << "       -------------------------------------" << endl;
		cout << " * " << n << " *";
		for (int j = 0; j < 9; j++)
		{
			if (problem[i][j] != 0 && problem[i][j] > 0)
			{
				if (problem[i][j] > 9)							//correct input by user
				{
					problem[i][j] = problem[i][j] - 9;			//to print the right value
					cout << " | ";
					SetConsoleTextAttribute(hConsole, 3);		//light aqua
					cout << problem[i][j];
					problem[i][j] = problem[i][j] + 9;			//to keep the color changed
					SetConsoleTextAttribute(hConsole, 7);		//white
				}
				else
				{
					cout << " | " << problem[i][j];
				}
			}
			else
			{
				if (problem[i][j] < 0)							//wrong input
				{
					cout << " | ";
					SetConsoleTextAttribute(hConsole, 4);		//red 
					cout << "x";
					SetConsoleTextAttribute(hConsole, 7);		//back to white
				}
				else
				{
					cout << " | " << " ";						//empty cell i.e zero
				}
			}
		}
		n++;
		cout << " | " << endl;
	}
	cout << "       -------------------------------------" << endl;
	cont(problem, solution, count);
}
void cont(int problem[9][9], int solution[9][9], int count)
{
	int minusCount = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (problem[i][j] < 0 || problem[i][j] == 0)
			{
				minusCount++;								/*if theres an empty cell or a
															wrong input count increases*/
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (minusCount == 0)							//if count is zero board is complete
			{
				if (problem[i][j] > 9)
				{
					problem[i][j] = problem[i][j] - 9;		/*changing right answers back to test
															if problem matches solution*/
				}
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (problem[i][j] != solution[i][j])
			{
				play(problem, solution, count);
			}
		}
	}
	end(count);
}
void play(int problem[9][9], int solution[9][9], int count)
{
	int x, y, input;
	cout << "Enter -1 to exit\n";
	cout << "Enter row (1-9): ";
	cin >> x;
	if (x == -1)
	{
		saveGame(problem, solution, count);
	}
	cout << "Enter column (1-9): ";
	cin >> y;
	if (problem[x-1][y-1] > 0 && problem[x-1][y-1] < 9)
	{
		cout << "Cannot alter the board\n";
		play(problem, solution, count);
	}
	cout << "Enter value (1-9): ";
	cin >> input;
	count++;
	if (input == solution[x - 1][y - 1])
	{
		problem[x - 1][y - 1] = input + 9;				//user input
	}
	else
	{
		problem[x - 1][y - 1] = -input;
		cout << "\n            ******** Wrong input ********\n\n";
	}
	display(problem, solution, count);
}
void saveGame(int problem[9][9], int solution[9][9], int count)
{
	cout << "Do you want to save the game? y / n\n";
	char x;
	cin >> x;
	if (x == 'y' || x == 'Y')
	{
		fstream saveSolution;
		saveSolution.open("Solution.txt", ios::out);
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				saveSolution << solution[i][j] << " ";
			}
			saveSolution << endl;
		}
		saveSolution.close();
		fstream saveProblem;
		saveProblem.open("Problem.txt", ios::out);
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				saveProblem << problem[i][j] << " ";
			}
			saveProblem << endl;
		}
		saveProblem.close();
		fstream countMoves;
		countMoves.open("Moves.txt", ios::out);
		countMoves << count;
		countMoves.close();
		exit(1);
	}
	else
	{
		cout << "Do you want to start a new game? y / n\n";
		char y;
		cin >> y;
		if (y == 'y' || y == 'Y')
		{
			main();
		}
		else
		{
			exit(1);
		}
	}
}
void end(int count)
{
	cout << "Game end\n";
	cout << "Number of moves: " << count << endl;
	char repeat;
	cout << "Do you want to play again? y / n\n";
	cin >> repeat;
	if (repeat == 'y' || repeat == 'Y')
	{
		main();
	}
	else
	{
		exit(1);
	}
}
void main()
{
	cout << "Load game or start a new one\n";
	cout << "1 - New Game\n";
	cout << "2 - Load Game\n";
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		solutionBoard();
	}
	if (choice == 2)
	{
		int x = fileExists();
		if (x == 1)
		{
			loadGame();
		}
		else
		{
			cout << "Saved game does not exist\n";
			cout << "Start a new game\n";
			main();
		}
	}
}
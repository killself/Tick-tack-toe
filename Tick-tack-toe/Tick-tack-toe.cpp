#include <iostream>
#include <Windows.h> 
#include <ctime>


const int FIELD_SIZE = 3;

void drawingPlayingField(char arr[FIELD_SIZE][FIELD_SIZE])
{
	std::cout << "\n -------------\n";
	for (int i = 0; i < FIELD_SIZE; ++i)
	{		
		for (int j = 0; j < FIELD_SIZE; ++j)
		{
			std::cout << " | " << arr[i][j];
		}
		std::cout << " |\n -------------\n";
	}

}

bool winCheck(char arr[FIELD_SIZE][FIELD_SIZE], int count, char symb)
{

	if (count < 5) { return false; }	

	if (arr[0][0] == symb && arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2]) { return true; }
	if (arr[1][0] == symb && arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2]) { return true; }
	if (arr[2][0] == symb && arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2]) { return true; }

	if (arr[0][0] == symb && arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0]) { return true; }
	if (arr[0][1] == symb && arr[0][1] == arr[1][1] && arr[0][1] == arr[2][1]) { return true; }
	if (arr[0][2] == symb && arr[0][2] == arr[1][2] && arr[0][2] == arr[2][2]) { return true; }

	if (arr[0][0] == symb && arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]) { return true; }
	if (arr[2][0] == symb && arr[2][0] == arr[1][1] && arr[2][0] == arr[0][2]) { return true; }

	return false;

}

void playerMove(char arr[FIELD_SIZE][FIELD_SIZE], char symb)
{

	int i = 0;
	int j = 0;

	while (true)
	{
		std::cout << "\nEnter row and column (separeted by space): ";
		std::cin >> i >> j;

		if (i > 3 || i < 1 || j > 3 || j < 1)
		{
			std::cout << "\nWrong cell! Try again.\n";
			continue;
		}
		else if (arr[i - 1][j - 1] == ' ')
		{
			arr[i - 1][j - 1] = symb;
			break;
		}

		std::cout << "\nWrong cell! Try again.\n";
	}
}

void computerMove(char arr[FIELD_SIZE][FIELD_SIZE], char symb)
{

	for (int k = 0; k < 8; ++k)
	{
		std::cout << ". ";
		Sleep(100);
	}
	std::cout << "\n";

	while (true)
	{
		int i = rand() % 3 + 1;
		int j = rand() % 3 + 1;

		if (arr[i - 1][j - 1] == ' ')
		{
			arr[i - 1][j - 1] = symb;
			break;
		}
	}

}


int main()
{

	std::string player_1 = "You";
	std::string player_2 = "Computer";
	int menu = 0;
	int count = 0;
	bool computerPlay = false;
	char playingField[FIELD_SIZE][FIELD_SIZE] = { { ' ', ' ', ' ' }, {' ', ' ', ' '}, {' ', ' ', ' '} };


	srand(time(NULL));

	std::cout << "*********************************************************************************\n";
	std::cout << "\t\t\tWELCOME TO TICK-TACK-TOE v0.01\n";
	std::cout << "*********************************************************************************\n\n";

	

	while (true)
	{		
		std::cout << "\nMENU:\n\n";
		std::cout << "1. Player vs Player mode\n";
		std::cout << "2. Player vs Computer mode\n";
		std::cout << "3. Exit\n";
		std::cin >> menu;

		if (menu > 0 && menu < 4)
		{
			break;
		}
		system("cls");
	}

	switch (menu)
	{
	case 1:
		computerPlay = false;
		player_1 = "Player 1";
		player_2 = "Player 2";
		break;
	case 2:
		computerPlay = true;
		break;
	case 3: 	
		std::cout << "\nGoodbye!\n\n";
		return 0;
	}
	
	while (true)
	{
		system("cls");
		drawingPlayingField(playingField);
		std::cout << "\nPlayer 1 move\n";
		playerMove(playingField, 'x');
		++count;
		drawingPlayingField(playingField);

		if (winCheck(playingField, count, 'x'))
		{
			std::cout << "\n\n****************************************************\n";
			std::cout << "\t\t" << player_1 << " wins!\n\t\tGame over!\n";
			std::cout << "****************************************************\n\n";
			system("pause");
			return 0;
		}
		else if (count == 9)
		{
			std::cout << "\nThis time a draw.\nTry again!\n\n";
			system("pause");
			return 0;
		}
		

		if (computerPlay)
		{
			std::cout << "\nComputer move\n";
			computerMove(playingField, 'o');			
		}
		else
		{
			std::cout << "\nPlayer 2 move\n";
			playerMove(playingField, 'o');
		}
		drawingPlayingField(playingField);

		++count;

		if (winCheck(playingField, count, 'o'))
		{
			std::cout << "\n\n****************************************************\n";
			std::cout << "\t\t" << player_2 << " wins!\n\t\tGame over!\n";
			std::cout << "****************************************************\n\n";			
			system("pause");
			return 0;
		}

		Sleep(500);
	}
	
}
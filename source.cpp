#include <iostream>
#include <ctime>
#include <cstdlib>

int numGen();

bool checkRow(int board[9][9], int i, int j);

int main(int argc, char *argv[])
{
	srand((unsigned)time(NULL));

	int board[9][9] = { 0 };
	int boardCount = 1;
	unsigned int counter = 0;

	checkRow(board, 1, 1);

	std::cout << "First board:" << std::endl;

	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			board[i][j] = numGen();
			while(checkRow(board, i, j))
			{	
				board[i][j] = numGen();
				counter++;
				if (counter == 25)
				{
					i = 0;
					j = 0;
					for (int k = 0; k < 9; k++)
					{
						for (int l = 0; l < 9; l++)
						{
							board[k][l] = 0;
						}
					}
					std::cout << "\n\n\nNext Board:" << std::endl;
					boardCount++;
				}
			}
			counter = 0;

			std::cout << board[i][j] << ", ";
			
		}
		std::cout << std::endl;
	}

	std::cout << "Finished" << std::endl;
	std::cout << "Boards generated: " << boardCount << std::endl;
	std::cin.ignore();
	return 0;
} 

int numGen()
{
	int value = (rand()%9)+1;
	return value;
}

bool checkRow(int board[9][9], int i, int j)
{

	for(int k = 0; k < 9; k++)
	{
		if(j == k)
		{
			continue;
		}
		else if(board[i][j] == board[i][k])
		{
			return true;
		}
	}

	for(int k = 0; k < 9; k++)
	{
		if (i == k)
		{
			continue;
		}
		else if(board[i][j] == board[k][j])
		{
			return true;
		}
	}

	return false;
}
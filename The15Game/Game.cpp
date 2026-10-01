// Patrick Murray
// CIS-2542-NET01
// Homework 7

// Game.cpp - Implementation for the Game class

#include "Game.h"
#include <iostream>
#include <algorithm>

Game::Game()
	: choices{1, 2, 3, 4, 5, 6, 7, 8, 9},
	  isPlayerOnesTurn(true)
{
	// Nothing here...
}

bool Game::IsGameOver() const
{
	if (IsWinner(playerOnePicks) == true || IsWinner(playerTwoPicks) == true)
	{
		return true;
	}

	if (choices.empty())
	{
		return true;
	}

	return false;
}

int Game::GetGameStatus() const
{
	// set local bools to reduce function calls
	bool playerOneWins = IsWinner(playerOnePicks);
	bool playerTwoWins = IsWinner(playerTwoPicks);

	// Player one win
	if (playerOneWins == true)
	{
		return 1;
	}

	// Player 2 win
	if (playerTwoWins == true)
	{
		return 2;
	}

	// Draw status
	if (choices.empty())
	{
		return 0;
	}

	// Active game status
	return -1;
}

// Output operator: "<<"
std::ostream& operator<<(std::ostream& ostr, const Game& rhs)
{
	ostr << std::endl;
	ostr << "Choices Remaining:    ";

	// Choices left
	for (int i : rhs.choices)
	{
		ostr << i << ' ';
	}

	ostr << std::endl;
	ostr << "Player One's Choices: ";

	// Player One's choices
	for (int i : rhs.playerOnePicks)
	{
		ostr << i << ' ';
	}

	ostr << std::endl;
	ostr << "Player Two's Choices: ";

	// Player Two's choices
	for (int i : rhs.playerTwoPicks)
	{
		ostr << i << ' ';
	}

	ostr << std::endl;
	
	return ostr;
}

void Game::MakePick()
{
	if (IsGameOver() == true)
	{
		std::cout << "GAME IS OVER...  NO MORE PICKS TO MAKE!" << std::endl;
		return;
	}

	// Print current game stats
	std::cout << *this;

	// Player one's turn
	if (isPlayerOnesTurn == true)
	{
		int pick;
		std::cout << "Player One's Pick?    ";
		std::cin >> pick;

		// Find the vector element of the pick 
		std::vector<int>::iterator iter = std::find(choices.begin(), choices.end(), pick);
		
		// Validate that the pick is available
		while (iter == choices.end())
		{
			std::cout << "Player One's Pick?    ";
			std::cin >> pick;

			// Validate that the pick is from 1 to 9
			while (pick < 1 || pick > 9)
			{
				std::cout << "Player One's Pick?    ";
				std::cin >> pick;
			}

			iter = std::find(choices.begin(), choices.end(), pick);
		}

		// Add the pick to player one's choices
		playerOnePicks.push_back(pick);
		
		// Erase the pick from the current choices
		choices.erase(iter);

		// Switch to player two's turn
		isPlayerOnesTurn = false;
		return;
	}

	// Player two's turn
	if (isPlayerOnesTurn == false)
	{
		int pick;
		std::cout << "Player Two's Pick?    ";
		std::cin >> pick;

		// Find the vector element of the pick 
		std::vector<int>::iterator iter = std::find(choices.begin(), choices.end(), pick);

		// Validate that the pick is available
		while (iter == choices.end())
		{
			std::cout << "Player Two's Pick?    ";
			std::cin >> pick;

			// Validate that the pick is from 1 to 9
			while (pick < 1 || pick > 9)
			{
				std::cout << "Player Two's Pick?    ";
				std::cin >> pick;
			}

			iter = std::find(choices.begin(), choices.end(), pick);
		}

		// Add the pick to player two's choices
		playerTwoPicks.push_back(pick);

		// Erase the pick from the current choices
		choices.erase(iter);

		// Switch to player one's turn
		isPlayerOnesTurn = true;
		return;
	}
}

bool Game::IsWinner(const std::vector<int>& PICKS) const
{
	if (PICKS.size() < 3)
	{
		return false;
	}

	// Check all 3-pick combinations in PICKS to see if any add up to 15
	for (int i = 0; i < (PICKS.size() - 2); ++i)
	{
		for (int j = (i + 1); j < (PICKS.size() - 1); ++j)
		{
			for (int k = (j + 1); k < PICKS.size(); ++k)
			{
				if (PICKS[i] + PICKS[j] + PICKS[k] == 15)
					return true;
			}
		}
	}

	return false;
}
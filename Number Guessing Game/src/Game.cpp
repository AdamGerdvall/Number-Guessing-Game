#include "Game.h"

Game::Game(/*int newLives, int newScore, int newNumber, int newDiff*/)
{
	//int lives = newLives;
	//int score = newScore;
	//int diff = newDiff;
	//int number = newNumber;
}

Game::~Game()
{

}

void Game::Startup()
{
	std::cout << "Enter Difficulty:" << "\n";
	std::cout << "Easy: 1" << "\n";
	std::cout << "Normal: 2" << "\n";
	std::cout << "Hard: 3" << "\n";

	while(playing)
	try
	{
		int i;

		std::string sGameDiff;
		std::getline(std::cin, sGameDiff);

		std::istringstream s(sGameDiff);
		if (s >> i)
		{			
			if (i<=3 && i>=1)
			{
				gameDiff = stoi(sGameDiff);
				std::cout << "You have " << GenerateLives() << " tries to guess a number between 1 and 100" << "\n";
				Run();
				break;
			}
		}
		throw sGameDiff;
	}
	catch (std::string sGameDiff)
	{
		std::cout << "Please Input an integer between 1 and 3." << "\n";
	}
}

void Game::Run()
{
	while(playing)
	{ 
		lives = GenerateLives();
		GenerateNumber();
		inGame = true;
		while (inGame)
		{
			CheckInput();
		}
	}
}

void Game::GenerateNumber()
{
	guessNum = rand() % 100 + 1;
	return;
}

int Game::GenerateLives()
{
	switch (gameDiff)
	{
	case 1:
		return 10;
		break;
	case 2:
		return 7;
		break;
	case 3:
		return 5;
		break;
	default:
		std::cout << "Error.GenerateLives" << "\n";
		return 0;
		break;
	}
}

void Game::CheckInput()
{
	while (true)
	{
		try
		{
			int i;

			std::string sGuess;
			std::getline(std::cin, sGuess);

			std::istringstream s(sGuess);
			if (s >> i)
			{
				if (i <= 100 && i >= 1)
				{
					int guess = stoi(sGuess);
					if (guess < guessNum)
					{
						std::cout << "Guess is lower than number." << "\n";
						WrongGuess();
						return;
					}
					else if (guess > guessNum)
					{
						std::cout << "Guess is higher than number." << "\n";
						WrongGuess();
						return;
					}
					else if (guess = guessNum)
					{
						
						CorrectGuess();
						return;
					}
					else
					{
						std::cout << "Error.CheckInput" << "\n";
						return;
					}
				}
			}
			throw sGuess;
		}
		catch (std::string sGuess)
		{
			std::cout << "Please Input an integer between 1 and 100." << "\n";
		}
	}
}

void Game::CorrectGuess()
{
	gameScore = gameScore + 1;
	std::cout << "\033[2J\033[1;1H";
	std::cout << "Guess is Correct! Try to guess the next number. Your current score is " << gameScore << "\n";
	inGame = false;
	return;
}

void Game::WrongGuess()
{
	lives--;
	if (lives == 0)
	{
		ResetGame();
	}
	return;
}

void Game::ResetGame()
{
	std::cout << "\n" "You Lost, The number was " << guessNum << "\n" "Your score was " << gameScore << "!" << "\n";
	std::cout << "Would you like to play again? (y/n)" << "\n";
	
	std::string str;
	std::getline(std::cin, str);

	if (str == "y")
	{
		std::cout << "\033[2J\033[1;1H";
		Startup();
	}
	else
	{
		playing = false;
		inGame = false;
		return;
	}
}

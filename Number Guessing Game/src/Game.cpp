#include "Game.h"

Game::Game(int newNumber)
{
	number = newNumber;
}

Game::~Game()
{
	std::cout << "Object destroyed" << "\n";
}

void Game::Run()
{
	std::cout << ""
}
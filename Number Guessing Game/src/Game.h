#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Game
{
public:
	Game();

	~Game();

	void Run();
	void Startup();
	void GenerateNumber();
	int GenerateLives();
	void CheckInput();
	void CorrectGuess();
	void WrongGuess();
	void ResetGame();
	
	int lives;
	int gameScore = 0;
	int gameDiff {};
	int guessNum{};
	bool playing = true;
	bool inGame{};

private:
};
#pragma once

#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

int randomNumber()
{
	std::random_device rd;
	std::mt19937 engine(rd());
	std::uniform_int_distribution<int> dist(0, 49);
	return dist(engine);
}

std::string chooseHangmanName()
{
	std::string filename = "Hangman Words.txt";
	std::ifstream cin(filename);
	std::string currentLine;

	std::vector<std::string> hangmanWords;

	if (!cin.is_open())
	{
		return "1";
	}

	while (std::getline(cin, currentLine))
	{
		hangmanWords.push_back(currentLine);
	}

	int arrayValue = randomNumber();

	return hangmanWords[arrayValue];

}
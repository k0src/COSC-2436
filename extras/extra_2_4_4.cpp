#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

// Generate num randomly.
// Player guesses number.
// If too high or too low, say that
// If guessed before, say that
// If right, end and say how many tries
// Use recursion

void guessingGameLoop(int randomNumber, std::vector<int>& guesses, int guess, int tries = 1) {
	if (guess == randomNumber) {
		std::cout << "You guessed the number " << randomNumber << " in " << tries << " tries!" << std::endl;
		return;
	}

	if (std::find(guesses.begin(), guesses.end(), guess) != guesses.end()) {
		std::cout << "You have already guessed " << guess << "." << std::endl;
	}

	guesses.push_back(guess);

	std::cout << "Guess a number 1-20: " << std::endl;
	std::cin >> guess;

	guessingGameLoop(randomNumber, guesses, guess, tries + 1);
}

void guessingGame(int randomNumber) {
	std::vector<int> guesses;
	int guess;
	std::cout << "Guess a number 1-20: " << std::endl;
	std::cin >> guess;
	guessingGameLoop(randomNumber, guesses, guess);
}

int main()
{
	std::srand(std::time(0));
	int randomNumber = (std::rand() % 20) + 1;
	std::cout << randomNumber << std::endl;
	guessingGame(randomNumber);
	return 0;
}
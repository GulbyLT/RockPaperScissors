#include <iostream>
#include <thread>
#include <random>

void tie();
void win();
void lose();

char youPick()
{
	std::cout << "Which one? Type R/P/S \n";
	char choice;
	std::cin >> choice;

	return choice;
}

char pcPick()
{
	std::cout << "I picked too!";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> distribution(0, 4);
	int number = distribution(gen);
	
	if (number == 1) {
		return 'R';
	}
	else if (number == 2) {
		return 'P';
	}
	else return 'S';

}


int main()
{
start:
	char yourChoice = youPick();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	char pcChoice = pcPick();
	//std::cout << " " << pcChoice << "!";

	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "\nROCK!\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "PAPER!\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "SCISSORS!\n";
	std::cout << "I picked " << pcChoice << "\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));

	if (yourChoice == pcChoice) {
		tie();
	}
	else if (yourChoice == 'S' && pcChoice == 'P' || yourChoice == 'R' && pcChoice == 'S' || yourChoice == 'P' && pcChoice == 'R') {
		win();
	}
	else if (yourChoice == 'P' && pcChoice == 'S' || yourChoice == 'S' && pcChoice == 'R' || yourChoice == 'R' && pcChoice == 'P') {
		lose();
	}

	
}

void lose()
{
	std::cout << "You lose!\n";
	std::cout << "Let's play again!\n";
	main();
}

void win()
{
	std::cout << "You win!\n";
	std::cout << "Let's play again!\n";
	main();

}

void tie()
{
	std::cout << "It's a tie! I picked the same thing!\n";
	std::cout << "Let's play again!\n";
	main();
}


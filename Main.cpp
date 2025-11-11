/* Grant Smith
C++ semester year- 2025
Lab- Lba5 Number Guessing Game
Lab description- Create a number guessing game, with 20 attemptes a game, will display various messages depending on if you win or lose, 
					allow user to end the game or play another one, and will display number of wins and loses after ending the game.*/
#include<iostream>
#include<iomanip>

int getranNum(int min_, int max_); //declaring functions I will use.
int getranMes(int min2_ ,int max2_);
int main()
{
	srand(static_cast<unsigned int>(time(0)));
	int min = 0;	//Setting the range for random number selection.
	int max = 100;
	int maxattempts = 20;
	int attempt = 0;								//assigning the different values for the variables I will use.
	int win = 0;
	int lose = 0;
	int min2 = 1;	//Setting range for message selection.
	int max2 = 10;
	char Tryagain = 'e';	//Assigning variable being used to start another game or end program.
	do
	{				//Explaining the game to user so they know what to do.
		std::cout << "Welcome to the number guessing game! You have 20 chances to guess the randomly selected number " << std::endl;
		std::cout << "The number selected will be between 0 and 100, now please make your guess \n";
		int guess = -1;
		int attempt = 0;
		int ranNum = getranNum(min, max); // choses the random number for you to guess.

		while (attempt < maxattempts)	//Setting while loop so that it will stop if you guess the right number or use all your attempts.
		{
			std::cout << "Your "<< attempt +1 << " guess\n";
			
			std::cin >> guess;
			if (!(guess)) //Fail safe in case user accidently enters in a non number.
			{
				std::cout << "Invaild input start program again, and make sure to only enter in numbers please." << std::endl;
				return 0;
			}
			if (guess > 100 || guess < 0)
			{
				std::cout << "number outside of range(0 to 100), please keep within range.\n";
			}
			if (guess == ranNum) //For if you guess the right number.
			{
				break;
			}
			attempt = attempt + 1;
		}
		int messageNum = getranMes(min2, max2);
		if (guess == ranNum)
		{										//What will display if user wins a game.
			switch (messageNum)
			{
			case 1: std::cout << "good job" << std::endl;
				break;
			case 2: std::cout << "Nice, do it again" << std::endl;
				break;
			case 3: std::cout << "Wow, you're doing great" << std::endl;
				break;
			case 4: std::cout << "That what I'm talking about, nice. " << std::endl;
				break;
			case 5: std::cout << " Great, now let's get a winning streak going" << std::endl;
				break;
			case 6: std::cout << "Alright Alright Alright that's how its done " << std::endl;
				break;
			case 7: std::cout << "Brillient" << std::endl;
				break;
			case 8: std::cout << "Congradulations! " << std::endl;
				break;
			case 9: std::cout << "Most impressive " << std::endl;
				break;
			case 10: std::cout << "Absoulutely outstanding " << std::endl;
				break;
			}
			win = win + 1; //increases the number of wins to be displayed later.
		}
		else
		{										//What will display if user loses a game.
			lose = lose + 1; //increases number of loses to be displayed later.
			switch (messageNum)
			{
			case 1: std::cout << "Maybe another try" << std::endl;
				break;
			case 2: std::cout << "try again, but think about it a bit more" << std::endl;
				break;
			case 3: std::cout << "well everyone fails every now and again" << std::endl;
				break;
			case 4: std::cout << "(inhale).....(exhale), you tried at least" << std::endl;
				break;
			case 5: std::cout << "Come on man, almost had it " << std::endl;
				break;
			case 6: std::cout << "Oof you ran out of guesses " << std::endl;
				break;
			case 7: std::cout << "Too bad, so sad " << std::endl;
				break;
			case 8: std::cout << "Better luck next time " << std::endl;
				break;
			case 9: std::cout << "So close yet so far " << std::endl;
				break;
			case 10: std::cout << "Maybe next game " << std::endl;
				break;
			}
		}
		if (guess == ranNum || attempt == maxattempts)
		{													//asking if user wants to play another game.
			switch (messageNum)
			{
			case 1: std::cout << "Would you like to try your luck once again" << std::endl;
				break;
			case 2: std::cout << "Go for another round? " << std::endl;
				break;
			case 3: std::cout << "Keep going perhaps? " << std::endl;
				break;
			case 4: std::cout << "Like another shot? " << std::endl;
				break;
			case 5: std::cout << "Ready for another game? " << std::endl;
				break;
			case 6: std::cout << "Game is ready... care to play again? " << std::endl;
				break;
			case 7: std::cout << "Feeling lucky for next game? " << std::endl;
				break;
			case 8: std::cout << "Had enough fun yet? " << std::endl;
				break;
			case 9: std::cout << "Up for another try? " << std::endl;
				break;
			case 10: std::cout << "Do you wish to keep playing " << std::endl;
				break;
			}
			std::cout << "Enter Y for yes and N for no " << std::endl; //Allows user to either play game again or end game.
			std::cin >> Tryagain;
		}
    } while (Tryagain == 'Y' || Tryagain == 'y');

	std::cout << "Here are your results: " << win << " wins and " << lose << " loses" << std::endl; //displays total wins to loseses.  
	return 0;
}
int getranNum(int min_, int max_)	//defining the functions I am using in this program.
{
	return rand() % (max_ - min_ + 1) + min_; //generate a random number between 0 and 100.
}
int getranMes(int min2_, int max2_)
{
	return rand() % (max2_ - min2_ + 1) + min2_; //generate a random number between 1 and 10.
}
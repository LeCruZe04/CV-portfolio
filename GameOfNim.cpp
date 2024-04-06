// File: Project2.cpp
//Name: Leonardo Cruz
//Date: 11/09/2023
//Description:  This program is a simple NIME game. It has an easy mode and a hard mode.
//Usage:  This program will ask the user for input, and the computer will give specific random data to play against a human player.

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <Windows.h>
#include <iomanip>

using namespace std; // I will use it despite I think is a bad way to learn and practice.

int toremove() // Picking the random number to remove
{
	return rand() % 3 + 1;
}

string printLine()
{
	int number = 75;
	string str = "";
	for (int i = 0; i <= number; i++) { str += "X"; }
	str = str + "\n";
	return str;
}

void easymode(int stonesQuantity, int turn)
{
	string line = printLine();
	while (stonesQuantity > 0) //Keep playing until stones are less than 0.
	{
		if (turn == 0) // Actions for the computer's turn
		{
			
			cout << "The computer is choosing a move...\n"; Sleep(500);
			int numbertoreduce = toremove();
			while ((stonesQuantity - numbertoreduce) < 0) { numbertoreduce = toremove(); } // Continue changing the number of number to reduce if the rest is negative.

			cout << "The computer removed " << numbertoreduce << " stones from the pile\n"; 
			stonesQuantity -= numbertoreduce;// Updates Quantity of stones.
			cout << "The pile now have " << stonesQuantity << " stones left\n" << line; Sleep(500);
			turn = 1; // Switch turn for the next iteration
		}
		else	// Actions for the human's turn
		{
			
			cout << "It is your turn. Enter the number of stones you would like to remove: ";
			int numbertoreduce;
			cin >> numbertoreduce;

			while (true)
			{
				if (numbertoreduce > 3 || numbertoreduce < 0) //Checks and prompts until get a valid input
				{

					cout << numbertoreduce << " is not a valid move. Enter either 1, 2, or 3 for the number of stones:";
					cin >> numbertoreduce;
					if (numbertoreduce > 0 && numbertoreduce < 4 && numbertoreduce <= stonesQuantity) { break; } // Break if get the valid input

				}
				else { break; } // If it does not find incorrect input break
			}

			cout << "You removed " << numbertoreduce << " from the pile\n"; Sleep(500);
			stonesQuantity -= numbertoreduce;// Updates Quantity of stones.
			cout << "The pile now has " << stonesQuantity << " stones left.\n" << line; Sleep(500);
			turn = 0; // Switch turn for the next iteration		

		}
	}
	if (turn == 1) { cout << "Congratulations, you won! :)\n" << line; Sleep(500);
	}
	else if (turn == 0) { cout << "Sorry, you lost the game :(\n" << line; Sleep(500);
	}

}

void hardmode(int stonesQuantity, int turn)
{
	string line = printLine();
	while (stonesQuantity > 0) //Keep playing until stones are less than 0.
	{
		if (turn == 0) // Actions for the computer's turn
		{
			cout << "The computer is choosing a move...\n"; Sleep(500);
			
			int numbertoreduce = toremove();
			if (stonesQuantity % 4 == 1) // Checks if stonesQuantity is a multiple of four plus 1 and changes numbertoreduce to 1.
			{
				numbertoreduce = 1;
			} 
			else
			{
				numbertoreduce = ((stonesQuantity - 1) % 4);
			}

			cout << "The computer removed " << numbertoreduce << " stones from the pile\n"; 
			stonesQuantity -= numbertoreduce;// Updates Quantity of stones.
			cout << "The pile now have " << stonesQuantity << " stones left\n" << line; Sleep(500);
			turn = 1; // Switch turns 
		}
		else	// Actions for the human's turn
		{
			cout << "It is your turn. Enter the number of stones you would like to remove: "; 
			int numbertoreduce;
			cin >> numbertoreduce;

			while (true)
			{
				if (numbertoreduce > 3 || numbertoreduce < 0 || numbertoreduce > stonesQuantity) //Checks and prompts until get a valid input
				{

					cout << numbertoreduce << " is not a valid move. Enter either 1, 2, or 3 for the number of stones:";
					cin >> numbertoreduce;
					if (numbertoreduce > 0 && numbertoreduce < 4 && numbertoreduce <= stonesQuantity) { break; } // Break if get the valid input
				}
				else { break; } // If it does not find incorrect input break
			}

			cout << "You removed " << numbertoreduce << " from the pile\n";
			stonesQuantity -= numbertoreduce;// Updates Quantity of stones.
			cout << "The pile now has " << stonesQuantity << " stones left.\n" << line;
			turn = 0; // Switch turns 

		}
	}
	
	if (turn == 1) { cout << "Congratulations, you won! :)\n" << line; }
	else if (turn == 0) { cout << "Sorry, you lost the game :(\n" << line; }

}


int main()
{
	srand(time(0)); // Generates a new seed each time it compiles due to time(0) function.
	string line = printLine();
	string intro = "THE GAME OF NIME";
	cout << setw(line.length()/2 + intro.length()/2) << right << intro << "\n"; // Center the intro string according to the width of the line.

	cout << line << line;
	cout << "Rules of the game :\n";
	cout << "* Each player can remove 1, 2, or 3 stones from the pile.\n"
		<< "* The player who makes the last move loses. \n";
	cout << line;
	cout << "Choose mode:\n" << "Easy Mode(e) or Hard Mode(h) :";
	
	string difficulty;
	
	while (true)	//User does choose the difficulty and keeps prompting if necessary until break.
	{
		cin >> difficulty;
		if (difficulty == "e") { cout << "You have chosen the easy mode.\n" << line; break; }
		else if (difficulty == "h") { cout << "You have chosen the hard mode.\n" << line; break; }
		else if (difficulty != "e" && difficulty != "h") { cout << "That is not an option!. Please enter e or h\n"; }
	}
	
	int stonesQuantity = rand() % 12 + 10;// Choose a random number between 10 & 21 (inclusive)
	cout << "The initial number of stones is " << stonesQuantity << "\n"
		<< "Now a roll of the die to determine who plays first. \n"; Sleep(10000);

	int turn = rand() % 2; // 0 for computer, 1 for player
	
	if (turn == 0) { cout << "The computer plays first\n" << line;} else {cout << "The player plays first\n" << line;} // Check who will start

	if (difficulty == "e") {easymode(stonesQuantity, turn);}
	else if (difficulty == "h") { hardmode(stonesQuantity, turn);}
	string outro = "THANK YOU FOR PLAYING";
	cout << setw(line.length() / 2 + outro.length()/2) << right<< outro << "\n\n\n\n"; // Center the intro string according to the width of the line.
	return 0;
}

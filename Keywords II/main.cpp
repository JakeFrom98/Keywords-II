#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <string>


using namespace std;

// Main Function
int main()
{
	// Number of Simulations
	int simiulation = 1;
	// Ask the recruit to login using thier name
	char name[10];
	cout << "Please Enter Your Name To Login: ";
	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	cin >> name;
	// Display Title of program to user
	cout << "Welcome To The Code Breaker Training Simulation Program For CIA Recruits!\n";
	cout << "Welcome" << " " << name << " to Keywords II!\n";
	// Pause Console
	system("pause");
	// Clear Console
	system("cls");
	// Display an overview of what Keywords II is to the recruit 
	cout << "Keywords II is a more advanced version of Keywords I.\n";
	cout << "You have made it past the first round of your traning but now you must pass this round of training to move on.\n";
	// Display an directions to the recruit on how to use Keywords
	cout << "You will be required to guess letters to discover a word and once you discover the word you will be able to move on.\n";
	// Pause Console
	system("pause");
	// Clear Console
	system("cls");
rerun:
	cout << "Starting simulation #" << simiulation;
	cout << "\nGood Luck...";
	// Pause Console For 5 Seconds
	system("timeout /t 5 /nobreak");
	// Clear Console
	system("cls");

	// The Max Number Of Incorrect Guesses
	const int MAX_WRONG = 8;  

	// Create a collection of 10 words you had wrote down manually
	vector<string> words;  
	words.push_back("AGENT");
	words.push_back("SPY");
	words.push_back("HANDLER");
	words.push_back("SLEEPER");
	words.push_back("POMPEO");
	words.push_back("CIA");
	words.push_back("CIPHER");
	words.push_back("CLEAN");
	words.push_back("ASSET");
	words.push_back("CENTER");

	// Randomly Select Word
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	// The Word To Guess
	const string THE_WORD = words[0];            
	// The Number Of Incorrect Guesses
	int wrong = 0;                               
	// How Many "-" Depending On The Word 
	string soFar(THE_WORD.size(), '-');          
	// The Letters That Are Already Guessed
	string used = "";                            

	// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
	while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
	{
		// Tell recruit how many incorrect guesses he or she has left
		cout << "\n\nYou have " << (MAX_WRONG - wrong);
		cout << " incorrect guesses left.\n";
		// Show recruit the letters he or she has guessed
		cout << "\nYou've used the following letters:\n" << used << endl;
		// Show player how much of the secret word he or she has guessed
		cout << "\nSo far, the word is:\n" << soFar << endl;

		// Get recruit's next guess
		char guess;
		cout << "\n\nEnter your guess: ";
		cin >> guess;
		// Makes Letter You Input Automatically Uppercase
		guess = toupper(guess); 
		
		// While recruit has entered a letter that he or she has already guessed
		while (used.find(guess) != string::npos)
		{
			// Get recruit ’s guess
			cout << "\nYou've already guessed " << guess << endl;
			cout << "Enter your guess: ";
			cin >> guess;
			// Add the new guess to the group of used letters
			guess = toupper(guess);
		}
		
		used += guess;

		// If the guess is in the secret word
		if (THE_WORD.find(guess) != string::npos)
		{
			// Tell the recruit the guess is correct
			cout << "That's right! " << guess << " is in the word.\n";

			// Update the word guessed so far with the new letter
			for (unsigned int i = 0; i < THE_WORD.length(); ++i)
			{
				if (THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}

		else
		{
			// Tell the recruit the guess is incorrect
			cout << "Sorry, " << guess << " isn't in the word.\n";
			// Increment the number of incorrect guesses the recruit has made
			++wrong;
		}
	}

	// If the recruit hasn't done enough simulations
	if (simiulation != 3)
	{
		++simiulation;
		cout << "\nThe word was " << THE_WORD << endl;
		system("pause");
		system("cls");
		goto rerun;
	}
	
	// If the recruit has made too many incorrect guesses
	if (wrong == MAX_WRONG)
		// Tell the recruit that he or she has failed the Keywords II course.
		cout << "\nYou have failed the Keywords II course!";
	
	// Congratulate the recruit on guessing the secret words

	else
		// Clear Console
		system("cls");
	cout << "\nThe word was " << THE_WORD << endl;
		cout << "\nCongratulations " << name << "! on discovering the final word!";
		// Ask the recruit if they would like to run the simulation again
		
		string again;
		cout << "\nWould You Like To Run The Simulation Again y/n? ";
		cin >> again;
		
		// If the recruit wants to run the simulation again
		if (again == "y")
			++simiulation;
			// Clear Console
			system("cls");
			goto rerun;
}
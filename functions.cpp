#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "functions.h"
// options
std::vector<string> options = { "test", "macro", "image to gif"};
std::vector<void(*)()> files = { run_test, run_macro, run_test };

void menu()
{
	clear_terminal();
	std::cout << "\033[95mWelcome to CoolGermanGuy's Multitool\033[0m\n";
	//! display all options
	for (int i = 0; i < options.size(); i++)
	{
		std::cout << "[" + std::to_string(i + 1) + "]" + " " + options[i] + "\n";
	}
	// input
	string input;
	cout << "\n";
	cin >> input;
	cout << "\n\n";

	//! check if option exists and run it
	for (int i = 0; i < options.size(); i++)
	{
		if (options[i] == input || std::to_string(i + 1) == input)
		{
			files[i]();
		}
	}
}

void clear_terminal()
{
	std::cout << "\033[3J\033[H\033[2J";
}

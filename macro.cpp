using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include "functions.h"

std::vector<std::string> macros = { "autoclicker", "spam e" };
std::vector<bool> macroStates = { false, false };

void run_macro()
{
	clear_terminal();
	std::cout << "\033[96mMacros\033[0m\n";
	//! display all macros
	for (int i = 0; i < macros.size(); i++)
	{
		if (macroStates[i])
		{
			std::cout << "\033[32m[" + std::to_string(i + 1) + "]" + " " + macros[i] + "\033[0m\n";
		}
		else
		{
			std::cout << "\033[31m[" + std::to_string(i + 1) + "]" + " " + macros[i] + "\033[0m\n";
		}
		
	}
	// input
	string input;
	cout << "\n";
	cin >> input;
	cout << "\n";

	if (input == "back" || input == "c" || input == "cancel" || input == "menu")
	{
		menu();
		return;
	}

	//! check if macro exists and toggle it
	for (int i = 0; i < macros.size(); i++)
	{
		if (macros[i] == input || std::to_string(i) == input)
		{
			macroStates[i] = not macroStates[i];
			run_macro();
			break;
		}
	}
}

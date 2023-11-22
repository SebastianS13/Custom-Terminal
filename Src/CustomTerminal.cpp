#include "CustomTerminal.hpp"

CustomTerminal::CustomTerminal()
{
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_MAXIMIZE);
	std::cout << ">> Welcome to sebastians custom terminal \n>> This is a custom made terminal made to replace the normal one \n>> It handles commands custom but can also handle normal commands from external apps \n";
	std::cout << "\n\n";
}

void CustomTerminal::Command()
{
	std::string Input;
	std::cout << "> ";
	std::getline(std::cin, Input);

	std::transform(Input.begin(), Input.end(), Input.begin(), [](unsigned char c) { return std::tolower(c); });

	if (DebugMode)
	{
		std::cout << ">>> Recieved command: " << Input << "\n";
	}

	if (Input == "exit"){ CustomTerminal::ExitCommand(); return; }
	if (Input == "color") { CustomTerminal::ColorCommand(); return; }


	// If command is not picked up by custom commadns it uses
	// In-build "system" to handle it which auto prints result
	// Or auto executes the command
	char* CommandArray = new char[Input.length() + 1];
	strcpy(CommandArray, Input.c_str());
	system(CommandArray);
}

void CustomTerminal::ExitCommand()
{
	exit(0);
}

void CustomTerminal::ColorCommand()
{
	std::string ColorCode; 
	std::cout << "\n>> Enter color code \n> ";
	std::cin >> ColorCode;

	std::string Command = "color " + ColorCode;

	char* CommandArray = new char[Command.length() + 1];
	strcpy(CommandArray, Command.c_str());

	system(CommandArray);
	std::cout << "\n";
}
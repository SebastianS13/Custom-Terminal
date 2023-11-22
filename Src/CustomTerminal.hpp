#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <cstring>
#include <windows.h>

class CustomTerminal
{
public:
	CustomTerminal();
	void Command();
private:
	bool DebugMode = false;

	void ExitCommand();
	void ColorCommand();
};
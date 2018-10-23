#pragma once

#include <string>

#include <Windows.h>

extern int initConsole(short, short);

extern int setConsoleWindowSize(short, short);

extern int setConsoleWindowTitle(std::string);

extern void setCursorVisibility(bool);

extern void setCursorPos(short, short);

extern void setConsoleColour(short);

extern void cls();

namespace Colour {
	enum : unsigned short {
		White = 15,
		Red = 12,
		Blue = 9,
		WhiteRedBack = 79,
		WhiteBlueBack = 31,
		RedRedBack = 76,
		RedBlueBack = 28,
		BlueBlueBack = 25,
		BlueRedBack = 73
	};
}
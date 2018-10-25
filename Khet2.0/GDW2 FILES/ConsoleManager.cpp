#include <iostream>
#include <string>
#include <Windows.h>

#include "ConsoleManager.h"

HANDLE hConsole;

short cWidth, cHeight;
std::string cTitle;
bool cursorVis;

short cursorX = 0, cursorY = 0;

int initConsole(short width, short height) {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cWidth = width;
	cHeight = height;

	if (!setConsoleWindowSize(width, height)) {
		return -1;
	}

	return 0;
}

int setConsoleWindowSize(short width, short height) {
	SetConsoleScreenBufferSize(hConsole, { width, height });
	SMALL_RECT windowSize = { 0, 0, width - 1, height - 1 };

	if (!SetConsoleWindowInfo(hConsole, TRUE, &windowSize)) {
		std::cout << "SetConsoleWindowInfo failed with error " << GetLastError() << "\n";
		return -1;
	}
	return 0;
}

int setConsoleWindowTitle(std::string title) {
	if (!SetConsoleTitle(title.c_str())) {
		std::cout << "SetConsoleTitle failed with error " << GetLastError() << "\n";
		return -1;
	}
	return 0;
}

void setCursorVisibility(bool isVisible) {
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = isVisible; // set the cursor visibility
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void setCursorPos(short x, short y) {
	cursorX = x;
	cursorY = y;
	SetConsoleCursorPosition(hConsole, { cursorX, cursorY });
}

void setConsoleColour(short colour) {
	SetConsoleTextAttribute(hConsole, colour);
}

void cls()
{
    // Get the Win32 handle representing standard output.
    // This generally only has to be done once, so we make it static.
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD topLeft = { 0, 0 };

    // std::cout uses a buffer to batch writes to the underlying console.
    // We need to flush that to the console because we're circumventing
    // std::cout entirely; after we clear the console, we don't want
    // stale buffered text to randomly be written out.
    std::cout.flush();

    // Figure out the current width and height of the console window
    if (!GetConsoleScreenBufferInfo(hOut, &csbi)) {
        // TODO: Handle failure!
        abort();
    }
    DWORD length = csbi.dwSize.X * csbi.dwSize.Y;

    DWORD written;

    // Flood-fill the console with spaces to clear it
    FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);

    // Reset the attributes of every character to the default.
    // This clears all background colour formatting, if any.
    FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);

    // Move the cursor back to the top left for the next sequence of writes
    SetConsoleCursorPosition(hOut, topLeft);
}

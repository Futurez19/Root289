#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include <io.h>
#include <fcntl.h>

#include <sstream>
#include <fstream>
#include <codecvt>

#include <cwchar>

#include "InputManager.h"
#include "ConsoleManager.h"

#define COLS 200
#define ROWS 50

std::wstring readFile(const char*);


bool running = true;

std::wstring map = L"";



int main()
{
	initConsole(COLS, ROWS);
	setCursorVisibility(false);
	setConsoleWindowTitle("Khet 2.0");
	
	_setmode(_fileno(stdout), _O_U16TEXT);

//	CONSOLE_FONT_INFOEX cfi;
//cfi.cbSize = sizeof(cfi);
//cfi.nFont = 0;
//cfi.dwFontSize.X = 12;                   // Width of each character in the font
//cfi.dwFontSize.Y = 12;                  // Height
//cfi.FontFamily = FF_DONTCARE;
//cfi.FontWeight = FW_NORMAL;
//std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
//SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	map = readFile("board.txt");

	char boardState[100];
	for (int i = 0; i < 100; i++)
		switch (i % 3) {
			case 0:
				boardState[i] = '&';
				break;
			case 1:
				boardState[i] = '#';
				break;
			case 2: 
				boardState[i] = '*';
				break;
		}


	while (running) {

		if (isButton(Events::Escape)) {
			running = false;
			continue;
		}

		// vv Input Checking vv



		// ^^ Input Checking ^^

		// vv Game Logic vv



		// ^^ Game Logic ^^
		
		// vv Output vv 
		setCursorPos(0, 0);
		//cls();

		//printf("x: %d y: %d           \n", getMouseX(), getMouseY());

		setCursorPos(0, 1);

		std::wcout << map;

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = 1; k <= 3; k++) {
					for (int l = 1; l <= 3; l++) {
						setCursorPos(i * 8 + k * 2, j * 4 + l + 1);
						std::wcout << boardState[i + j * 10];
					}
				}
			}
		}

		while (!isButton(Events::Space));
	
		setCursorPos(COLS, ROWS);
		// ^^ Output ^^
	}
	return 0;
}

// CREDIT: https://stackoverflow.com/questions/4775437/read-unicode-utf-8-file-into-wstring
std::wstring readFile(const char* filename) {
    std::wifstream wif(filename);
    wif.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
    std::wstringstream wss;
    wss << wif.rdbuf();
    return wss.str();
}
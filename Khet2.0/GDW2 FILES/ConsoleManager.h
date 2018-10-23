#pragma once

#include <string>

#include <Windows.h>

extern int initConsole(short, short);

extern int setConsoleWindowSize(short, short);

extern int setConsoleWindowTitle(std::string);

extern void setCursorVisibility(bool);

extern void setCursorPos(short, short);

extern void cls();
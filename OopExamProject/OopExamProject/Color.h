#pragma once
#include<iostream>
#include<Windows.h>
using namespace std;

enum Colors {
	Black, Blue, Green, Aqua, Red, Purple, Yellow, White, Gray
};

void color(size_t color) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, color);
}


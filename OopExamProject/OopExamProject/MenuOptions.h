#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <iomanip>

using namespace std;

class Menu
{
private:

#define Up 72
#define Down 80
#define Enter 13

	int m_x;
	int m_y;
	int menu_color;
	bool m_clr;
	string str[10];

	void m_gotoxy(short x, short y)
	{
		COORD coord = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	void hidecursor()
	{
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 10;
		info.bVisible = FALSE;
		SetConsoleCursorInfo(consoleHandle, &info);
	}
	void showcursor()
	{
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 10;
		info.bVisible = TRUE;
		SetConsoleCursorInfo(consoleHandle, &info);
	}

public:
	const int RED = 12;
	const int GREEN = 10;
	const int TURQUOISE = 11;
	const int YELLOW = 14;
	const int PURPLE = 13;
	const int BCK = 160;

	void set_xy(int x, int y)
	{
		m_x = x;
		m_y = y;
	}
	void clear_screen(bool clr)
	{
		m_clr = clr;
	}
	void set_color(int color)
	{

		switch (color)
		{
		case 12: menu_color = 12;		break;
		case 10: menu_color = 10;		break;
		case 11: menu_color = 11;		break;
		case 14: menu_color = 14;		break;
		case 13: menu_color = 13;		break;
		case 160: menu_color = 160;		break;
		}
	}

	Menu()
	{
		m_x = 33;
		m_y = 5;
		m_clr = true;
		menu_color = BCK;
		for (int i = 0; i < 10; i++)
			str[i] = "";
	}

	int Gmenu(string str1, string str2, string str3 = "", string str4 = "", string str5 = "", string str6 = "", string str7 = "", string str8 = "", string str9 = "", string str10 = "")
	{
		hidecursor();
		HANDLE  hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		int process = 0, keystroke, nCount = 0, counter = 0, i = 0;
		string Gmenu[10];

		str[0] = str1;
		str[1] = str2;
		str[2] = str3;
		str[3] = str4;
		str[4] = str5;
		str[5] = str6;
		str[6] = str7;
		str[7] = str8;
		str[8] = str9;
		str[9] = str10;

		for (int j = 0; i < 10; i++, j++)
		{
			if (str[i] == "")
				j--;
			else
				Gmenu[j] = str[i];
		}

		if (str1.size() != 0)
			nCount++;
		if (str2.size() != 0)
			nCount++;
		if (str3.size() != 0)
			nCount++;
		if (str4.size() != 0)
			nCount++;
		if (str5.size() != 0)
			nCount++;
		if (str6.size() != 0)
			nCount++;
		if (str7.size() != 0)
			nCount++;
		if (str8.size() != 0)
			nCount++;
		if (str9.size() != 0)
			nCount++;
		if (str10.size() != 0)
			nCount++;

		i = 0;

		if (m_clr == true)
			system("cls");

		while (true)
		{
			for (int j = 0; i <= 9; i++, j++)
			{

				m_gotoxy(m_x, m_y + i);
				if (i != process)
				{
					SetConsoleTextAttribute(hConsole, 15);
					cout << Gmenu[i] << endl;
				}
				else
				{
					SetConsoleTextAttribute(hConsole, menu_color);
					cout << Gmenu[i] << endl;
					SetConsoleTextAttribute(hConsole, 15);
				}

			}
			i = 0;
			keystroke = _getch();
			if (keystroke == Enter)
			{
				showcursor();
				for (int l = 0; l < 10; l++)
					if (Gmenu[process] == str[l])
						return l;
			}
			switch (keystroke)
			{
			case Down:
			{
				if (process < nCount - 1)
				{
					process++;
				}
				break;
			}
			case Up:
			{
				if (process > 0)
				{
					process--;
				}
				break;
			}
			}

		}
	}
};

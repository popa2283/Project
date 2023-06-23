#pragma once
#include <iostream> 
#include <time.h> 
#include <vector> 
#include<Windows.h> 
#include < math.h> 
#include <conio.h>
#include<string>

using namespace std;

HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
int Xcat = 5;
int Ycat = 5;
int direction;
vector<vector<char>>hp() {

	CONSOLE_FONT_INFOEX  cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 2;
	cfi.dwFontSize.X = 20;
	cfi.dwFontSize.Y = 20;
	cfi.FontFamily = FF_ROMAN;
	cfi.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(hand, FALSE, &cfi);


	vector<char>vec1;
	char s = 254;
	vector<vector<char>> vec;

	for (size_t i = 0; i < 12; i++)
	{



		for (size_t j = 0; j < 12; j++)
		{




			if (i == 0)
			{
				vec1.push_back(s);
			}
			if (i == 11)
			{
				vec1.push_back(s);
			}
			if (i > 0)
			{



				if (j == 0)
				{
					vec1.push_back(s);
				}
				if (j == 11)
				{
					vec1.push_back(s);
				}
				else {
					vec1.push_back(32);
				}
			}








		}
		vec.push_back(vec1);


	}
	return vec;
}
void right() {
	Xcat++;
}
void left() {
	Xcat--;
}
void up() {
	Ycat--;
}
void down() {
	Ycat++;
}
void ff(int direction) {



	if (direction == 0) {
		right();
	}
	else if (direction == 1) {
		left();
	}
	else if (direction == 2) {
		up();
	}
	else if (direction == 3) {
		down();
	}
}
void hh() {

	if (direction == 0) {
		left();
		down();
		direction = 3;
	}
	else if (direction == 1) {
		right();
		up();
		direction = 2;
	}
	else if (direction == 2) {
		down();
		right();
		direction = 0;
	}
	else if (direction == 3) {
		up();
		left();
		direction = 1;
	}
}
void GAME_ONE() {
	COORD cord;
	direction = rand() % 3;
	int ct;
	ct = rand() % 4;

	vector<vector<char>>vec2;
	vec2 = hp();

	vec2[Ycat][Xcat] = '@';

	int x1 = 1;
	
	SetConsoleTextAttribute(hand, 5);
	for (size_t i = 0; i < 10; i++)
	{
		cout << x1 << " ";
		x1++;
	}
	cout << endl;
	x1 = 1;
	int y1 = 0;
	SetConsoleTextAttribute(hand, 9);



	for (size_t i = 1; i < 11; i++)
	{

		for (size_t j = 1; j < 11; j++)
		{
			if (vec2[i][j] == '@') {
				SetConsoleTextAttribute(hand, 15);

			}
			if (vec2[i][j] == '#') {
				SetConsoleTextAttribute(hand, 13);

			}
			cout << vec2[i][j] << " ";
			SetConsoleTextAttribute(hand, 9);

		}
		cout << endl;
	}
	int x = 0;
	int y = 0;

	int g = 0;
	int r = 0;
	int o = 0;
	

	while(true)
	{
		
		while (true)
		{
			
			cout << "x= ", cin >> x;
			
			while (!cin or x >10)
			{
				cin.clear();
				while (cin.get() != '\n') continue;
				cout << "x= ", cin >> x;
				

				
			}
			cout << "y= ", cin >> y;		
			while (!cin or y > 10)
			{
				cin.clear();
				while (cin.get() != '\n') continue;
				cout << "y= ", cin >> y;
				
			}
			cout << endl;	
			if (vec2[y][x] != '#' and vec2[y][x] != '@') {
				break;
			}
			
		}

		vec2[y][x] = '#';
		vec2[Ycat][Xcat] = 254;
		ff(direction);

		while (vec2[Ycat][Xcat] == '#') {

			hh();
			if (g == 4) {
				break;
			}
			g++;




		}
		if (g == 4 or Ycat == 0 or Ycat == 11 or Xcat == 11 or Xcat == 0) {
			system("cls");
			cord.X = 70;
			cord.Y = 17;

			SetConsoleCursorPosition(hand, cord);
			if (g == 4) {
			
				cout << "VICTORY" << endl;

			}
			else  {
				
				cout << "GEME OVER" << endl;
				
			}
			Ycat = 5;
			Xcat = 5;
			Sleep(2000);
			system("cls");
			
			cout << "game 1 " << endl;
			cout << "game 2 " << endl;
			cout << "ESC -- > EXET" << endl;
			
			break;

		}
		
		


		g = 0;
	

		vec2[Ycat][Xcat] = '@';
		system("cls");
		
		SetConsoleTextAttribute(hand, 5);
		for (size_t i = 0; i < 10; i++)
		{
			cout << x1 << " ";
			x1++;
		}
		cout << endl;
		x1 = 1;
		int y1 = 0;
		SetConsoleTextAttribute(hand, 9);



		for (size_t i = 1; i < 11; i++)
		{

			for (size_t j = 1; j < 11; j++)
			{
				if (vec2[i][j] == '@') {
					SetConsoleTextAttribute(hand, 15);

				}
				if (vec2[i][j] == '#') {
					SetConsoleTextAttribute(hand, 13);

				}
				cout << vec2[i][j] << " ";
				SetConsoleTextAttribute(hand, 9);

			}
			cout << endl;
		}
	}
}


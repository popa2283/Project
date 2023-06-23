#pragma once
#include <iostream> 
#include <time.h> 
#include <vector> 
#include<Windows.h> 
#include < math.h> 
#include <conio.h>
#include<string>
using namespace std;
int coins = 0;
int g = 0;
int g2 = 0;
int sum = 0;
int one_size = 0;
int two_size = 0;
int ss = 0;
HANDLE handl = GetStdHandle(STD_OUTPUT_HANDLE);
vector<vector<char>>hp2() {
	coins = 0;
	CONSOLE_FONT_INFOEX  cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 2;
	cfi.dwFontSize.X = 20;
	cfi.dwFontSize.Y = 20;
	cfi.FontFamily = FF_ROMAN;
	cfi.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(handl, FALSE, &cfi);

	char s = '@';

	vector<vector<char>> vec;


	for (size_t i = 0; i < 26; i++)
	{

		vector<char>vec1;
		vector<int>veca;
		vector<int>vecd;
		int d;
		int a;
		int sta;
		int std;
		int a1 = 0;
		int d1 = 0;
		int boomx = 0;
		int boomy = 0;
		int boom = 0;
		for (size_t j = 0; j < 29; j++)
		{
			for (size_t t = 0; t < 20; t++)
			{

				a = rand() % 20 + 1;
				sta = rand() % 20 + 1;
				if (boom < 5) {
					boomx = rand() % 20 + 1;
				}

				if (a1 > 0) {
					for (size_t j = 0; j < veca.size(); j++)
					{
						if (a == veca[j])
						{
							a = rand() % 20 + 1;
						}
						if (sta == vecd[j]) {
							sta = rand() % 20 + 1;
						}
						if (boom < 5) {
							if (boomx == veca[j])
							{
								boomx = rand() % 20 + 1;
							}
						}
					}
				}
				veca.push_back(a);
				veca.push_back(sta);
				veca.push_back(boomx);
				int d = rand() % 20 + 1;
				int std = rand() % 20 + 1;
				if (boom < 5) {
					boomy = rand() % 20 + 1;
				}
				if (a1 > 0) {
					for (size_t y = 0; y < vecd.size(); y++)
					{
						if (d == veca[y])
						{
							d = rand() % 20 + 1;

						}
						if (std == vecd[y]) {
							std = rand() % 20 + 1;
						}
						if (boom < 5) {
							if (boomy == veca[j])
							{
								boomy = rand() % 20 + 1;
							}
						}
					}
				}
				vecd.push_back(d);
				vecd.push_back(std);
				vecd.push_back(boomy);
				if (i > 0 and i < 26 and j > 0 and j < 26) {
					if (i == a and j == d) {
						vec1.push_back('S');
						coins++;
					}
					if (i == sta and j == std) {
						vec1.push_back('@');
					}
					if (i == boomx and j == boomy) {
						vec1.push_back('#');
					}
				}
				a1++;
				boom++;
			}





			if (i == 0)
			{
				vec1.push_back(s);
			}
			if (i == 25)
			{
				vec1.push_back(s);

			}
			if (i > 0)
			{

				if (j != 29 and j != 0) {
					vec1.push_back(32);
				}
				if (j == 0)
				{
					vec1.push_back(s);
				}
				if (j == 27)
				{
					vec1.push_back(s);
				}

			}







		}
		vec.push_back(vec1);
	}

	return vec;

}
void cast() {
	SetConsoleTextAttribute(handl, 4);
	cout << "ESC --> EXET"  << endl;
	SetConsoleTextAttribute(handl, 4);
	cout << "#--> KILL" << endl;
	SetConsoleTextAttribute(handl, 5);
	cout << "S--> COINS" << endl;
	SetConsoleTextAttribute(handl, 1);
	cout << "1--> ONE PLEER" << endl;
	SetConsoleTextAttribute(handl, 15);
	cout << "2--> TWO PLEER" << endl;
	SetConsoleTextAttribute(handl, 10);
	cout << "SUM COINS" << sum << endl;

}
void ff2() {
	COORD cord;
	system("cls");
	cord.X = 70;
	cord.Y = 17;
	g = 0;
	g2 = 0;
	SetConsoleCursorPosition(handl, cord);
	cout << "KING --> PLEER ONE" << endl;


	
	Sleep(3000);
	system("cls");
	

}
void ff1() {
	COORD cord;
	system("cls");
	cord.X = 70;
	cord.Y = 17;
	g = 0;
	g2 = 0;
	SetConsoleCursorPosition(handl, cord);
	cout << "KING --> PLEER TWO" << endl;


	

	Sleep(3000);
	system("cls");

}
void game() {
	vector<char>one;
	vector <char>two;
	COORD cord;
	char s = '@';
	srand(time(NULL));
	vector<vector<char>>vec3;
	vec3 = hp2();
	int x = 10;
	int y = 10;
	vec3[y][x] = '1';
	int x2 = 11;
	int y2 = 10;
	vec3[y2][x2] = '2';
	int of = 0;
	cast();
	for (size_t i = 0; i < 26; i++)
	{

		for (size_t j = 0; j < 29; j++)
		{
			if (vec3[i][j] == '#') {
				SetConsoleTextAttribute(handl, 4);

			}
			if (vec3[i][j] == 'S') {
				SetConsoleTextAttribute(handl, 5);

			}
			if (vec3[i][j] == '1') {
				SetConsoleTextAttribute(handl, 1);

			}
			if (vec3[i][j] == '2') {
				SetConsoleTextAttribute(handl, 15);

			}
			if (vec3[i][j] == '@') {
				SetConsoleTextAttribute(handl, 14);

			}
			cout << vec3[i][j] << " ";
			SetConsoleTextAttribute(handl, 10);

		}
		cout << endl;
	}




	int htr = 0;
	while (true)
	{

		if (coins == sum) {
			vec3 = hp2();
			int x = 10;
			int y = 10;
			vec3[y][x] = '1';
			int x2 = 11;
			int y2 = 10;
			vec3[y2][x2] = '2';
			of = 1;
			system("cls");			
			cord.X = 70;
			cord.Y = 17;
			coins = 0;
			sum = 0;
			SetConsoleCursorPosition(handl, cord);
			if (g > g2) {
				ff2();			
				
			}
			else if (g < g2) {
				ff1();
				
			}
			else {
				cout << "NOT KING" << endl;				
				g = 0;
				g2 = 0;
			}


		}

		else if (of == 0) {

			if (_kbhit())
			{

				switch (_getch())
				{

				case char(27): {
					system("cls");
					cord.X = 70;
					cord.Y = 17;
					SetConsoleCursorPosition(handl, cord);
					cout << "NOT KING" << endl;
					Sleep(3000);
					system("cls");
					

					
					g = 0;
					g2 = 0;
					of = 1;

					break;
				}
				case 'a':
				{



					if (x > 1) {

						vec3[y][x] = ' ';

						x -= 1;
						if (vec3[y][x] == '#')
						{
							ff1();
							two.push_back(254);
							two_size = two.size();
							
							sum = 0;
							of = 1;



						}
						if (vec3[y][x] != ' ' and vec3[y][x] != s and vec3[y][x] != '2')
						{

							g++;
						}
						if (vec3[y][x] == s or vec3[y][x] == '2')
						{

							x += 1;
						}

						vec3[y][x] = '1';
						if (x == 0) {
							x = 10;
							y = 10;
						}


						break;
					}



				}
				case 'f':
				{



					if (x2 > 1) {

						vec3[y2][x2] = ' ';

						x2 -= 1;
						if (vec3[y2][x2] == '#')
						{
							ff2();
							one.push_back(254);
							one_size = one.size();
							
							sum = 0;
							of = 1;



						}
						if (vec3[y2][x2] != ' ' and vec3[y2][x2] != s and vec3[y2][x2] != '1')
						{

							g2++;
						}
						if (vec3[y2][x2] == s or vec3[y2][x2] == '1')
						{

							x2 += 1;
						}

						vec3[y2][x2] = '2';
						if (x2 == 0) {
							x2 = 10;
							y2 = 10;
						}


						break;
					}



				}
				case 'd':
				{

					if (x < 28) {

						vec3[y][x] = ' ';
						x += 1;
						if (vec3[y][x] == '#')
						{
							ff1();
							two.push_back(254);
							two_size = two.size();
							
							sum = 0;
							of = 1;



						}
						if (vec3[y][x] != ' ' and vec3[y][x] != s and vec3[y][x] != '2')
						{

							g++;
						}
						if (vec3[y][x] == s or vec3[y][x] == '2')
						{

							x -= 1;
						}

						if (x == 28) {
							x -= 1;
						}
						vec3[y][x] = '1';

						break;
					}

				}
				case 'h':
				{

					if (2 < 28) {

						vec3[y2][x2] = ' ';
						x2 += 1;
						if (vec3[y2][x2] == '#')
						{
							ff2();
							one.push_back(254);
							one_size = one.size();
							
							sum = 0;
							of = 1;


						}
						if (vec3[y2][x2] != ' ' and vec3[y2][x2] != s and vec3[y2][x2] != '1')
						{

							g2++;
						}
						if (vec3[y2][x2] == s or vec3[y2][x2] == '1')
						{

							x2 -= 1;
						}

						if (x2 == 28) {
							x2 -= 1;
						}
						vec3[y2][x2] = '2';

						break;
					}

				}
				case 'w':
				{
					if (y > 1) {

						vec3[y][x] = ' ';
						y -= 1;
						if (vec3[y][x] == '#')
						{
							ff1();
							two.push_back(254);
							two_size = two.size();
							
							sum = 0;
							of = 1;


						}
						if (vec3[y][x] != ' ' and vec3[y][x] != s and vec3[y][x] != '2')
						{

							g++;
						}
						if (vec3[y][x] == s or vec3[y][x] == '2')
						{

							y += 1;
						}

						if (y == 0) {
							y += 1;
						}

						vec3[y][x] = '1';

						break;
					}

				}
				case 't':
				{
					if (y2 > 1) {

						vec3[y2][x2] = ' ';
						y2 -= 1;
						if (vec3[y2][x2] == '#')
						{
							ff2();

							one.push_back(254);
							one_size = one.size();
							
							sum = 0;
							of = 1;



						}
						if (vec3[y2][x2] != ' ' and vec3[y2][x2] != s and vec3[y2][x2] != '1')
						{

							g2++;
						}
						if (vec3[y2][x2] == s or vec3[y2][x2] == '1')
						{

							y2 += 1;
						}

						if (y2 == 0) {
							y2 += 1;
						}

						vec3[y2][x2] = '2';

						break;
					}

				}
				case 's':
				{

					if (y < 26) {

						vec3[y][x] = ' ';
						y += 1;
						if (vec3[y][x] == '#')
						{
							ff1();
							two.push_back(254);
							two_size = two.size();
							
							sum = 0;
							of = 1;



						}
						if (vec3[y][x] != ' ' and vec3[y][x] != s and vec3[y][x] != '2')
						{

							g++;
						}
						if (vec3[y][x] == s or vec3[y][x] == '2')
						{

							y -= 1;
						}

						if (y == 25)
						{
							y -= 1;
						}
						vec3[y][x] = '1';

						break;
					}

				}
				case 'g':
				{

					if (y2 < 26) {

						vec3[y2][x2] = ' ';
						y2 += 1;
						if (vec3[y2][x2] == '#')
						{
							ff2();
							one.push_back(254);
							one_size = one.size();
							
							sum = 0;
							of = 1;


						}
						if (vec3[y2][x2] != ' ' and vec3[y2][x2] != s and vec3[y2][x2] != '1')
						{

							g2++;
						}
						if (vec3[y2][x2] == s or vec3[y2][x2] == '1')
						{

							y2 -= 1;
						}

						if (y2 == 25)
						{
							y2 -= 1;
						}
						vec3[y2][x2] = '2';

						break;
					}

				}






				}
				if (of == 0) {
					system("cls");
					SetConsoleTextAttribute(handl, 10);
					cast();
					for (size_t i = 0; i < 26; i++)
					{

						for (size_t j = 0; j < 29; j++)
						{
							if (vec3[i][j] == '#') {
								SetConsoleTextAttribute(handl, 4);

							}
							if (vec3[i][j] == 'S') {
								SetConsoleTextAttribute(handl, 5);

							}
							if (vec3[i][j] == '1') {
								SetConsoleTextAttribute(handl, 1);

							}
							if (vec3[i][j] == '2') {
								SetConsoleTextAttribute(handl, 15);

							}
							if (vec3[i][j] == '@') {
								SetConsoleTextAttribute(handl, 14);

							}
							cout << vec3[i][j] << " ";
							SetConsoleTextAttribute(handl, 10);

						}
						cout << endl;
					}
					SetConsoleTextAttribute(handl, 1);
					cout << "coins one " << g << endl;
					for (size_t i = 0; i < one.size(); i++)
					{
						cout << one[i] << "";
					}cout << endl;
					SetConsoleTextAttribute(handl, 15);
					cout << "coins two " << g2 << endl;
					for (size_t i = 0; i < two.size(); i++)
					{
						cout << two[i] << "";
					}cout << endl;
					SetConsoleTextAttribute(handl, 10);


					sum = g + g2;
				}
			
			}
			
			
		}
		if (of == 1) {
			cout << "game 1  <" << endl;
			cout << "game 2 " << endl;
			cout << "ESC -- > EXET" << endl;
			coins = 0;
			 g = 0;
			g2 = 0;
			 sum = 0;

			break;
		}

	}
}

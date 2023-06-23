

#include <time.h> 
#include <vector> 
#include <Windows.h> 
#include < math.h> 
#include <conio.h>
#include <string>
#include "game _one .h"
#include "game_twu.h"
using namespace std;


void main()
{
	srand(time(NULL));


	int game_on = 0;
	SetConsoleTextAttribute(hand, 9);
	cout << "game 1  <" << endl;
	cout << "game 2 " << endl;
	cout << "ESC -- > EXET" << endl;
	int men = 1;
	int esc = 0;
	while (true)
	{
		if (esc == 1) {
			break;
		}
		
		
		if (_kbhit())
		{
			
			switch (_getch())
			{

			case 'w': {
				system("cls");
				cout << "game 1  <" << endl;
				cout << "game 2 " << endl;
				cout << "ESC -- > EXET" << endl;
				men = 1;
				break;
			}
			case's': {
				system("cls");

				cout << "game 1 " << endl;
				cout << "game 2  <" << endl;
				cout << "ESC -- > EXET" << endl;
				men = 2;
				break;
			}
				   case char(13) : {

					   if (men == 1) {
						   system("cls");
						   GAME_ONE();
						   men = 0;

					   }
					   if (men == 2) {
						   system("cls");
						   game();
						   men = 0;
					   }
					   break;
				   }
				   case char(27) : {

					   system("cls");
					   esc = 1;
					   break;
				   }


			}
		}
	}
}

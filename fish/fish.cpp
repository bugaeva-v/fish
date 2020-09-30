#include <iostream>
#include<ctime>
#include <windows.h>
#include<map>

using namespace std;

COORD position;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void SetPosition(int x, int y)
{
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(hConsole, position);
}
void SetPosition(int y)
{
	position.Y = y;
	SetConsoleCursorPosition(hConsole, position);
}
void SetPosition()
{
	SetConsoleCursorPosition(hConsole, position);
}
void time(int s) {
	int CLOCKS_PER_MSEC = CLOCKS_PER_SEC / 1000;
	clock_t end_time = clock() + s * CLOCKS_PER_MSEC;
	while (clock() < end_time) {}
	return;
}
map <string, int> color = { {"Black", 0},
							{"Blue", 1},
							{"Green", 2 },
							{"Cyan", 3},
							{"Red", 4},
							{"Magenta", 5},
							{"Brown", 6},
							{"LightGray", 7},
							{"DarkGray", 8},
							{"LightBlue", 9},
							{"LightGreen", 10},
							{"LightCyan", 11},
							{"LightRed", 12},
							{"LightMagenta", 13},
							{"Yellow", 14},
							{"White", 15} };

void ColorCout(char symbol, int color_background, int color_symbol) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_background << 4 | color_symbol);
	cout << symbol;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 << 4 | 7);
}
int main()
{
	int scale_x = 55, scale_y = 17;
	int speed = 100;
	double a = 5, b = 2.5;
	for (double y = 0; y <= scale_y; y++)// высота аквариума чистыми
	{
		for (double x = 0; x <= scale_x; x++)//длина аквариума чистыми
		{
			if (x == 0 || x == scale_x || y == scale_y)
				ColorCout('/', color["Black"], color["LightCyan"]);
			else
				cout << " ";
		}
		cout << endl;
	}
	SetPosition(1, 8);
	for (position.Y = 8; position.Y < scale_y;)
	{
		for (position.X = 1; position.X < scale_x; position.X++)
		{
			ColorCout('-', color["Black"], color["LightBlue"]);
		}
		SetPosition(1, position.Y + 1);
	}
	while (true) {
		SetPosition(1, 8);
		while (position.X <= 38) {
			time(speed);
			for (double y = -4; y < 4; y++)
			{
				for (double x = -9; x < 8; x++)
				{

					if ((x * x / a / a) + (y * y / b / b) <= 1)
						ColorCout('*', 0, 14);
					else if (-x - 5 >= y && x + 5 <= y && x >= -7)
						ColorCout('*', 0, 14);
					else
						ColorCout('-', 0, 9);
				}
				SetPosition(position.Y + 1);
			}
			if (position.X == 38)break;
			SetPosition(position.X + 1, 8);
			time(speed);
			for (double y = -4; y < 4; y++)
			{
				for (double x = -9; x < 8; x++)
				{

					if ((x * x / a / a) + (y * y / b / b) <= 1)
						ColorCout('*', 0, 14);
					else if (-x - 5 >= y / 2 && x + 5 <= y / 2 && x >= -6)
						ColorCout('*', 0, 14);
					else
						ColorCout('-', 0, 9);
				}
				SetPosition(position.Y + 1);
			}
			SetPosition(position.X + 1, 8);
		}
		SetPosition(38, 8);

		a = 2.5;

		time(speed);
		for (double y = -4; y < 4; y++)
		{
			for (double x = -9; x < 8; x++)
			{

				if ((x * x / a / a) + (y * y / b / b) <= 1)
					ColorCout('*', 0, 14);
				else if (-x - 3 >= y && x + 3 <= y && x >= -4)
					ColorCout('*', 0, 14);
				else
					ColorCout('-', 0, 9);
			}
			SetPosition(position.Y + 1);
		}
		SetPosition(8);

		a = 1;

		time(speed);
		for (double y = -4; y < 4; y++)
		{
			for (double x = -9; x < 8; x++)
			{

				if ((x * x / a / a) + (y * y / b / b) <= 1)
					ColorCout('*', 0, 14);
				else if (-x - 1 >= y && x + 1 <= y && x >= -1.4)
					ColorCout('*', 0, 14);
				else
					ColorCout('-', 0, 9);
			}
			SetPosition(position.Y + 1);
		}
		SetPosition(8);

		a = 2.5;

		time(speed);
		for (double y = -4; y < 4; y++)
		{
			for (double x = -7; x < 10; x++)
			{

				if ((x * x / a / a) + (y * y / b / b) <= 1)
					ColorCout('*', 0, 14);
				else if (x - 3 >= y && -x + 3 <= y && x <= 4)
					ColorCout('*', 0, 14);
				else
					ColorCout('-', 0, 9);
			}
			SetPosition(position.Y + 1);
		}

		a = 5;

		SetPosition(position.X - 1, 8);
		while (position.X >= 1) {
			time(speed);
			for (double y = -4; y < 4; y++)
			{
				for (double x = -7; x < 10; x++)
				{

					if (x * x / a / a + y * y / b / b <= 1)
						ColorCout('*', 0, 14);
					else if (x - 5 >= y && -x + 5 <= y && x <= 7)
						ColorCout('*', 0, 14);
					else
						ColorCout('-', 0, 9);
				}
				SetPosition(position.Y + 1);
			}
			if (position.X == 1)break;
			SetPosition(position.X - 1, 8);
			time(speed);
			for (double y = -4; y < 4; y++)
			{
				for (double x = -7; x < 10; x++)
				{

					if (x * x / a / a + y * y / b / b <= 1)
						ColorCout('*', 0, 14);
					else if (x - 5 >= y / 2 && -x + 5 <= y / 2 && x <= 6)
						ColorCout('*', 0, 14);
					else
						ColorCout('-', 0, 9);
				}
				SetPosition(position.Y + 1);
			}
			SetPosition(position.X - 1, 8);
		}
		SetPosition(1, 8);

		a = 2.5;

		time(speed);
		for (double y = -4; y < 4; y++)
		{
			for (double x = -9; x < 8; x++)
			{

				if ((x * x / a / a) + (y * y / b / b) <= 1)
					ColorCout('*', 0, 14);
				else if (x - 3 >= y && -x + 3 <= y && x <= 4)
					ColorCout('*', 0, 14);
				else
					ColorCout('-', 0, 9);
			}
			SetPosition(position.Y + 1);
		}
		SetPosition(8);
		a = 1;
		time(speed);
		for (double y = -4; y < 4; y++)
		{
			for (double x = -9; x < 8; x++)
			{

				if ((x * x / a / a) + (y * y / b / b) <= 1)
					ColorCout('*', 0, 14);
				else if (x - 1 >= y && -x + 1 <= y && x <= 1.4)
					ColorCout('*', 0, 14);
				else
					ColorCout('-', 0, 9);
			}
			SetPosition(position.Y + 1);
		}
		SetPosition(8);
		a = 2.5;
		time(speed);
		for (double y = -4; y < 4; y++)
		{
			for (double x = -7; x < 10; x++)
			{

				if ((x * x / a / a) + (y * y / b / b) <= 1)
					ColorCout('*', 0, 14);
				else if (-x - 3 >= y && x + 3 <= y && x >= -4)
					ColorCout('*', 0, 14);
				else
					ColorCout('-', 0, 9);
			}
			SetPosition(position.Y + 1);
		}
		a = 5;
	}
}
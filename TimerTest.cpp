#include <iostream>
#include <Windows.h>

using namespace std;

const int COLS = 11;

const int ROWS = 11;

char canvas[ROWS][COLS * 5] = { {0} };

const char CLOCK_CHAR = 'O';

const char* const codes[] =
{

	// digit 0 
	"11111111111000000001100000000110000000011000000001100000000110000000011000000001100000000110000000011111111111",
	// digit 1 
	"00000000010000000001000000000100000000010000000001000000000100000000010000000001000000000100000000010000000001",
	// digit 2 
	"11111111110000000001000000000100000000010000000001111111111110000000001000000000100000000010000000001111111111",
	// digit 3 
	"11111111110000000001000000000100000000010000000001111111111100000000010000000001000000000100000000011111111111",
	// digit 4 
	"10000000011000000001100000000110000000011000000001111111111100000000010000000001000000000100000000010000000001",
	// digit 5 
	"11111111111000000000100000000010000000001000000000111111111100000000010000000001000000000100000000011111111111",
	// digit 6 
	"11111111111000000000100000000010000000001000000000111111111110000000011000000001100000000110000000011111111111",
	// digit 7 
	"11111111110000000001000000000100000000010000000001000000000100000000010000000001000000000100000000010000000001",
	// digit 8 
	"11111111111000000001100000000110000000011000000001111111111110000000011000000001100000000110000000011111111111",
	// digit 9 
	"11111111111000000001100000000110000000011000000001111111111100000000010000000001000000000100000000011111111111",
	// semi-colon separator 
	"00010010000"
};

void storeDigit(int digit, int offset)
{

	for (int row = 0; row < ROWS; row++)
	{

		for (int col = 0; col < COLS; col++)
		{

			int x = offset + col;

			int y = row;

			int dot = COLS * row + col;

			if ('1' == codes[digit][dot])
			{

				canvas[y][x] = CLOCK_CHAR;

			}

		}

	}

}
//
void secToMin(int& secInput, int& minsInput)
{
		minsInput++;
		secInput -= 60;
}


void minToSec(int& minInput, int& secInput)
{
	minInput--;
	secInput += 60;
}


int main()
{
	int minutes = 0;
	int seconds = 0;
	cin >> seconds;

	while (seconds > 60)
	{
		secToMin(seconds, minutes);
	}

STARTOFTIMER:
	if (seconds >= 60)
	{
		secToMin(seconds, minutes);
	}
	if (seconds <= 0)
	{
		if (minutes > 0)
		{
			minToSec(minutes, seconds);
		}
		else cout << "Time is up";
	}

	if (minutes < 10)
	{
		storeDigit(0, 0);
		storeDigit(minutes, 11);
		storeDigit(10, 22);
		storeDigit(seconds / 10, 24);
		storeDigit(seconds % 10, 35);
	}

	//prins canvas
	for (int row = 0; row < ROWS; row++)
	{

		for (int col = 0; col < COLS * 5; col++)
		{

			cout << canvas[row][col];

		}

		cout << endl;

	}

	seconds--;
	Sleep(1000);
	goto STARTOFTIMER;
}
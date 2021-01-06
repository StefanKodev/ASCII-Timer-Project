#include <iostream>
#include <Windows.h>

using namespace std;

const int COLS = 11;

const int ROWS = 11;

const int numOfNums = 10;
const int numOfLines = 11;

const char* const codes[numOfNums][numOfLines] =
{
	{
		// digit 0 
		"0000000000",
		"0        0",
		"0        0",
		"0        0",
		"0        0",
		"0        0",
		"0        0",
		"0        0",
		"0        0",
		"0        0",
		"0000000000"
		},
	// digit 1 
	{
	"         1",
	"         1",
	"         1",
	"         1",
	"         1",
	"         1",
	"         1",
	"         1",
	"         1",
	"         1",
	"         1"
	},
	// digit 2 
	{
	"2222222222",
	"         2",
	"         2",
	"         2",
	"         2",
	"2222222222",
	"2         ",
	"2         ",
	"2         ",
	"2         ",
	"2222222222"
	},
	// digit 3 
	{
	"3333333333",
	"         3",
	"         3",
	"         3",
	"         3",
	"3333333333",
	"         3",
	"         3",
	"         3",
	"         3",
	"3333333333"
	},
	// digit 4 
		{
		"4        4",
		"4        4",
		"4        4",
		"4        4",
		"4        4",
		"4444444444",
		"         4",
		"         4",
		"         4",
		"         4",
		"         4"
		},
	// digit 5 
	{
	"5555555555",
	"5         ",
	"5         ",
	"5         ",
	"5         ",
	"5555555555",
	"         5",
	"         5",
	"         5",
	"         5",
	"5555555555"
	},
	// digit 6 
	{
	"6666666666",
	"6         ",
	"6         ",
	"6         ",
	"6         ",
	"6666666666",
	"6        6",
	"6        6",
	"6        6",
	"6        6",
	"6666666666"
	},
	// digit 7 
	{
	"7777777777",
	"         7",
	"         7",
	"         7",
	"         7",
	"         7",
	"         7",
	"         7",
	"         7",
	"         7",
	"         7"
	},
	// digit 8 
	{
	"8888888888",
	"8        8",
	"8        8",
	"8        8",
	"8        8",
	"8888888888",
	"8        8",
	"8        8",
	"8        8",
	"8        8",
	"8888888888"
	},
	// digit 9 
	{
	"9999999999",
	"9        9",
	"9        9",
	"9        9",
	"9        9",
	"9999999999",
	"         9",
	"         9",
	"         9",
	"         9",
	"9999999999"
	}
};

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
	int minHund = 0;
	int minTens;
	int minUnits;
	int secTens;
	int secUnits;
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
		else goto ENDOFTIMER;
	}

	if (minutes < 10)
	{
		minTens = 0;
		minUnits = minutes % 10;
		secTens = seconds / 10;
		secUnits = seconds % 10;
	}
	else if (minutes >= 10 && minutes < 100)
	{
		minTens = minutes / 10;
		minUnits = minutes % 10;
		secTens = seconds / 10;
		secUnits = seconds % 10;
	}
	else
	{
		minHund = minutes / 100;
		minTens = (minutes % 100) / 10;
		minUnits = minutes % 10;
		secTens = seconds / 10;
		secUnits = seconds % 10;
	}


	if (minutes < 100)
	{
		for (int i = 0; i < ROWS; i++)
		{
			cout << codes[minTens][i];
			cout << " ";
			cout << codes[minUnits][i];
			cout << " ";
			if (i == 4 || i == 7) cout << char(178);
			else cout << " ";
			cout << " ";
			cout << codes[secTens][i];
			cout << " ";
			cout << codes[secUnits][i];
			cout << " ";
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < ROWS; i++)
		{
			cout << codes[minHund][i];
			cout << " ";
			cout << codes[minTens][i];
			cout << " ";
			cout << codes[minUnits][i];
			cout << " ";
			if (i == 4 || i == 7) cout << char(178);
			else cout << " ";
			cout << " ";
			cout << codes[secTens][i];
			cout << " ";
			cout << codes[secUnits][i];
			cout << " ";
			cout << endl;
		}
	}

	seconds--;
	Sleep(1000);
	system("cls");
	goto STARTOFTIMER;


ENDOFTIMER:
	for (int i = 0; i < ROWS; i++)
	{
		cout << codes[0][i];
		cout << " ";
		cout << codes[0][i];
		cout << " ";
		if (i == 4 || i == 7) cout << char(178);
		else cout << " ";
		cout << " ";
		cout << codes[0][i];
		cout << " ";
		cout << codes[0][i];
		cout << " ";
		cout << endl;
	}
	PlaySound(TEXT("alarmsound.wav") , NULL, SND_SYNC);

}

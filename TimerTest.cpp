#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

const int COLS = 11;

const int ROWS = 11;

const int numOfNums = 10;
const int numOfLines = 11;

// This is an array that contains all of the different digits from 0 to 9 all written down line by line
// because that is how we are going to be printing them out in the console.
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

void secToMin(int& secInput, int& minsInput) // simple funtion that transforms sec into min
{
	minsInput++;
	secInput -= 60;
}


void minToSec(int& minInput, int& secInput) // simple function that transforms min into sec
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
	system("cls");

	while (seconds > 60) // if the sec are more than 60 in the input we transform them into mins
	{
		secToMin(seconds, minutes);
	}

STARTOFTIMER:
	if (seconds >= 60) // we check if the sec are more than 60 and if so we transoform them into mins
	{
		secToMin(seconds, minutes);
	}
	if (seconds < 0)
	{
		if (minutes > 0) // if the sec are less than 0 are we have more mins we transform one min into 60 sec
		{
			minToSec(minutes, seconds);
		}
		else goto ENDOFTIMER; // else we go to the end of the program
	}

	if (minutes < 10) // if the mins are less than 10 we set the minTens to 0
	{
		minTens = 0;
		minUnits = minutes % 10;
		secTens = seconds / 10;
		secUnits = seconds % 10;
	}
	else if (minutes >= 10 && minutes < 100) // else if the mins are between 10 and 100 we set them to min/10
	{
		minTens = minutes / 10;
		minUnits = minutes % 10;
		secTens = seconds / 10;
		secUnits = seconds % 10;
	}
	else // the mins cant be more than ~165 so we dont need a 4 digit number for the mins the max digits is 3
	{
		minHund = minutes / 100;
		minTens = (minutes % 100) / 10;
		minUnits = minutes % 10;
		secTens = seconds / 10;
		secUnits = seconds % 10;
	}

	if (minutes < 100) // if the mins are less than 100 we print out a 4 digit timer "mm:ss"
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
	else // else we print out a 5 digit timer "mmm:ss" 
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

	seconds--; //seconds goes down by one
	Sleep(1000); // we wait one second
	system("cls"); // clears the console for the next print
	goto STARTOFTIMER; // go to the begining


ENDOFTIMER:
	for (int i = 0; i < ROWS; i++) // prints out "00:00"
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
	PlaySound(TEXT("alarmsound.wav") , NULL, SND_SYNC); // plays a sound 

}

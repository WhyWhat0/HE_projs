#include <conio.h>
#include<stdio.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include<windows.h>

using namespace std;

#define KEY_UP    72
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_DOWN  80

int main()
{
    const int KEY_ARROW_CHAR1 = 224;
    const int KEY_ARROW_UP = 72;
    const int KEY_ARROW_DOWN = 80;
    const int KEY_ARROW_LEFT = 75;
    const int KEY_ARROW_RIGHT = 77;

    unsigned char ch1 = _getch();
    if (ch1 == KEY_ARROW_CHAR1)
    {
        // Some Arrow key was pressed, determine which?
        unsigned char ch2 = _getch();
        switch (ch2)
        {
        case KEY_ARROW_UP:
            // code for arrow up
            cout << "KEY_ARROW_UP" << endl;
            break;
        case KEY_ARROW_DOWN:
            // code for arrow down
            cout << "KEY_ARROW_DOWN" << endl;
            break;
        case KEY_ARROW_LEFT:
            // code for arrow right
            cout << "KEY_ARROW_LEFT" << endl;
            break;
        case KEY_ARROW_RIGHT:
            // code for arrow left
            cout << "KEY_ARROW_RIGHT" << endl;
            break;
        }
    }
    else
    {
        switch (ch1)
        {
            Beep(400, 50);
        }
    }

    return 0;
}
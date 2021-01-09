#pragma once
#include <iostream>
#include <dos.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>


const int screen_height = 12;
const int screen_width = 44;

std::string months[] = { "JAN", "FEB", "MAR","APR","MAY","JUN","JUL",
                            "AUG","SEP","OCT","NOV","DEC" };

char zero[5][3] = { 178,178,178,
                  178,' ',178,
                  178,' ',178,
                  178,' ',178,
                  178,178,178 };

char one[5][3] = { ' ',' ',178,
                  ' ',' ',178,
                  ' ',' ',178,
                  ' ',' ',178,
                  ' ',' ',178 };

char two[5][3] = { 178,178,178,
                  ' ',' ',178,
                  178,178,178,
                  178,' ',' ',
                  178,178,178 };

char three[5][3] = { 178,178,178,
                  ' ',' ',178,
                  ' ',178,178,
                  ' ',' ',178,
                  178,178,178 };

char four[5][3] = { 178,' ',178,
                  178,' ',178,
                  178,178,178,
                  ' ',' ',178,
                  ' ',' ',178 };

char five[5][3] = { 178,178,178,
                  178,' ',' ',
                  178,178,178,
                  ' ',' ',178,
                  178,178,178 };

char six[5][3] = { 178,178,178,
                  178,' ',' ',
                  178,178,178,
                  178,' ',178,
                  178,178,178 };

char seven[5][3] = { 178,178,178,
                     ' ',' ',178,
                     ' ',' ',178,
                     ' ',' ',178,
                     ' ',' ',178, };

char eight[5][3] = { 178,178,178,
                  178,' ',178,
                  178,178,178,
                  178,' ',178,
                  178,178,178 };

char nine[5][3] = { 178,178,178,
                  178,' ',178,
                  178,178,178,
                  ' ',' ',178,
                  178,178,178 };

char colon[5][3] = { ' ',' ',' ',
                     ' ',178,' ',
                     ' ',' ',' ',
                     ' ',178,' ',
                     ' ',' ',' ' };



HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursorPos;

void gotoxy(int x, int y)
{
    cursorPos.X = x;
    cursorPos.Y = y;
    SetConsoleCursorPosition(console, cursorPos);
}


void setCursor(bool visible, DWORD size)
{
    if (size == 0)
        size = 20;

    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);

}


void printNum(int num, int x, int y)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            switch (num)
            {
            case 0: gotoxy(x + j, y + i);
                std::cout << zero[i][j];
                break;

            case 1: gotoxy(x + j, y + i);
                std::cout << one[i][j];
                break;

            case 2: gotoxy(x + j, y + i);
                std::cout << two[i][j];
                break;

            case 3: gotoxy(x + j, y + i);
                std::cout << three[i][j];
                break;

            case 4: gotoxy(x + j, y + i);
                std::cout << four[i][j];
                break;

            case 5: gotoxy(x + j, y + i);
                std::cout << five[i][j];
                break;

            case 6: gotoxy(x + j, y + i);
                std::cout << six[i][j];
                break;

            case 7: gotoxy(x + j, y + i);
                std::cout << seven[i][j];
                break;

            case 8: gotoxy(x + j, y + i);
                std::cout << eight[i][j];
                break;

            case 9: gotoxy(x + j, y + i);
                std::cout << nine[i][j];
                break;

            case 10: gotoxy(x + j, y + i);
                std::cout << colon[i][j];
                break;
            }
        }
    }
}


void drawScreen()
{

    for (size_t i = 0; i <= screen_height; i++)
    {
        for (size_t j = 6; j <= screen_width; j++)
        {
            gotoxy(j, 0);
            std::cout << '\xDC';
            gotoxy(j, screen_height);
            std::cout << '\xDC';
            gotoxy(6, i);
            std::cout << '\xDB';
            gotoxy(screen_width, i);
            std::cout << '\xDB';
        }
    }
}


void displayClock()
{
    setCursor(0, 0);

    srand((unsigned)time(NULL));

    time_t now = time(NULL);

    char dt[26] = {};

    ctime_s(dt, 26, &now);

    tm lt = {};

    localtime_s(&lt, &now);

    asctime_s(dt, 26, &lt);

    int h = lt.tm_hour;
    int m = lt.tm_min;
    int s = lt.tm_sec;

    int year = 1900 + lt.tm_year;
    int mon = lt.tm_mon;
    int day = lt.tm_mday;


    while (true)
    {
        system("cls");

        drawScreen();

        int numX = 10, numY = 5;

        // print date

        gotoxy(screen_width / 2, 2);
        std::cout << day << " " << months[mon] << " " << year;

        // print hour

        if (h >= 10)
        {
            printNum(h / 10, numX, numY);
            printNum(h % 10, numX += 4, numY);
        }
        else
        {
            printNum(0, numX, numY);
            printNum(h, numX += 4, numY);
        }

        printNum(10, numX += 4, numY);

        // print minutes

        if (m >= 10)
        {
            printNum(m / 10, numX += 4, numY);
            printNum(m % 10, numX += 4, numY);
        }
        else
        {
            printNum(0, numX += 4, numY);
            printNum(m, numX += 4, numY);
        }

        printNum(10, numX += 4, numY);

        // print seconds

        if (s >= 10)
        {
            printNum(s / 10, numX += 4, numY);
            printNum(s % 10, numX += 4, numY);
        }
        else
        {
            printNum(0, numX += 4, numY);
            printNum(s, numX += 4, numY);
        }

        // updating time

        if (s >= 59)
        {
            s = 0;
            m++;
        }

        if (m >= 59)
        {
            m = 0;
            h++;
        }

        if (h >= 23)
        {
            s = 0;
            m = 0;
            h = 0;
        }

        if (h < 12)
        {
            gotoxy(screen_width - 3, screen_height - 1);
            std::cout << "AM";
        }
        else
        {
            gotoxy(screen_width - 3, screen_height - 1);
            std::cout << "PM";
        }

        // to stop the watch

        if (_kbhit())
        {
            char k = _getch();

            if (k == 32)
            {
                break;
            }
        }

        Sleep(950);
        s++;
    }
}

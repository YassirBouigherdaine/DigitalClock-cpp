#pragma once
#include <iostream>
#include <dos.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>



void gotoxy(int x, int y);

void setCursor(bool visible, DWORD size);

void printNum(int, int, int);

void drawScreen();

void setAlarm();

void printTime();

void options();
    
void displayClock();
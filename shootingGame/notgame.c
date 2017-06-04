/*
	notgame.c: functions that are not related with game itself.
*/

// header file
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "Console.h"
// define constant value
#define ScreenWidth 80
#define ScreenHeight 24 

// function declaration
void DrawLogo();
void DrawBoundary();
void HelpScreen(); // ����
void ExitGame(); // ���� ����

// function definition
void DrawLogo()
{
	gotoxy(17,1);
	printf("  *** STRIKERS 1945 - C Programming Version ***  ");
}
void DrawBoundary()
{
	int i=0;
	clrscr();
	gotoxy(1,1);
	for(i=0; i<ScreenWidth; i++)
		putchar('#');
	for(i=1; i<=ScreenHeight; i++){
		gotoxy(1,i);
		putchar('#');
		gotoxy(ScreenWidth, i);
		putchar('#');
	} // for
	gotoxy(1, ScreenHeight);
	for(i=0; i<ScreenWidth; i++)
		putchar('#');
}
void HelpScreen() // ����
{
	clrscr();
	DrawBoundary();
	DrawLogo();
	gotoxy(10,5);
	printf("\tŰ ����:");
	gotoxy(10,7);
	printf("�·� �̵�: j");
	gotoxy(10,8);
	printf("��� �̵�: k");
	gotoxy(10,10);
	printf("�̻��� �߻�: a");
	gotoxy(10,13);
	printf("��ź ����: s");
	gotoxy(10,14);
	printf("��ź�� ������ �ð��� �������� �ϳ��� ȸ���˴ϴ�.");
	gotoxy(10,20);
	printf("Made by Sung-Hyun, Lee");
	gotoxy(10,23);
	system("PAUSE");
}
void ExitGame() // ���� ����
{
	clrscr();
	printf("STRIKERS 1945 C-Programming Version.\n");
	printf("Made by Sung-Hyun, Lee\n\n");
	printf("e-mail: caleb-@hanmail.net\n");
}
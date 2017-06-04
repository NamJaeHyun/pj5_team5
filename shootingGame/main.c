/*
1�� ����

20700486 �̼���

Term-Project: STRIKERS 1945

Visual C++
*/
/*
2�� ����

main.c/Console.c/game_play.c/notgame.c

Team-Project : ���¼ҽ�SW����

Created by OSS_TEAM5 on 2017. 6.

Copyright @ 2017. 5. OSS_TEAM5. All rights reserved.

Visual C++

*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // for getch
#include "Console.h"

// Global Variables Declaration
char selection = 0; // �޴� ���� ����

				 // Functions Declaration
int StartMenu(char selection); // ���� �޴�
int GamePlay();
void HelpScreen();
void ExitGame(); // ���� ���� ���� ����

				 //���� �ΰ� �׸���
void DrawBoundary();
void DrawLogo();

					 // main function
int main()
{
	RankLoad();

	while (1)
	{

		selection = StartMenu(selection);
		switch (selection) {
		case '1': // ���� ����
			GamePlay();
			break;
		case '2': // Ranking Ȯ��
			ViewRanking();
			break;
		case '3': // ����
			HelpScreen();
			break;
		case '4': // ���� ����
			ExitGame();
			system("PAUSE");
			return 0;
			break;
		} // switch
	} // while
	return 0;
}

int StartMenu(char selection) // Menu
{
	do {
		clrscr();
		DrawBoundary();
		DrawLogo();
		gotoxy(10, 5);
		printf("1. ���� ����");
		gotoxy(10, 8);
		printf("2. Ranking Ȯ��");
		gotoxy(10, 11);
		printf("3. ����");
		gotoxy(10, 14);
		printf("4. ���� ����");
		gotoxy(10, 20);
		printf(" ��ȣ �Է�: ");
		selection = getch();
		if (selection != '1'&&selection != '2'&&selection != '3'&&selection != '4') {
			printf("#    �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���. \n");
			printf("#    ");
			system("PAUSE");
		} // if
	} while (selection != '1'&&selection != '2'&&selection != '3'&&selection != '4'); // while
	return selection;
}
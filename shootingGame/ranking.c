#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "Console.h"

#define clrscr() system("cls")
#define ESC 27
#define D 68
#define d 100


struct data {

	char name[10];
	int realscore;

};	// �̸��� ���� ����

struct data rank[17];	// data����ü 17���� ������ �迭

						/* ���Ͽ� ��� ���� */
void FileSave(void)
{
	FILE *rankfile;
	rankfile = fopen("rank.txt", "wt");

	int i;

	/* ���Ͽ� 1����� 16�� ���� ��� */
	for (i = 0; i<16; i++) {

		if (rank[i].realscore == 0)
			fprintf(rankfile, "0 ....\n");

		else
			fprintf(rankfile, "%d %s\n", rank[i].realscore, rank[i].name);
	}
	fclose(rankfile);
}

/* ���� ��ŷ ��ϰ� ���ο� ���� ������ ���Ͽ� ����*/
void RankSort(void)
{
	int i, j;
	struct data temp;

	for (i = 0; i<16; i++)
	{
		for (j = 0; j<17; j++)
		{
			if (rank[j].realscore < rank[j + 1].realscore)
			{
				temp = rank[j];
				rank[j] = rank[j + 1];
				rank[j + 1] = temp;
			}
		}
	}
	FileSave();
}

/* ��ŷ�� ����� �̸��� ������ �Է¹ް� ���� */
void WriteRank(int realscore)
{
	gotoxy(33, 20);
	printf("NAME : ");
	gotoxy(41, 20);
	fgets(rank[16].name, 10, stdin);

	rank[16].realscore = realscore;
	RankSort();
	FileSave();
}

/* ��ŷ ���� �ʱ�ȭ */
void RankAllDel(void)
{
	int i;
	for (i = 0; i<17; i++)
		rank[i].realscore = 0; // ��� ������ ������ 0���� ����

	FileSave();
}

/* ���� �ε� */
void RankLoad(void)
{
	int i;
	FILE *rankfile;

	rankfile = fopen("rank.txt", "rt");

	if (rankfile == NULL) {		// ������ ���� ���, ������ ��������
		rankfile = fopen("rank.txt", "a");
		fclose(rankfile);
		return;
	}

	for (i = 0; i < 16; i++) {
		fscanf(rankfile, "%d %s\n", &rank[i].realscore, &rank[i].name);
	}

	fclose(rankfile);

}

/* ��ŷ �׸��� - ���*/
void RankDetailDraw()
{

	for (int i = 0; i < 8; i++)
	{
		gotoxy(5, (2 + i) * 3);
		printf("%d", i + 1);
		gotoxy(48, (2 + i) * 3);
		printf("%d", i + 9);
		gotoxy(18, (2 + i) * 3);
		printf("%s", rank[i].name);
		gotoxy(62, (2 + i) * 3);
		printf("%s", rank[i + 8].name);
		gotoxy(35, (2 + i) * 3);
		printf("%d", rank[i].realscore);
		gotoxy(80, (2 + i) * 3);
		printf("%d", rank[i + 8].realscore);

	}

	for (int i = 0; i < 24; i++)
	{
		gotoxy(42, 5 + i);
		printf("|");
	}

}

/* ��ŷ �׸��� */
void ViewRanking(void)
{
	clrscr();
	RankLoad();
	RankSort();

	RankDetailDraw();

	// Ű �Է�
	while (1)
	{
		int key;
		key = getch();

		if (key == D || key == d)
		{
			RankAllDel();
			break;
		}
		if (key == ESC)
		{
			break;
		}
	}
	system("cls");
}

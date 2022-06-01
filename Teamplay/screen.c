#include "common.h"

extern int level;
extern int point;

void title(void)
{
	int ch;

	emptyinfo();

	gotoxy(16, 12);
	printf("���� ã�� ����");

	gotoxy(15, 8);
	printf("   Enter�� ����");

	while (1) {
		ch = _getch();
		if (ch == 13)
			break;
	}
}

void emptyscreen(void)
{
	for (int i = 0; i < XAXIS + 2; i++) {
		printf("��");
	}
	printf("\n");

	for (int j = YAXIS - 1; j >= 0; j--) {
		printf("��");
		for (int i = 0; i < XAXIS; i++) {
			printf("  ");
		}
		printf("��");
		printf("\n");
	}

	for (int i = 0; i < XAXIS + 2; i++) {
		printf("��");
	}

	gotoxy(-1, -2);
	for (int i = 0; i < XAXIS + 20; i++) {
		printf("--");
	}
}

void emptyinfo(void)
{
	for (int i = 0; i < YAXIS; i++) {
		gotoxy(XAXIS + 1, i);
		printf("                              ");
	}
}

void screenchange(void)
{
	for (int i = YAXIS - 1; i >= 0; i--) {
		gotoxy(0, i);
		for (int j = 0; j < XAXIS; j++) {
			printf("��");
		}
		Sleep(15);
	}

	Sleep(200);

	for (int i = 0; i < YAXIS; i++) {
		gotoxy(0, i);
		for (int j = 0; j < XAXIS; j++) {
			printf("  ");
		}
		Sleep(15);
	}
}

void infoprint(void)
{
	gotoxy(XAXIS + 4, YAXIS - 3);
	printf("                    ");
	gotoxy(XAXIS + 4, YAXIS - 3);
	printf("���� ���� :         ����");

	gotoxy(XAXIS + 2, YAXIS - 4);
	printf("                    ");
	gotoxy(XAXIS + 6, YAXIS - 4);
	printf(" ���� :         ��");

	gotoxy(XAXIS + 1, YAXIS - 5);
	printf(" ���� �̵� Ƚ�� :         ��");

	gotoxy(XAXIS + 6, YAXIS - 6);
	printf(" ü�� : ");
}

void levelshow(void)
{
	gotoxy(13, 13);
	printf("����������������������������������������������");
	gotoxy(13, 12);
	printf("��                     ��");
	gotoxy(13, 11);
	printf("��                     ��");
	gotoxy(13, 10);
	printf("��                     ��");
	gotoxy(13, 9);
	printf("��                     ��");
	gotoxy(13, 8);
	printf("��                     ��");
	gotoxy(13, 7);
	printf("����������������������������������������������");

	gotoxy(16, 10);
	printf("Level %4d", level);

	Sleep(1000);
}

int pausemenu(void)
{
	int ch;
	int n = 1;

	gotoxy(13, 15);
	printf("����������������������������������������������");
	gotoxy(13, 14);
	printf("��                     ��");
	gotoxy(13, 13);
	printf("��                     ��");
	gotoxy(13, 12);
	printf("��                     ��");
	gotoxy(13, 11);
	printf("��                     ��");
	gotoxy(13, 10);
	printf("��                     ��");
	gotoxy(13, 9);
	printf("��                     ��");
	gotoxy(13, 8);
	printf("��                     ��");
	gotoxy(13, 7);
	printf("��                     ��");
	gotoxy(13, 6);
	printf("��                     ��");
	gotoxy(13, 5);
	printf("��                     ��");
	gotoxy(13, 4);
	printf("����������������������������������������������");

	gotoxy(16, 14);
	printf("�Ͻ�����");

	gotoxy(16, 12);
	printf("1. ����ϱ�");

	gotoxy(16, 10);
	printf("2. �ٽ��ϱ�");

	gotoxy(16, 8);
	printf("3. Ÿ��Ʋ��");

	gotoxy(16, 6);
	printf("4. ��������");

	while (1) {
		gotoxy(15, 13 - 2 * n);
		printf("-----------------");

		ch = _getch();
		gotoxy(15, 13 - 2 * n);
		printf("                 ");

		if (ch == 224) {
			ch = _getch();
			switch (ch) {
			case 72:
				if (n != 1) {
					n -= 1;
				}
				else {
					n = 4;
				}
				break;
			case 80:
				if (n != 4) {
					n += 1;
				}
				else {
					n = 1;
				}
				break;
			}
		}
		else if (ch == 13)
			break;
	}

	tableprint();

	if (n == 1) return 0;
	else return n;
}

int gameover(void)
{
	int ch, n = 2;

	gotoxy(13, 17);
	printf("����������������������������������������������");
	gotoxy(13, 16);
	printf("��                     ��");
	gotoxy(13, 15);
	printf("��                     ��");
	gotoxy(13, 14);
	printf("��                     ��");
	gotoxy(13, 13);
	printf("��                     ��");
	gotoxy(13, 12);
	printf("��                     ��");
	gotoxy(13, 11);
	printf("��                     ��");
	gotoxy(13, 10);
	printf("��                     ��");
	gotoxy(13, 9);
	printf("��                     ��");
	gotoxy(13, 8);
	printf("��                     ��");
	gotoxy(13, 7);
	printf("��                     ��");
	gotoxy(13, 6);
	printf("��                     ��");
	gotoxy(13, 5);
	printf("��                     ��");
	gotoxy(13, 4);
	printf("����������������������������������������������");

	gotoxy(15, 15);
	printf("Game over");

	gotoxy(15, 13);
	printf("���� : %8d", point);

	gotoxy(15, 11);
	printf("�ٽ� �Ͻðڽ��ϱ�?");

	gotoxy(15, 9);
	printf("1. �ٽ��ϱ�");

	gotoxy(15, 7);
	printf("2. ��������");

	while (1) {
		gotoxy(15, 10 - n);
		printf("-----------------");

		ch = _getch();
		gotoxy(15, 10 - n);
		printf("                 ");

		if (ch == 224) {
			ch = _getch();
			switch (ch) {
			case 72:
				if (n == 2)
					n = 4;
				else
					n = 2;
				break;
			case 80:
				if (n == 4)
					n = 2;
				else
					n = 4;
				break;
			}
		}
		else if (ch == 13)
			break;
	}

	return n;
}
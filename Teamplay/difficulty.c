#include "common.h"

extern int dif;

void difficulty(void)
{
	int yes = 1;
	int ch;

	emptyinfo();

	while (1) {
		gotoxy(15, 16);
		printf("���̵��� �����ϼ���");

		gotoxy(15, 14);
		printf("1. ����");

		gotoxy(15, 12);
		printf("2. ����");

		gotoxy(15, 10);
		printf("3. �����");

		gotoxy(15, 8);
		printf("4. �ſ� �����");

		gotoxy(44, 17);
		printf("��, �� �� �̵�");

		gotoxy(44, 16);
		printf("Enter�� ����");

		while (1) {
			gotoxy(15, (15 - (2 * dif)));
			printf("-------------------");

			ch = _getch();
			gotoxy(15, (15 - (2 * dif)));
			printf("                   ");

			if (ch == 224) {
				ch = _getch();
				switch (ch) {
				case 72:
					if (dif != 1) {
						dif -= 1;
					}
					else {
						dif = 4;
					}
					break;
				case 80:
					if (dif != 4) {
						dif += 1;
					}
					else {
						dif = 1;
					}
					break;
				}
			}
			else if (ch == 13)
				break;
		}

		for (int i = 0; i < YAXIS; i++) {
			for (int j = 0; j < XAXIS; j++) {
				gotoxy(j, i);
				printf("  ");
			}
		}

		gotoxy(15, 16);

		switch (dif) {
		case 1:
			printf("����");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("�����");
			break;
		case 4:
			printf("�ſ� �����");
			break;
		}
		printf("���� �Ͻðڽ��ϱ�?");

		gotoxy(15, 14);
		printf("1. ��");

		gotoxy(15, 12);
		printf("2. �ƴϿ�");

		while (1) {
			gotoxy(15, 12 + yes);
			printf("-------------------");

			ch = _getch();

			gotoxy(15, 12 + yes);
			printf("                   ");

			if (ch == 224) {
				ch = _getch();
				switch (ch) {
				case 72:
				case 80:
					yes *= -1;
					break;
				}
			}
			else if (ch == 13)
				break;
		}

		for (int i = 0; i < YAXIS; i++) {
			for (int j = 0; j < XAXIS; j++) {
				gotoxy(j, i);
				printf("  ");
			}
		}

		if (yes == 1)
			break;
		else
			continue;
	}
}
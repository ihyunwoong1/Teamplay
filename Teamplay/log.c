#include "common.h"

extern int log[5];

void logprint(int n)
{
	switch (n)
	{
	case 1:
		printf("* ������ ã�ҽ��ϴ�!");
		break;
	case 2:
		printf("* ������ �ֿ����ϴ�!");
		break;
	case 3:
		printf("* ������ �������ϴ�!");
		break;
	case 4:
		printf("* �̲��� �Ѿ������ϴ�!");
		break;
	case 5:
		printf("* ������ ã�ҽ��ϴ�!");
		break;
	}
}

void logreset(void)
{
	for (int i = 0; i < 5; i++) {
		log[i] = 0;
	}
	gotoxy(0, -8);
	printf("                               ");
	gotoxy(0, -7);
	printf("                               ");
	gotoxy(0, -6);
	printf("                               ");
	gotoxy(0, -5);
	printf("                               ");
	gotoxy(0, -4);
	printf("                               ");
}

void logupdate(int n)
{
	for (int i = 3; i >= 0 ; i--) {
		log[i + 1] = log[i];
	}

	log[0] = n;

	gotoxy(0, -8);
	printf("                               ");
	gotoxy(0, -8);
	logprint(log[0]);

	gotoxy(0, -7);
	printf("                               ");
	gotoxy(0, -7);
	logprint(log[1]);

	gotoxy(0, -6);
	printf("                               ");
	gotoxy(0, -6);
	logprint(log[2]);

	gotoxy(0, -5);
	printf("                               ");
	gotoxy(0, -5);
	logprint(log[3]);

	gotoxy(0, -4);
	printf("                               ");
	gotoxy(0, -4);
	logprint(log[4]);
}
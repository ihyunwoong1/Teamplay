#include "common.h"

extern table[40][20];
extern int playerx;
extern int playery;
extern int dif;
extern int level;
extern int point;
extern int movement;
extern int health;

void place(int x, int y)
{
	gotoxy(x, y);
	printf("��");
}

void replace(int x, int y)
{
	gotoxy(x, y);
	printf("  ");
}

void setmovement(void)
{
	movement = MOVEMAX - ((level / 5) * dif * 5);
}

void tile(int position)
{
	switch (position) 
	{
	case 1:
		point += level * 100;
		logupdate(1);
		break;
	case 2:
		point += level * 10;
		logupdate(2);
		break;
	case 3:
		point -= level * 50;
		health -= 1;
		logupdate(3);
		break;
	case 4:
		point -= level * 5;
		health -= 1;
		logupdate(4);
		break;
	case 5:
		point += level * 5;
		if (health != 5) health += 1;
		logupdate(5);
		break;
	}
}

int input(void)
{
	int ch;
	int r = 0;

	ch = _getch();
	if (ch == 224) {
		ch = _getch();
		table[playerx][playery] = 0;
		switch (ch) {
		case 72:
			if (playery == 19)
				break;
			else {
				replace(playerx, playery);
				playery += 1;
				place(playerx, playery);
				movement--;
				break;
			}
		case 80:
			if (playery == 0)
				break;
			else {
				replace(playerx, playery);
				playery -= 1;
				place(playerx, playery);
				movement--;
				break;
			}
		case 75:
			if (playerx == 0)
				break;
			else {
				replace(playerx, playery);
				playerx -= 1;
				place(playerx, playery);
				movement--;
				break;
			}
		case 77:
			if (playerx == 39)
				break;
			else {
				replace(playerx, playery);
				playerx += 1;
				place(playerx, playery);
				movement--;
				break;
			}
		}
	}
	else if (ch == 27) {
		return pausemenu();
	}

	tile(table[playerx][playery]); //�̵��� ��ġ �̺�Ʈ ����

	if (table[playerx][playery] == 1) //��ǥ ����
		r = 5;

	table[playerx][playery] = -1;

	if (r == 0 && health <= 0)
		r = 1; //���ӿ���

	else if (r == 0 && movement <= 0)
		r = 1;

	return r;
}
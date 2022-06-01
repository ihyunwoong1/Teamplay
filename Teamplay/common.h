#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#define XAXIS 40
#define YAXIS 20
#define MOVEMAX 250

struct highsc {
	char name[4];
	int score;
};

void cursorview(void); //제출시 지우기

void difficulty(void);
int rand_x(void);
int rand_y(void);
int rand_t(void);
void run(void);
void title(void);
void tableset(void);
void tableprint(void);
void gotoxy(int, int);
int input(void);
void tile(int);
void stat(void);
void logupdate(int);
void logreset(void);
void emptyscreen(void);
void emptyinfo(void);
void screenchange(void);
void infoprint(void);
void levelshow(void);
int pausemenu(void);
int gameover(void);
void highscore(void);
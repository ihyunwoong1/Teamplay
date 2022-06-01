#include "common.h"

int table[40][20] = { 0 }; // 현재 위치 -1, 빈칸 0, 목표지점 1, 나머지 타일 2 ~ (rand_t)
int log[5] = { 0 }; //게임 로그
int dif = 1; //난이도
int playerx; //현재 플레이어 x축 좌표
int playery; //현재 플레이어 y축 좌표
int level; //현재 레벨
int point; //점수
int movement; //남은 이동 횟수
int health; //체력

void run(void)
{
	int r; //게임 진행/종료 판단하는 변수. 0 = 계속, 1 = 게임오버, 2 = 난이도선택으로, 3 = 타이틀로, 4 = 게임종료, 5 = 클리어

	cursorview(); //커서 안보이게 하는 함수, 제출시 지우기

	emptyscreen(); //비어있는 ui 출력 

	while (1) {
		title(); //타이틀 화면

		while (1) {
			screenchange(); //화면전환 
			difficulty(); //난이도 선택 
			emptyinfo(); //우측 정보란 지우는 
			level = 0;
			point = 0;

			while (1) {
				playerx = 0;
				playery = 0;
				health = 5;
				level += 1;
				tableset(); //깃발 위치 설정 

				screenchange();
				tableprint(); //게임 테이블 출력 
				infoprint(); //우측 정보 ui 출력 
				setmovement();  // 이동 횟수 설정 
				stat(); //우측 정보 수치 출력 

				levelshow(); //현재 레벨 보여주는 
				tableprint();

				do {
					r = input(); //입력받는 
					stat();
				} while (r == 0); //r = 0일때 계속하기

				if (r == 1)
					r = gameover(); //r = 1일때 게임오버

				if (r != 5) //r = 5일때 다음 레벨로
					break;
			}

			if (r == 3 || r == 4) //r = 2일때 난이도선택으로
				break;
		}
		if (r == 3) //r = 3일때 타이틀로
			screenchange();

		else if (r == 4) //r = 4일때 게임 종료
			break;
	}
}
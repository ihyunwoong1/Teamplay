#include "common.h"

int table[40][20] = { 0 }; // ���� ��ġ -1, ��ĭ 0, ��ǥ���� 1, ������ Ÿ�� 2 ~ (rand_t)
int log[5] = { 0 }; //���� �α�
int dif = 1; //���̵�
int playerx; //���� �÷��̾� x�� ��ǥ
int playery; //���� �÷��̾� y�� ��ǥ
int level; //���� ����
int point; //����
int movement; //���� �̵� Ƚ��
int health; //ü��

void run(void)
{
	int r; //���� ����/���� �Ǵ��ϴ� ����. 0 = ���, 1 = ���ӿ���, 2 = ���̵���������, 3 = Ÿ��Ʋ��, 4 = ��������, 5 = Ŭ����

	cursorview(); //Ŀ�� �Ⱥ��̰� �ϴ� �Լ�, ����� �����

	emptyscreen(); //����ִ� ui ��� 

	while (1) {
		title(); //Ÿ��Ʋ ȭ��

		while (1) {
			screenchange(); //ȭ����ȯ 
			difficulty(); //���̵� ���� 
			emptyinfo(); //���� ������ ����� 
			level = 0;
			point = 0;

			while (1) {
				playerx = 0;
				playery = 0;
				health = 5;
				level += 1;
				tableset(); //��� ��ġ ���� 

				screenchange();
				tableprint(); //���� ���̺� ��� 
				infoprint(); //���� ���� ui ��� 
				setmovement();  // �̵� Ƚ�� ���� 
				stat(); //���� ���� ��ġ ��� 

				levelshow(); //���� ���� �����ִ� 
				tableprint();

				do {
					r = input(); //�Է¹޴� 
					stat();
				} while (r == 0); //r = 0�϶� ����ϱ�

				if (r == 1)
					r = gameover(); //r = 1�϶� ���ӿ���

				if (r != 5) //r = 5�϶� ���� ������
					break;
			}

			if (r == 3 || r == 4) //r = 2�϶� ���̵���������
				break;
		}
		if (r == 3) //r = 3�϶� Ÿ��Ʋ��
			screenchange();

		else if (r == 4) //r = 4�϶� ���� ����
			break;
	}
}
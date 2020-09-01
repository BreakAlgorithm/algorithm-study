//���� 2503 ���ھ߱�
#pragma warning(disable:4996)
#include<stdio.h>
#include<iostream>
#include<vector>
#include <string>
#include <tuple>
#include<cstring>

using namespace std;

struct inputData
{
	int question;
	int strike;
	int ball;
};
int n;
inputData* arr = new inputData[n];
bool checkIn[987];

void input() {
	int tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].question);
		scanf("%d", &arr[i].strike);
		scanf("%d", &arr[i].ball);
	}
}

int main() {
	//chekIn-> 1�� �ʱ�ȭ
	memset(checkIn, 1, sizeof(checkIn));
	input();
	
	string check;
	string checkList;
	int checkStrike = 0;
	int checkBall=0;
	//n���� ���������Ͽ�
	//k[123~987] ������ ������ ���Ͽ� ���� ���غ��� ������ true���� �͸� ������ üũ
	for (int i = 0; i < n; i++) {
		for (int k = 123; k <= 987; k++) {
			//���� ������ ���ڿ� k ��° ������ ������ ��
			check=to_string(arr[i].question);
			checkList = to_string(k);

			//k��° ���ڿ� ���� strike�� boll�� Ȯ��
			for (int m = 0; m < 3; m++) {
				for (int a = 0; a < 3; a++) {
					if (check[m] == checkList[a]) {
						if (m == a) checkStrike++;
						if (m != a) checkBall++;
					}
				}
			}

			//srike�� boll�� ���� ���� ���ڴ� ����� ������ ���� (false)
			if (arr[i].strike != checkStrike || arr[i].ball != checkBall)
				checkIn[k] = 0;

			//������ k��° ���� üũ�ϱ����� �ٽ� 0���� �ʱ�ȭ �س��´�.
			checkStrike = 0;
			checkBall = 0;

		}
		//�� n��° ������ ���Ͽ� 123~987 ������ ���ڸ� ���غ� ���
	}
	//n�� ���� ��ο� ���Ͽ� ���ڸ� �����Ͽ� check(bool)�� ���¸� üũ�� ���


	//���� ���ڰ� �ѹ� �� ���ų� 0�� �� ���ڸ� ��� ���ܽ�Ŵ
	for (int i = 123; i < 987; i++)
	{
		string tmp = to_string(i);
		if (tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2]) 
			checkIn[i] = 0;
		if (tmp[0] - '0' == 0 || tmp[1] - '0' == 0 || tmp[2] - '0' == 0) 
			checkIn[i] = 0;
	}

	//true�� ����� ���� üũ
	int Answer = 0;
	for (int i = 123; i <= 987; i++)
	{
		if (checkIn[i] == 1) Answer++;
	}
	printf("%d", Answer);


	return 0;
}
#include<iostream>
#include<utility>
#include<vector>
#define MAX 101

using namespace std;


int dir = 4; // ����
int N; // ���� ũ��
int K; // ��� ����
int map[MAX][MAX] = { 0, }; //��ü ����
int L; // ���� ��ȯ Ƚ��

vector<pair<int, char>> pv;

void changeDir(int i) {
	switch (dir) {
	case 1:
		if (pv[i].second == 'L') dir = 3;
		else dir = 4;
		break;
	case 2:
		if (pv[i].second == 'L') dir = 4;
		else dir = 3;
		break;
	case 3:
		if (pv[i].second == 'L') dir = 2;
		else dir = 1;
		break;
	case 4:
		if (pv[i].second == 'L') dir = 1;
		else dir = 2;
		break;
	}
}

void move() {
	
	switch (dir) {
	case 1:
		--x;
		break;
	case 2:
		++x;
		break;
	case 3:
		--y;
		break;
	case 4:
		++y;
		break;
	}

}


int main() {
	bool finish = true;
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		//����� �ִ� ��ġ�� 1�� ����
	}
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int a; char b;
		cin >> a >> b;
		pv.push_back(make_pair(a, b));
	}

	int x = 0; //���� �ð�

	while (finish) {
		
		//���� �������� �̵� : ��/��/��/��
		//���� �ð��� �����̵��� Ȯ�� �� ����
		//1.�̵��� ĭ�� ���� ��´ٸ� ���� : ���� �ʸ� ����ϰ� �ݺ��� ����
		//2. �����̸� �÷� �Ӹ��� ����ĭ�� ��ġ��Ŵ
		//3. �̵��Ͽ��� ��� ��� ����Ȯ��
		//3-1. ����� ���� ��� ����� �������� ������ �������� ����
		//3-2. ����� ���� ��� �����̸� ���̰� ������ ��ġ�� ĭ�� ���

	}



	return 0;
}
#include<iostream>
#include<deque>
#define MAX 101

using namespace std;

class Point {
public:
	int x, y;
	Point() {
		x = y = -1;
	}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int dir = 4; // ����
int N; // ���� ũ��
int K; // ��� ����
int L; // ���� ��ȯ ����
int map[MAX][MAX] = { 0, }; //��ü ����
int ax, ay, cTime;
int answer; //���� �ð�
char cDir;
deque<Point> snake;
char change[10001];

void changeDir() {
	switch (dir) {
	case 1:
		if (change[answer] == 'L') dir = 3;
		else dir = 4;
		break;
	case 2:
		if (change[answer] == 'L') dir = 4;
		else dir = 3;
		break;
	case 3:
		if (change[answer] == 'L') dir = 2;
		else dir = 1;
		break;
	case 4:
		if (change[answer] == 'L') dir = 1;
		else dir = 2;
		break;
	}
}

Point move(Point now) {
	int x = now.x, y = now.y;
	switch (dir) {
	case 1:
		--x;//��
		break;
	case 2:
		++x;//��
		break;
	case 3:
		--y;//��
		break;
	case 4:
		++y;//��
		break;
	}
	return Point(x, y);
}

void go() {
	while (true) {
		//���� �ð� ���� üũ , ���� ��ȯ�� ���� ��� ���� ��ȯ�� ����
		if (change[answer] == 'L' || change[answer] == 'D') changeDir();
		//���� ��ġ�κ��� ���� �������� �̵�
		Point next = move(snake.front());

		int x = next.x;
		int y = next.y;  
		//��������

		//������ ������ ���� ��Ұų� �ڱ� �ڽ��� ���� ����� ��� ����
		if (x < 0 || x >= N || y < 0 || y >= N || map[x][y] == 2) break;

		//�Ӹ� �÷��ֱ�
		snake.push_front(Point(x, y)); 
		//����� ���� ���
		if (map[x][y] == 0) {
			map[snake.back().x][snake.back().y] = 0; //������ �����ֱ�
			snake.pop_back();
		}
		//���� ���� �ִ� ���� ��� 2�� ����
		map[x][y] = 2;
		++answer;
	}
	cout << answer + 1 << endl;
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> ax >> ay;
		map[ax - 1][ay - 1] = 1;
		//��� ��ġ 1�� ����
	}
	cin >> L;

	for (int i = 0; i < L; i++) {
		cin >> cTime;
		cin >> cDir;
		change[cTime] = cDir;
	}
	map[0][0] = 2;
	snake.push_back(Point(0, 0));
	go();
	return 0;
}

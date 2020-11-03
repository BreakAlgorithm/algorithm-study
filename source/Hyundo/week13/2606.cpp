#include<iostream>
#define MAX 101

using namespace std;

int N;
int M;
int map[MAX][MAX];
int mem[MAX];
int cnt = 0;


void DFS(int x)
{
	//�湮�� ��� 1�� �ʱ�ȭ
	mem[x] = 1;
	//���� index x�� node�� �ٸ� ��� ���� ���Ῡ�� Ȯ��
	//cnt �� �ٽ� �ѹ� �������� �ʵ��� �湮�� ���� ���� ��ġ�θ� �̵�
	for (int i = 1; i <= N; i++) {
		if (mem[i] == 0 && map[x][i] == 1) {
			cnt++;
			//���̷����� �ɸ� i ��ǻ�Ϳ��� �ٽ� ����
			DFS(i);
		}
	}
}



int main()
{
	cin >> N;
	cin >> M;
	for(int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}

	DFS(1);
	cout << cnt;

	return 0;
}
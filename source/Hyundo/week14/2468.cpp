#include<iostream>
#define MAX 1000

using namespace std;

int map[MAX][MAX];
int mem[MAX][MAX];
int N;

int a;

void DFS(int x, int y) {
	//�湮�� ���� 0���� �ʱ�ȭ
	mem[y][x] = 0;
	//������ ��� ��� �Լ� ����
	if (x < 0 || x >= N || y < 0 || y >= N)
		return;
	//�����¿� �̵��ϸ� DFS�� ����
	if (mem[y - 1][x] > a)
		DFS( x, y - 1);
	if (mem[y + 1][x] > a)
		DFS(x, y + 1);
	if (mem[y][x - 1] > a)
		DFS( x - 1, y);
	if (mem[y][x + 1] > a)
		DFS( x + 1, y);
	return;
}

int main()
{	
	int ans = 0;
	int max = 0;

	//input
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	//max �� ����
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] > max)
				max = map[i][j];
		}
	}

	//mem�� �ʱ�ȭ
	for (a = 1; a < max+1; a++) {

		int count = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				mem[i][j] = map[i][j];
		
		//count : ���� ���� ����
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (mem[i][j] > a) {
					count++;
					DFS(j, i);
				}
			}
		}

		//���� ������ �ִ밪�� ans�� ����
		if (count > ans)
			ans = count;
	}

	//���� : �ƹ� ������ ���� ����� ���� ���� �ִ�.
	//(���� = 0)�� ���� �ʾ��� ��쵵 ���� ��Ŵ
	if (ans == 0)
		cout << 1;
	else
		cout << ans;
	
	return 0;
}
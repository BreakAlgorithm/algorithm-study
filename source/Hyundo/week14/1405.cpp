#include<iostream>

#define MAX 29
using namespace std;

int N;
double percentage[4];
bool visited[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };


double DFS(int x, int y, int Cnt)
{
	//�ִ� �̵�Ƚ�� ���޽� 1 return;
	if (Cnt == N) return 1.0;

	//�湮�� ��ġ �ʱ�ȭ
	visited[x][y] = true;

	double Result = 0.0;

	//��ȭ�¿� �̵�
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		//�̵� ��ġ�� �̹� �湮 �� ���� ���� ��� skip (�̵� ��ΰ� �ܼ����� ����)
		if (visited[nx][ny] == true) continue;
		//ó�� �湮�ϴ� ��ġ�� ���
		//�̵��� ��ġ���� DFS ����
		//���� �̵��������� �̵��� Ȯ�� * ���� ��ġ������ �̵� Ȯ��
		Result = Result + percentage[i] * DFS(nx, ny, Cnt + 1);
	}

	visited[x][y] = false;
	return Result;
}


int main(void)
{
	cin >> N;
	for (int i = 0; i < 4; i++)
	{
		int a; 
		cin >> a;
		percentage[i] = a / 100.0;
	}
	double Answer = DFS(14, 14, 0);
	cout.precision(10);    // �Ҽ��� �Ʒ� 10�ڸ� ���� ����
	cout << fixed << Answer <<endl; // �Ҽ��� �Ʒ� ���� 10�ڸ� ���� ���

	return 0;
}
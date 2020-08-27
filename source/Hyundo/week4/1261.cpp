#include<iostream>
#include<string>
#include<queue>

#define endl "\n"
#define MAX 100
using namespace std;

int N, M;
int MAP[MAX][MAX];
int Dist[MAX][MAX];
bool Visit[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void Print()
{
	cout << "#############################" << endl;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << Dist[i][j] << " ";
		}
		cout << endl;
	}
	cout << "#############################" << endl;

}

void BFS(int a, int b)
{
	queue<pair<int, int>> Q;
	Q.push(make_pair(a, b));
	Dist[a][b] = 0; //ó�� (0,0)�� �湮Ƚ���� 0���� ����

	while (Q.empty() == 0)
	{
		//Print();
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();//�������� ������ ���� pop���־� ���̻� �Ʒ� if���� ������ �ش����� �ʾ� Q�� ���� ������ ���� ��� �ݺ��� ����

		for (int i = 0; i < 4; i++)
		{  //�� {+0,+1} �� {+0,-1} �� {+1,+0} �� {-1,+0} ������ üũ
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {


				if (MAP[nx][ny] == 1) //Ž���ϴ� ���� ���� ��
				{
					if (Dist[nx][ny] > Dist[x][y] + 1)
						//(������ ���� Ž���ϴ� ��(nx,ny)���� �̵��ϴµ� �μ� ���� ������ ���� Ž������ �μ����� �������� ���� ���)
						//������ Ž���� ���� ������ ������ Ŭ ���
						//or �湮�� ���� ���� ���(�ʱ� ���尪)
					{
						Dist[nx][ny] = Dist[x][y] + 1; //�̹��� Ž������ ���� ���� 1�� ���� �����Ͽ� �� ���� ���� ���� �μ� ��츦 �������ش�.
						Q.push(make_pair(nx, ny)); //������ ������ ��ġ�� Q�� push �Ѵ�.
					}
				}
				else if (MAP[nx][ny] == 0) //Ž���ϴ� ���� ���� �ƴ� ��
				{
					if (Dist[nx][ny] > Dist[x][y]) //������ Ž���� ���� ������ ������ Ŭ ��� or �湮�� ���� ���� ���(�ʱ� ���尪)
					{
						Dist[nx][ny] = Dist[x][y]; //�湮�� ���� ������ ���� �־��ְ�
						Q.push(make_pair(nx, ny)); //������ ������ ��ġ�� Q�� push �Ѵ�.
					}
				}
			}
		}
	}
}

int main(void)
{

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		string Inp;
		cin >> Inp;
		for (int j = 0; j < Inp.length(); j++)
		{
			MAP[i][j] = Inp[j] - '0';
			Dist[i][j] = 9998; //100,100���� �̷���� �̷ο� �ִ� ���� �� �ִ� ���� ����
		}
	}
	BFS(0, 0);
	cout << Dist[M - 1][N - 1] << endl;
	//BFS Ž���� ��� ������ �μ����� ������ ����� Dist�� m.n�� ����� ���� ���

	return 0;
}
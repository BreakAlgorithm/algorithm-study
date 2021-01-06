#include<iostream>
#include<queue>

using namespace std;

int cave[126][126];
int dist[126][126];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void sol(int N,int TC)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			cin >> cave[i][j];
			dist[i][j] = 999999999;
		}
	}

	priority_queue<pair<int, pair<int, int>>> PQ;
	//PQ = (cost (x,y)) 
	PQ.push(make_pair(cave[0][0], make_pair(0, 0)));
	dist[0][0] = cave[0][0];

	while (PQ.empty() == 0)
	{
		int Cost = PQ.top().first;
		int x = PQ.top().second.first;
		int y = PQ.top().second.second;
		PQ.pop();
		//�Ʒ� ���ǿ��� cost�� �� ���� ��尡 �߰ߵ��� �������
		//pop�� ��� �����ϰ� �Ǹ�
		//PQ�� ���̻� ���� ���� ��� �ݺ��� ����
		
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < N) //�̵� ���� ����
			{
				int nCost = Cost + cave[nx][ny];
				//������ġ�κ��� �����¿� �̵� �ÿ� cost�� �� ���� ��尡 �߰ߵ��� ���� ���
				//push�� ���̻� ������� ����
				if (dist[nx][ny] > nCost)
				{
					//cost�� �� ���� ��尡 �߰ߵ� ��� �� ���� cost�� ���� �ʱ�ȭ
					dist[nx][ny] = nCost;
					PQ.push(make_pair(dist[nx][ny], make_pair(nx, ny)));
					
				}
			}
		}
	}

	cout << "Problem " << TC << ": " << dist[N-1][N-1] << endl;
}


int main()
{
	int tmpN = 0;
	int i = 0;
	while (1)
	{
		i++;
		cin >> tmpN;
		if (tmpN == 0)
			break;
		else
			sol(tmpN,i);
	}



	return 0;
}
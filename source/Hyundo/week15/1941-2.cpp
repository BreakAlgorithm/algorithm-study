#include<iostream>
#include<cstring>
#include<string>
#include<queue>

#define endl "\n"
using namespace std;

int MAP[5][5], Answer;
bool Select[25];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1 ,0, 0 };

void Input()
{
	for (int i = 0; i < 5; i++)
	{
		string Inp;
		cin >> Inp;
		for (int j = 0; j < Inp.length(); j++)
		{
			if (Inp[j] == 'Y') MAP[i][j] = 1;
			else if (Inp[j] == 'S') MAP[i][j] = 2;
		}
	}
}

bool MoreThanFour()
{
	int Cnt = 0;
	for (int i = 0; i < 25; i++)
	{
		if (Select[i] == true)
		{
			//idx�� ���Ͽ� x��ǥ�� y��ǥ�� ���
			int x = i / 5;
			int y = i % 5;
			//����� ��ǥ�� �ش��ϴ� ���� 2(S)���� Ȯ��
			if (MAP[x][y] == 2) Cnt++;
		}
	}
	//�� S�� ������ ���� ���
	if (Cnt >= 4) return true;
	else return false;
}

bool Adjacency()
{
	queue <pair<int, int>> Q; ////���� ���� ������ �л��� ��ǥ�� Queue�� ����(������)
	bool Check_Select[5][5]; //������ �л����� �����ϴ� �迭
	bool Queue_Select[5][5]; 
	bool Check_Answer = false;

	memset(Queue_Select, false, sizeof(Queue_Select));
	memset(Check_Select, false, sizeof(Check_Select));

	int Tmp = 0;
	for (int i = 0; i < 25; i++)
	{
		//���� DFS�� ���� ���õǾ� �ִ� �л���
		if (Select[i] == true)
		{
			//�ش� ��ǥ�� ���
			int x = i / 5;
			int y = i % 5;
			//���� ���õǾ� �ִ� �л����� 2���� �迭�� ǥ��
			Check_Select[x][y] = true;
			//ù �������� �����ϱ� ���� tmp�� 0, �� ù ������ ��쿡�� Q �� ����
			if (Tmp == 0)
			{
				Q.push(make_pair(x, y));
				Queue_Select[x][y] = true;
				//Tmp�� ������Ŵ���� ���� ���Ŀ��� �̺κ��� ������� �ʴ´�.
				Tmp++;
			}
		}
	}

	int Cnt = 1;
	//Q�� ���� ���� �������� �ݺ���(BFS)
	while (Q.empty() == 0)
	{
		//x,y�� ù �������� ����
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		//�Ʒ� for������ Q�� ���̻� push���� �ʴ� ���� ������ ���� �ʱ� ������
		//Q�� ���̻� push���� �ʰ� �ǰ� while���� ���ǿ� �ش����� �ʾ�
		//g���� �ݺ����� �����ԉ�

		//������ �ִ� �л��� 7���� �Ǿ��� ��쿡 true�� return�ϵ��� check_answer�� ����
		if (Cnt == 7)
		{
			Check_Answer = true;
			break;
		}

		//�¿���� �̵��� ����
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5)
			{
				//DFS�� ���� ������ �л� 7�� �ش��ϰ� ���� BFS�� ���� Ž���� ���� ���� ��� ���ǿ� �ش���
				if (Check_Select[nx][ny] == true && Queue_Select[nx][ny] == false)
				{
					//�湮 ǥ�� ����
					Queue_Select[nx][ny] = true;
					Q.push(make_pair(nx, ny));
					//BFS�� ���� �湮�� ������ ��쿡�� ������ �ִ� ���̹Ƿ� cnt�� �÷��ش�.
					Cnt++;
				}
			}
		}
	}

	if (Check_Answer == true) return true;
	return false;
}

void DFS(int Idx, int Cnt)
{
	//�� ���� �������� bfs�� dfs�δ� ���ڰ� ����� ã�� �� ���� ������
	//25���� �л� �߿��� 7���� �̰� �̰��� S�� 4 �̻� ���ԵǾ������� ��� ����Ǿ��ִ����� �Ǵ��Ͽ� ������ ����
	//7���� ��� ���� ���
	if (Cnt == 7)
	{
		//�̴ټ��İ� 4���̻��� ���
		if (MoreThanFour() == true)
		{
			//���� ���°� ��� �����Ͽ� �ִ� ��� ����� �� �߰�
			if (Adjacency() == true) Answer++;
		}
		return;
	}

	for (int i = Idx; i < 25; i++)
	{	
		//�̹� �̵��� ���� �ִ� ��� continue;
		if (Select[i] == true) continue;
		//�̵� ǥ��
		Select[i] = true;
		//���� ��ġ�� �̵�
		DFS(i, Cnt + 1);
		//backtraking
		Select[i] = false;
	}
}

void Solution()
{
	DFS(0, 0);
	cout << Answer << endl;
}

void Solve()
{
	Input();
	Solution();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();

	return 0;
}

#include<iostream>
#include<queue>

#define endl "\n"
#define MAX 20
using namespace std;

int R, C, Answer;
char MAP[MAX][MAX];
bool Visit[26];

int dx[] = { 0, 0, 1, -1 }; // ��, ��
int dy[] = { 1, -1, 0, 0 }; // ��, ��

int Bigger(int A, int B) { if (A > B) return A; return B; }


void DFS(int x, int y, int Cnt)
{
	Answer = Bigger(Answer, Cnt); //�ִ��� ������ �� �ִ� ĭ�� ���� ����� ����

	for (int i = 0; i < 4; i++) //�����¿�� �̵��Ͽ� üũ
	{ //�� {+0,+1} �� {+0,-1} �� {+1,+0} �� {-1,+0} ������ üũ
		int nx = x + dx[i]; 
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < R && ny < C) //�ִ�, �ּ� ������ ����� �ʾ��� ��
		{
			if (Visit[MAP[nx][ny] - 'A'] == false) //�ش� ���ĺ��� ������ ���� ���
			{
				Visit[MAP[nx][ny] - 'A'] = true; //�װ����� �̵��ϰ�
				DFS(nx, ny, Cnt + 1); //count�� �߰��� �Ŀ� �ش� ��ġ���� �ٽ� DFS�� �����Ͽ� üũ
				Visit[MAP[nx][ny] - 'A'] = false; //üũ�� �Ŀ� �� �ٸ� ������ Ȯ���ϱ� ���� false üũ
			}
		}
	}
}

int main(void)
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> MAP[i][j];
		}
	}

	Visit[MAP[0][0] - 'A'] = true; //ó�� �����ϴ� (0,0) �� �̹� ����ģ ������ üũ
	DFS(0, 0, 1);  // x,y=(0,0) , count�� 1���� DFS ����
	cout << Answer << endl;

	return 0;
}

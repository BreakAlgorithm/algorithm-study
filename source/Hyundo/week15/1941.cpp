#include<iostream>

using namespace std;

int arr[5][5] = { 0, };
int mem[5][5] = { 0, };

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
//(0,1)�� (1,0)�� (0,-1)�� (-1,0)��
int cnt=0;
int Scnt = 0;


void dfx(int x, int y,int depth)
{
	if (arr[x][y] == 2)
		Scnt++;

	mem[x][y] = 1;


	cout << "x,y,depth" << x << y << depth << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
		{
			cout << mem[i][j];
		}
		cout << endl;
	}

	if (depth > 7) {
		mem[x][y] = 0;
		if (Scnt >= 4) {
			cnt++;
		}
		return;
	}

	else
	{
		int nx = 0;
		int ny = 0;
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if (mem[nx][ny] != 1 && (nx < 5 || nx >= 0 || ny < 5 || ny >= 0))
			{
				dfx(nx, ny, depth + 1);
			}
		}
		mem[x][y] = 0;
		if (arr[x][y] == 2)
			Scnt--;
	}
}


int main() {
	for (int i = 0; i < 5; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < 5; j++) {
			if (tmp[j] == 'Y')
				arr[i][j] = 1;
			else
				arr[i][j] = 2;
		}
	}
	//������ ��ġ�� ���Ͽ� ����
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
		{
			dfx(i, j, 1);
		}
	}


	cout << cnt;


	return 0;
}
#include<iostream>

#define MAX 101
//ù��° �õ� : 100 �̶� �����Ͽ��ٰ� ��������
//-> 101 �� ����

using namespace std;

char map[MAX][MAX];   //RGB�� ��� �νİ����� �Ϲ����� ���� map
char CBmap[MAX][MAX]; //color blindness�� ���� map
int N;

//�Ϲ��ε��� ���� DFS
void sol(char color,int x, int y) {
	//1.���� x,y �� ������ ����� ��� return
	map[y][x] = 'x';
	if (x < 0 || x >= N || y < 0 || y >= N)
		return;
	//2,���� ��ġ���� ã�� ����� ������ ��� �̵�
	if (map[y - 1][x] == color)
		sol(color, x, y - 1);
	if (map[y + 1][x] == color)
		sol(color, x, y + 1);
	if (map[y][x - 1] == color)
		sol(color, x - 1, y);
	if (map[y][x + 1] == color)
		sol(color, x + 1, y);

}

//���ϻ����� ���� DFS
void CBsol(char color, int x, int y) {
	//1.���� x,y �� ������ ����� ��� return
	CBmap[y][x] = 'x';
	if (x < 0 || x >= N || y < 0 || y >= N)
		return;
	//2,���� ��ġ���� ã�� ����� ������ ��� �̵�
	if (CBmap[y - 1][x] == color)
		CBsol(color, x, y - 1);
	if (CBmap[y + 1][x] == color)
		CBsol(color, x, y + 1);
	if (CBmap[y][x - 1] == color)
		CBsol(color, x - 1, y);
	if (CBmap[y][x + 1] == color)
		CBsol(color, x + 1, y);
}

int main()
{
	int ans1=0; //�Ϲ����� ���� �� ����
	int ans2=0; //���ϻ����ε��� ���� �� ����

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < N; j++) {
			map[i][j] = tmp[j];
			//���ϻ����� map���� G��� R�� ����Ͽ� G�� R�� �� �������� ��ġ
			if(tmp[j]=='G')
				CBmap[i][j] = 'R';
			else
				CBmap[i][j] = tmp[j];
		}
	}

	//map �� CBmap�� ��� ��ġ�� check�ϸ鼭 
	//����Լ� sol�� �������� ���� ��ġ���� DFS�� �����Ͽ�
	//DFS�� ���Ӱ� ���� ��ġ���� count�� �߰��Ͽ� ������ ������ ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 'x') {
				ans1++;
				sol(map[i][j], j, i);
			}
			if(CBmap[i][j] != 'x') {
				ans2++;
				CBsol(CBmap[i][j], j, i);
			}
		}
	}

	cout << ans1<<" "<<ans2<<endl;
	return 0;
}
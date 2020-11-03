#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 26


using namespace std;
int N;
int map[MAX][MAX];
int mem[MAX][MAX];
vector<int> Vcnt;


void DFS(int count,int x, int y) {
	//�湮�� ��ġ �ʱ�ȭ
	//mem �� �湮 ���� ���
	//map �� ������ȣ ���
	mem[y][x] = 0;
	map[y][x] = count;
	//���� ��� ��� return
	if (x < 0 || x >= N || y < 0 || y >= N)
		return;
	//�����¿�
	if (mem[y - 1][x] == 1)
		DFS(count, x, y - 1);
	if (mem[y + 1][x] == 1)
		DFS(count, x, y + 1);
	if (mem[y][x - 1] == 1)
		DFS(count, x - 1, y);
	if (mem[y][x + 1] == 1)
		DFS(count, x + 1, y);
}

int main()
{
	int count = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		//string���� �Է� ���� �� map �� mem�� ��� int �� ����
		for (int j = 0; j < N; j++) {
			map[i][j] = tmp[j] - 48;
			mem[i][j] = tmp[j] - 48;
		}
	}

	//�迭�� ��� ��ġ�� check�ϸ鼭 ������ DFS�� �������� ����(mem[i][j] !=0)
	//��ġ�� �������� ��� ���� ������ �߰��ϰ� ���� �߰ߵ� ���� ������ȣ�� �ο�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mem[i][j] != 0) {
				count++;
				Vcnt.push_back(0);
				DFS(count, j, i);
			}
		}
	}
	//out of bound ����
	Vcnt.push_back(0);
	//�� ������ ���
	cout << Vcnt.size()-1 << endl;

	//map �� üũ�Ͽ� �� ������ ������ Vcnt�� ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Vcnt[map[i][j]]++;
		}
	}
	//������������ ������ ���� ���� ����ϱ� ���� sort
	sort(Vcnt.begin()+1, Vcnt.end());
	//�� ������ ���� �� ���
	for (int i = 1; i < Vcnt.size(); i++)
		cout << Vcnt[i] << endl;

	return 0;
}
#include<iostream>
#include<cstdlib>
#define MAX 16

using namespace std;


int map[MAX] = { 0, };
int N;
int cnt=0;


bool condition(int x)
{
	for (int i = 0; i < x; i++)
	{
		//���� : ���� y�༱�� ������ �ȉ� + �밢���� ������ �ȉ�
		if (map[x] == map[i] || abs(x - i) == abs(map[x] - map[i]))
			return false;
	}

	return true;
}

void dfs(int x) {

	//�־��� ������ ��� ä�� ��� return 1;
	if (x == N-1) {
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++) {
		//���ǿ� ������ ���� ������ ����
		map[x] = i;
		if (condition(x)) {
			dfs(x + 1);
		}
		//���ǿ� ���� ������ �ߴ�
		else
			return;
	}
}


int main()
{
	cin>>N;

	dfs(0);

	cout << cnt << endl;

	return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;
int N;

int ans[101];
int fin[101];
int map[101];//��° �ٿ� �̷�� ������ ����
int visited[101]; //�湮 üũ
int cnt = 0;

void dfs(int n)
{
	int i;
	//�湮 ���� ǥ��
	visited[n] = 1;
	//���� n ��ġ�� ��° �ٿ� �̷�� ������ ���Ͽ� �湮 ���� üũ
	//�湮�� ���� ���ٸ�  dfs�� ���� �� °���� ������ ���� dfs ����
	if (visited[map[n]] == 0)
		dfs(map[n]);
	//sycle�� ���ƿ� ��� ans�� ������ �߰����ش�.
	else if (fin[map[n]] == 0){
		ans[cnt++] = n;
		//���� ���ڿ� ��° ���� ���ڸ� ��� ���信 �߰��Ѵ�.
		for (i = map[n]; i != n; i = map[i])
			ans[cnt++] = i;
	}
	//���Ŀ� sycle�� ���ԵǴ��� ans�� �߰����� �ʵ��� �ش� ������ fin�� 1�� �ʱ�ȭ�Ѵ�.
	//Ȥ�� �� ���ǿ� ��� �ش����� �ʴ� ��쿡�� sycle�� ���Ե��� �������� fin�� 1�� �ʱ�ȭ�Ѵ�.
	fin[n] = 1;
}

int main()
{
	int i, j;
	cin >> N;
	for (i = 1; i <= N; i++)
		cin >> map[i];
	
	for (i = 1; i <= N; i++){
		//�̹� �湮�� ��� dfs���� x
		if (visited[i]) continue;
		dfs(i);
	}
	//ū ���� ������ ����ϱ� ���� sort
	sort(ans, ans + cnt);
	cout << cnt << "\n";
	for (i = 0; i < cnt; i++)
		cout << ans[i] << "\n";

	return 0;
}
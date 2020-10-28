#include<iostream>
#include<algorithm>
#define MAX 10001

using namespace std;

int n;
int wine[MAX];
int dp[2][MAX] = { 0 };

int sol(int x, int y)
{
	if (dp[x][y] != 0)
		return dp[x][y];

	//������ ����̰ų� ������ ���� ����ε� �̹� 2������ ���� ���
	if (y == n - 1||(y==n-2 && x==1)) {
		dp[x][y] = wine[y];
		return dp[x][y];
	}

	//�������� ���� ��쿡 ���� �з�
	int sum1 = 0, sum2 = 0;
	if (x == 0) {
		if (y + 1 < n)
		sum1 = sol(1,y + 1);
		if(y+2<n)
		sum2 = sol(0,y + 2);
	}
	else if (x == 1) {
		if (y + 2 < n)
		sum1 = sol(0,y + 2);
		if (y + 3 < n)
		sum2 = sol(0,y + 3);
	}

	dp[x][y] = wine[y] + max(sum1, sum2);
	return dp[x][y];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> wine[i];
	sol(0, 0);

	cout << dp[0][0] << endl;

	return 0;
}
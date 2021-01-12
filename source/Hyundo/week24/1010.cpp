#include <iostream>
using namespace std;

int T, N, M;
int mem[33][33] = { 0 };

int dp(int n, int m) {
	//n�� 0�� ��, n=m�� �� 1 ��ȯ, ����
	if (n == 0 || n == m)
		return 1;
	//�̹� ����� �Ϸ�� ���
	else if (mem[n][m] != 0) {
		return mem[n][m];
	}
	//��ȭ�� dp[n][m] = dp[n-1][m-1] + dp[n][m-1]
	else {
		mem[n][m] = dp(n - 1, m - 1) + dp(n, m - 1);
		return mem[n][m];
	}
}

int main() {

	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N >> M;
		cout<<dp(N, M)<<endl;
	}
	return 0;
}
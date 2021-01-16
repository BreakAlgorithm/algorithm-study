#include <iostream>

using namespace std;

int n, k;
int coins[101];
int mem[10001] = { 0 };
//mem[i] = ���� i ���� �ǵ��� �ϴ� ����� ��

void sol() {
	mem[0] = 1;
	//mem[i] �� i�� 0�� �� ��� = ���� i���� �ǵ��� ���� �� �ִ� -> 1
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= coins[i]) {
				//mem[j] : ���� j���� �ǵ��� �ϴ� ����� ��
				//mem[j-coin[i]] : ���� j-coin[i] ���� �ǵ����ϴ� ����� ��
				//mem[j]=mem[j] + mem[j-coin[i]] : 
				//coin[i] �� ���� ���� j-coin[i]���� �Ǵ� ����� ����ŭ j���� �ǵ��� ���� �� �ִ�.
				mem[j] += mem[j - coins[i]];
			}
		}
	}
	cout << mem[k];
}

int main() {
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> coins[i];
	}

	sol();
	return 0;
}
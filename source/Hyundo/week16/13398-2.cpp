#include<iostream>
#include<algorithm>

#define MAX 100001

using namespace std;

int arr[MAX];
int sum[MAX][2];
//sum[i] = arr[1]~arr[i]������ ������

int main() {
	ios_base::sync_with_stdio(false);
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int result = arr[0];

	for (int i = 0; i < N; i++) {
		sum[i][0] = arr[i];
		sum[i][1] = arr[i];
		if (i != 0) {
			//1.���� �ε����� ���� �������� ���� ���
			//(i-1��°���� ������ + arr[i]) VS arr[i]
			sum[i][0] = max(sum[i - 1][0] + arr[i], arr[i]);
			//2.���� �ε����� ���� �������� ���
			//(i-1��°���� ������) VS (i-1)��°���� ������ ������� �� ������ +a[i])
			sum[i][1] = max(sum[i - 1][0], sum[i - 1][1] + arr[i]);

			//������� �ִ밪 result VS 1��(���� x) VS 2��(���� o)
			result = max(result, max(sum[i][0], sum[i][1]));
		}
	}
	cout << result << '\n';
	return 0;
}
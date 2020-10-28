#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001

using namespace std;

long N;
long K;
long res;

long Search(long left, long right) {
	
	int cnt = 0;
	long mid = (left + right) / 2;
	//����
	if (left > right)
		return res;
	//���Ϸ��� ���� res�� ��
	//res�� 1����� N����� i��° �࿡�� min(res/i,N)�� ���� ��
	for (int i = 1; i <= N; i++) {
		cnt += min(mid / i, N);
	}

	//���� ���� K���� ���� ��� res�� �� ���� �������� ã��
	if (K <= cnt) {
		res = mid;
		return Search(left, mid - 1);
	}
	//���� ���� K���� ū ���  res�� �� ū �������� ã��
	else {
		return Search(mid + 1, right);
	}
}


int main()
{
	cin >> N >> K;
	int tmp;
	long left = 1;
	long right = K;

	cout << Search(left, right);





	return 0;
}
#include<iostream>

using namespace std;

int T[16];
int P[16];
int mem[16] = {-1};
int N;


int sol(int date) {

	int tmpMax = P[date];
	//���� ��¥�� ���� ����� �̹� ����� ���
	if (mem[date] != -1) {
		return mem[date];
	}
	//���糯¥�� ����� ������ ���� ���� ���
	else if (date + T[date] > N+1) {
		mem[date] = 0;
		return 0;
	}
	//���� ��¥�� �ִ� ��� 
	else {
		for (int i = date + T[date]; i < N+1; i++) {
			int tmpRes = P[date] + sol(i);
			if (tmpRes > tmpMax)
				tmpMax = tmpRes;
		}
		mem[date] = tmpMax;
		return mem[date];
	}
}

int main()
{
	int max = 0;
	std::fill_n(mem, 16, -1);
	int answer = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> P[i];
	}

	for (int i = N; i > 0; i--) {
		int tmp = sol(i);
		if (max < tmp) {
			max = tmp;
		}
	}
	cout << max;

}
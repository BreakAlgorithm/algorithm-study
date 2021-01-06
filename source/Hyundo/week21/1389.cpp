//�ɺ� �������� 6�ܰ� ��Ģ
//
#include<iostream>
#include<algorithm>

#define MAX 101

using namespace std;

int map[MAX][MAX];

int main() {

	//input
	int N,M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {  
		for (int j = 0; j < N; j++) {
			map[i][j] = N+1;
		}
	}

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		//ģ�� �����̹Ƿ� ��������� ǥ��
		map[from-1][to-1] = 1;
		map[to-1][from-1] = 1;
	}

	//Floyd-Warshall
	for (int i = 0; i < N; i++) {  //i ��° ������ ������ ��
		for (int j = 0; j < N; j++) {   //j �������� ����
			for (int k = 0; k < N; k++) {    // k �������� �̵�
				if (j != k && map[j][i] != 0 && map[i][k] != 0)
				{
					//�ּ� �ɺ� �������� ���� ǥ ������ ����
					map[j][k] = min(map[j][k],map[j][i] + map[i][k]);
				}
			}
		}
	}

	int max = N*N;
	int answer = 0;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++)
			if (i != j)
				sum += map[i][j];
		//���� �� �ɺ� ������ ���� ���� ���� ���� ��ȣ�� answer�� ����
		if (sum < max) {
			max = sum;
			answer = i+1;
		}
	}

	cout << answer<<endl;
}
#include<iostream>
#include<algorithm>

#define MAX 501

using namespace std;

int map[MAX][MAX];

int main() {

	//input
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map[i][j] = N+1;
	

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		map[from - 1][to - 1] = 1;
	}

	//Floyd-Warshall
	for (int i = 0; i < N; i++) {  //i ��° ������ ������ ��
		for (int j = 0; j < N; j++) {   //j �������� ����
			for (int k = 0; k < N; k++) {    // k �������� �̵�
				if (j != k && map[j][i] != 0 && map[i][k] != 0)
				{
					map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
				map[j][i] = map[i][j];


	int answer = 0;
	
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			if(map[i][j]!=N+1)
			sum += 1;
		}
		if (sum == N - 1)
			answer++;
	}

	cout << answer;
}
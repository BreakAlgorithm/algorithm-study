#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321
#define MAX 101

using namespace std;

int n, m;
int arr[MAX][MAX];


int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {        // vectex table �ʱ�ȭ
		for (int j = 0; j < n; j++) {
			arr[i][j] = INF;
		}
	}

	int from, to, weight;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> weight;
		//���� ���ÿ� ���� ���ø� �����ϴ� �뼱 �� ����ġ�� �ּҰ��� ���� ����
		arr[from-1][to-1] = min(arr[from-1][to-1], weight);
	}

	for (int i = 0; i < n; i++) {  //i ��° ������ ������ ��
		for (int j = 0; j < n; j++) {   //j �������� ����
			for (int k = 0; k < n; k++) {    // k �������� �̵�
				if (j != k && arr[j][i] != INF && arr[i][k] != INF) {
					//�ּҺ������ ����
					arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
				}
			}
		}
	}

	//������ ����� ��� ���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j]== INF)
				cout << 0 << " ";
			else
				cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
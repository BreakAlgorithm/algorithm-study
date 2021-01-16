#include<iostream>
#define MAX 101

using namespace std;

bool map[MAX][MAX];

int main() {

	//input
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) 
			cin >> map[i][j];
	

	//Floyd-Warshall
	for (int i = 0; i < N; i++) {  //i ��° ������ ������ ��
		for (int j = 0; j < N; j++) {   //j �������� ����
			for (int k = 0; k < N; k++) {    // k �������� �̵�
				if (map[j][i] != 0 && map[i][k] != 0)//j->i ���� ���� Ȯ�� && i->k ���� ���� Ȯ��
				{
					map[j][k] = 1;
					//j->i->k 
					//i ������ �����Ͽ� j �������κ��� k�������� ��ΰ� ����
				}
			}
		}
	}

	//output
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << map[i][j]<<" ";
		cout << endl;
	}

}
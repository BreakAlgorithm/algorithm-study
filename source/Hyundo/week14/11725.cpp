#include <iostream>
#include <vector>
using namespace std;

#define MAX 100001

int N;
vector<int> vertex[MAX];
int answer[MAX];
bool visited[MAX];


void DFS(int x) {
	//�湮�� ��� true �� ����
	visited[x] = true;
	//���� �湮�� ����� �������� ��� �ݺ����� ���� Ž��
	for (int i = 0; i < vertex[x].size(); i++) {
		int next = vertex[x][i];
		//�湮�� ���� ���� node�� �θ� ��带 ���� x�� �����ϰ�
		//�湮�ϱ� ���� ��� ����
		if (visited[next] == false) {
			answer[next] = x;
			DFS(next);
		}
	}
}

int main() {
	cin >> N;
	int a, b;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		vertex[a].push_back(b);
		vertex[b].push_back(a);
	}

	//��Ʈ(1) ���� ����
	DFS(1);

	for (int i = 2; i <= N; i++)
		cout << answer[i] << '\n';

	return 0;
}
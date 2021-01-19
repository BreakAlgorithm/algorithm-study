#include<iostream>
#define MAX 202

using namespace std;

int N, M;
int root[MAX];

void init() {
	for (int i = 1; i <= N; i++)
		root[i] = i;

}

int find(int i) {
	if (root[i] == i)
		return i;
	else
		return root[i] = find(root[i]);

}

void merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x == y)
		return;
	else
		root[x] = y;
}

int main() {
	cin >> N >> M;
	init();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp;
			cin >> tmp;
			if (tmp == 1)
				merge(i, j);
		}
	}

	//���� �Է°����� �񱳸� ���� �ʱⰪ ����
	int tmpRoot;
	cin >> tmpRoot;
	int connect=find(tmpRoot);
	bool check = true;

	//�Է°��� ���Ͽ� root�� �񱳸� ���� ���� Ʈ�� ���� �������� �ʴ� ��� ���� �Ұ� -> check = false
	for (int i = 2; i <= M; i++) {
		int tmp;
		cin >> tmp;
		if (find(tmp) != connect) {
			check = false;
		}
	}

	if (check == false)
		cout << "NO";
	else cout << "YES";
}
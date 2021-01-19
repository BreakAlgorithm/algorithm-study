#include<iostream>
#define MAX 10002

using namespace std;

int N, M, k;

int price[MAX]; //������ �л��� ���ϴ� ģ����
int root[MAX];  


//1��ģ������ N��ģ������ �ڱ��ڽ��� root�� �ʱ�ȭ
void init() {
	for (int i = 1; i <= N; i++)
		root[i] = i;
}

//Union-Find �Լ��� find 
int find(int i) {
	if (root[i] == i)
		return i;
	else
		return root[i] = find(root[i]); //��� ����
}

//Union-Find �Լ��� Union (rank ��� price�� ��(�ּҺ������ ����))
void merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x == y)
		return;
	//�� Ʈ���� ��Ʈ�� ���Ͽ� ģ����(price)�� ��
	if (price[x] > price[y])
		root[x] = y;
	else
		root[y] = x;
}


int main() {

	cin >> N >> M >> k;

	init();

	for (int i = 1; i <= N; i++)
		cin >> price[i];
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
		if (root[i] == i)
			answer += price[i];

	if (answer > k)
		cout << "Oh no";
	else
		cout << answer;

	return 0;
}
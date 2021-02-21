#include<iostream>
#include<algorithm>

#define MAX 1000001
#define INF 1000000001

using namespace std;

int N, M;
long long arr[MAX];  //�־��� �迭
long long tree[MAX * 4]; //�־��� �迭�� ���� ������� ���׸�Ʈ Ʈ���� �����ϴ� �迭


long long init(int left, int right, int node) {
	//���� ��� ���� �� arr �迭�� ������ tree�� �ʱ�ȭ
	if (left == right) return tree[node] = arr[left];
	//������� �� �����ϰ�� �ڽ� ��� �� �ּڰ����� tree�� �ʱ�ȭ
	int mid = (left + right) / 2;
	return tree[node] = min(init(left, mid, node * 2), init(mid + 1, right, node * 2 + 1));
}

long long getMin(int node, int left, int right, int start, int end) {
	//������ ����� ��� �ִ������� return�Ͽ� min �Լ� ��󿡼� ����
	if (right < start || left > end) return INF;
	//ã�� ���� ���� ���� ��尡 ���ԵǴ� ��� ����� ���� ��ȯ
	if (start >= left && end <= right) return tree[node];

	//���� Ʈ���������� �ּڰ��� �ּڰ��� ��ȯ
	int mid = (start + end) / 2;
	return min(getMin(node * 2, left, right, start, mid), getMin(node * 2 + 1, left, right, mid + 1, end));
}


int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	init(0, N - 1, 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << getMin(1, a - 1, b - 1, 0, N - 1) << "\n";
	}

}
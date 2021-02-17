#include<iostream>
#include<math.h>
#define MAX 1000010
#define MODULER 1000000007

using namespace std;

long long arr[MAX];  //�־��� �迭
long long tree[MAX * 4]; //�־��� �迭�� ���� ������� ���׸�Ʈ Ʈ���� �����ϴ� �迭

long long init(int node, int start, int end) {
	//�������
	if (start == end) return tree[node] = arr[start] % MODULER;
	int mid = (start + end) / 2;
	return tree[node] = (init(node * 2, start, mid) * init(node * 2 + 1, mid + 1, end)) % MODULER;
}

//[start,end] : ���� node�� ����ϰ� �ִ� ����
//[left,right] : ���� ���ؾ� �ϴ� ����
long long sum(int left, int right, int node, int start, int end) {

	if (left > end || right < start) return 1;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return (sum(left, right, node * 2, start, mid) * sum(left, right, node * 2 + 1, mid + 1, end))%MODULER;
}

long long update(int node, int start, int end, int index, long long num) {
	//���� ���� ���Ե��� �ʴ� ��� : update�������� ��ȯ
	if (index < start || index > end) return tree[node];
	//���� ��忡 ������ ��� : update���� ����
	if (start == end) return tree[node] = num;
	//�ٸ� ��� : ���� Ʈ������ index�� �ش��ϴ� update���� �� �� ����� tree�� �ٽ� �ʱ�ȭ
	int mid = (start + end) / 2;
	return tree[node]=(update(node * 2, start, mid, index, num) * update(node * 2 + 1, mid + 1, end, index, num))%MODULER;
	
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	init(1, 0, N - 1);

	for (int i = 0; i < M + K; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		if (a == 1) {
			b--;
			update(1, 0, N - 1, b, c);
		}
		else {
			cout << sum(b - 1, c - 1, 1, 0, N - 1) % MODULER << "\n";
		}
	}

}
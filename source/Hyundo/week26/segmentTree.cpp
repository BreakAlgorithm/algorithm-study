#include<iostream>
#define MAX 1000010

using namespace std;

long long arr[MAX];  //�־��� �迭
long long tree[MAX * 4]; //�־��� �迭�� ���� ������� ���׸�Ʈ Ʈ���� �����ϴ� �迭

//Segment Tree�� ����� ����
long long init(int node,int start, int end) {
	//node�� ���� ����� ���, ���� ���� �迭�� �� ���Ҹ� ������ �ϱ� ������ tree[node] = a[start]�� �ȴ�.
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	//node�� ���� �ڽ�, ������ �ڽ�, ������ �ڽ� Ʈ���� ���� ����
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

//���� ���ϴ� ����
//[start,end] : ���� node�� ����ϰ� �ִ� ����
//[left,right] : ���� ���ؾ� �ϴ� ����
long long sum(int left, int right, int node, int start, int end) {
	//1. [left,right]�� [start,end]�� ��ġ�� �ʴ� ���
	// : �� �̻� Ž���� �̾�� �ʿ䰡 ����
	if (left > end || right < start) return 0;

	//2. [left,right]rk [start,end] �� ������ �����ϴ� ���
	// : ���� �ȿ� ���ԵǸ� �� �ڽĵ� ��� ���ԵǹǷ� �� �̻� �ڽ� ��带 ȣ���� �ʿ䰡 ����
	if (left <= start && end <= right) return tree[node];

	//3. [start,end]�� [left,right]�� ������ �����ϴ� ���
	//4. [left, right] ��[start, end]�� ������ �ִ� ���(1, 2, 3 ������ ������ ���)
	// : ���� �ڽİ� ������ �ڽ��� ��Ʈ�� �ϴ� Ʈ������ �ٽ� Ž���� ����
	int mid = (start + end) / 2;
	return sum(left, right, node * 2, start, mid) + sum(left, right, node * 2 + 1, mid+1, end);
}

//���� �����ϴ� ����
//� ���� ������ ���, �� ���ڰ� ���Ե� ������ ����ϴ� ��带 ��� �����ؾ� ��
//dif = val - arr[index] (arr[index] : ����� ����,  val : ������ ���� )
void update(int node, int start, int end, int index, long long dif) {
	//1. [start,end]�� index�� ���Ե��� �ʴ� ���
	if (index < start || index > end) return;

	//2. [start,end]�� index�� ���ԵǴ� ���
	// : diff��ŭ �������� ���� ������ �־�� ��
	tree[node] += dif;

	//���� node�� ���� ��尡 �ƴ� ��� �ڽĵ� ������ �־�� �ϱ� �빮�� ���� ������� �˻�
	if (start == end) return;
	int mid = (start + end) / 2;
	update(node * 2, start, mid, index, dif);
	update(node * 2 + 1, mid + 1, end, index, dif);
}


int main() {
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	init(1, 0, N-1);

	for (int i = 0; i < M+K; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		if (a == 1) {
			b--;
			long long diff = c - arr[b];
			arr[b] = c;
			update(1,0,N-1,b,diff);
		}
		else {
			cout<<sum(b-1,c-1,1,0,N-1)<<endl;
		}
	}

}
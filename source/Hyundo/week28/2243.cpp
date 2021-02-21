#include <iostream>

#define MAX 1000001

using namespace std;

long long tree[4*MAX];
//���� ��� : ���� ������ ����
//�θ� ��� : ������ �����鿡 �ش��ϴ� ���� ������ ��

//top-down������� �ش� index���� ã���鼭 ���鿡 ����� ���� ��� data�� �� ���� �����Ѵ�.
void update(int node, int start, int end, int index, long long diff){
	if (start > index || index > end)
		return;

	tree[node] += diff;

	cout << node << " : " << tree[node] << endl;

	if (start != end){
		int mid = (start + end) / 2;
		update(node * 2, start, mid, index, diff);
		update(node * 2 + 1, mid + 1, end, index, diff);
	}
}


int query(int index, int target, int start, int end) {
	if (start == end)
		return start;
	int mid = (start + end) / 2;
	//�̾ƾ� �ϴ� ������ ��ȣ���� ���� Ʈ���� ������ �� ���� ���
	//�ަU Ʈ�� ������ target�� �ش��ϴ� ������ ���� �� ����
	if (target <= tree[index * 2])
		return query(index * 2, target, start, mid);
	//�̾ƾ� �ϴ� ������ ��ȣ���� ���� Ʈ���� ������ �� ���� ���
	//���� Ʈ�������� target�� �ش��ϴ� ������ ���� ���� ����
	else
		return query(index * 2 + 1, target - tree[index * 2], mid + 1, end);
	//������ ��忡�� ���� ��忡 �ִ� ������ ������ ���� ����Ǿ� �����Ƿ�
	//������ ��忡�� �ش� target�� ã�� ���ؼ��� ���ʳ���� �� ��ŭ �����ؾ� �Ѵ�.
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int A;
		cin >> A;
		if (A == 1){
			int B;
			cin >> B;
			int index = query(1, B, 1, MAX);
			cout << index << "\n";
			update(1, 1, MAX, index, -1);
		}

		else{
			int B;
			long long C;
			cin >> B >> C;

			update(1, 1, MAX, B, C);
		}
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>

using namespace std;

//�� ������ x, y, r �� ��� �ִ� Ŭ����
class camp {
public:
	int x, y, r;
	camp() {}
	camp(int x, int y, int r) {
		this->x = x;
		this->y = y;
		this->r = r;
	}
};

int t, n;
camp c[3000];
int root[3000];

int find(int i) {
	if (i == root[i])
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
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> t;
	for(int i=0;i<t;i++){
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin>>c[i].x>>c[i].y>>c[i].r; //
			root[i] = i;
		}

		int cnt = 0;
		//��� ������ ���Ͽ� ���� ���Ͽ� merge ���� Ȯ��
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int x = c[i].x - c[j].x;
				int y = c[i].y - c[j].y;  
				int r = c[i].r + c[j].r;  //c[i] ���� c[j] ���� ���ްŸ��� ��
				int d = x * x + y * y; //c[i] ���� c[j] ���� �߽��� ���� �Ÿ�(�� ����)

				//c[i] ���� c[j] ���� �߽��� ���� �Ÿ�(�� ����) �� c[i] ���� c[j] ���� ���ްŸ��� ��(�� ����)
				//���Ͽ� �� ������ ����� �����ϴٸ� merge
				if (d <= r * r) {
					if (find(i) != find(j)) {
						merge(i, j);
						//�� ���� ����� �����Ͽ� �ϳ��� �׷����� �������� �� cnt++
						cnt++;
					}
				}
			}
		}

		//ó���� �־��� �� �׷��� ����-������ �׷��� ���� = ���� ������ �׷� ����
		cout << n-cnt << endl;
	}
	return 0;
}

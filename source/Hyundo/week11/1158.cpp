#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> v;
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
		v.push_back(i);
	vector<int>::iterator it;
	it = v.begin();
	cout << "<";
	while (v.size() != 1) {
		for (int i = 0; i < K - 1; ++i) {
			++it;
			//������ ���� ��쿡 �����̹Ƿ� begin���� �ٽ� ����
			if (it == v.end())
				it = v.begin();
		}
		//�� ��ġ�κ��� K��°�� ���ŵǴ� ����� ���
		cout << *it << ", ";
		it = v.erase(it);
		if (it == v.end())
			it = v.begin();
	}
	cout << *it << ">";
}
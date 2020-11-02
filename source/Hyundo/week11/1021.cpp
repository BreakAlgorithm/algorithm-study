#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int main() {
	int count = 0;
	deque<int> dq;
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		dq.push_back(i);

	for (int i = 0; i < M; ++i) {
		int num;
		cin >> num;
		int index = 0;
		for (int i = 0; i < dq.size(); ++i) {
			if (dq[i] == num) {
				index = i;
				break;
			}
		}
		//�� �տ� �ִ� ���� �������� ������ �ε��� ���� ���
		//2�� ����� 3�� ������ �� ������ ������ ã��
		//2�� ���� ����
		if (index < dq.size() - index) {
			for (;;) {
				if (dq.front() == num) {
					dq.pop_front();
					break;
				}
				++count;
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		//3�� ���� ����
		else {
			for (;;) {
				if (dq.front() == num) {
					dq.pop_front();
					break;
				}
				++count;
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}
	cout << count;
}
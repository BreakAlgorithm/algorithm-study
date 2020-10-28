#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

#define MAX 1000001

int N;
int NGE[MAX];
stack<std::pair<int, int>> s;

int main() {
	memset(NGE, -1, sizeof(NGE));

	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		//stack�� ����ִ� ��쿡�� push
		if (s.size() == 0) 
			s.push({ tmp, i });
		else {
			//stack ���� ������ ������ �� ū ���� ���ų� stack�� �� ������ �ݺ�
			while (tmp > s.top().first) {
				//stack���� �ִ� ������ ���� ���� �� ũ�Ƿ� ���� ���� ��ū���� ����
				NGE[s.top().second] = tmp;
				//stack�� �ִ� ���� pop
				s.pop();
				if (s.size() == 0) break;
			}
			//stack���� �� ū ���� ���� ��쿡�� ������ ���� stack�� push
			s.push({ tmp, i });
		}
	}
	for (int i = 0; i < N; i++) cout << NGE[i] << " ";
}

#include<iostream>
#include<vector>
using namespace std;
int main() {
	int N;
	cin >> N; // ǳ���� ����
	vector<pair<int, int>> v; // N ���� ��Ҹ� ���� ���͸�����

	for (int i = 1; i <= N; i++) { // ǳ�� ��ȣ�� 1���� N����  
		int num;
		cin >> num;

		v.push_back(make_pair(i, num));
	}
	while (v.empty() != true) { //������� ���� ��쿡 ��� �ݺ� 

		cout << v.front().first << " ";
		int a = v.front().second;
		v.erase(v.begin());


		if (a < 0) { //���� ��� - �� �ڸ� �� ������ 
			for (int j = 0; j < abs(a); j++) {
				v.insert(v.begin(), v.back());
				v.erase(v.end());
			}
		}
		else { // ��� ���- �� ���� �� �ڷ� 
			for (int j = 0; j < a - 1; j++) {
				v.push_back(v.front());
				v.erase(v.begin());
			}
		}
	}

	return 0;
}

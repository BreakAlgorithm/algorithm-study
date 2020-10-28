#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	int T;
	int n;
	int num;
	string p;
	string arr;
	bool reverse;
	bool error;
	deque<int> d;

	cin >> T;

	while (T--) {
		d.clear();
		num = 0;
		reverse = false;
		error = false;

		cin >> p;
		cin >> n;
		cin >> arr;

		//�Է°��� "[" �� "]"����
		arr = arr.substr(1, arr.size() - 2);

		for (int i = 0; i < arr.size(); ++i) {
			if (atoi(arr.substr(i, 1).c_str()) != 0 || arr.substr(i, 1).compare("0") == 0) {
				num *= 10;
				num += stoi(arr.substr(i, 1));
			}
			else {
				d.push_back(num);
				num = 0;
			}
		}

		if (num != 0) {
			d.push_back(num);
		}

		for (int i = 0; i < p.size(); ++i) {
			if (p[i] == 'R') {
				reverse = !reverse;
			}
			else if (p[i] == 'D') {
				//���� ����ִ� ���¿��� D�� ������ ��� error ó��
				if (d.empty()) {
					error = true;
					break;
				}
				if (reverse == true) {
					d.pop_back();
				}
				else {
					d.pop_front();
				}
			}
		}

		if (error) {
			cout << "error" << endl;
			continue;
		}

		cout << "[";
		//���� ���°� reverse �Ǿ� �ִ� ���°� �ƴ϶�� �տ��� ����
		if (!reverse) {
			while (d.size()) {
				cout << d.front();
				d.pop_front();
				if (d.size()) {
					cout << ",";
				}
			}
		}
		//���� ���°� reverse�� Ȧ���� �̷�� ���� �ݴ��� ���¶�� �ڿ��� ����
		else {
			while (d.size()) {
				cout << d.back();
				d.pop_back();
				if (d.size()) {
					cout << ",";
				}
			}
		}
		cout << "]" << endl;
	}

	return 0;
}
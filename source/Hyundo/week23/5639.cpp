#include<iostream>
#include<vector>

using namespace std;

vector<int> arr;

void makeTree(int from, int to) {
	int idx = from + 1;
	if (from == to)
		return;
	//leaf node�� ��� ���
	if(from == to - 1){
		cout << arr[from] << endl;
		return;
	}
	//from(root)�� �������� left�� right�� ������� ã��
	while (idx < to && arr[idx] < arr[from]) {
		idx++;
	}
	//root�� �������� left�� right�� ������ ��������� ����
	makeTree(from + 1, idx);
	makeTree(idx, to);
	//left�� right���� ����� ��� �Ϸ�� �Ŀ� parent node�� ������ ���
	cout << arr[from] << endl;
}


int main() {
	int num;
	//�Է�
	while (cin >> num) {
		if (num == -1)
			break;
		else
			arr.push_back(num);
	}
	//from 0 ~ to arr.size()
	makeTree(0, arr.size());

	return 0;
}
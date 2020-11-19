#include<iostream>
#include<vector>
#include<string>

#define MAX 1100000
//�Է� ���� 1000001�� ���ѵǾ� ������
//100001ũ�ų� ����, �Ҽ��̸鼭 �Ӹ������ ���� ã�� ����
//�Ҽ��� ������ �� ������ �� ũ�� ��ƾ� �Ѵ�.
using namespace std;

int N;

bool arr[MAX];
vector<int> primeNum;

void aratos() {
	int i = 2;
	for (i = 2; i < MAX; i++) {
		arr[i] = i;
	}

	for (i = 2; i < MAX; i++) {
		if (arr[i] == 0)
			continue;
		for (int j = i + i; j < MAX; j += i) {
			arr[j] = 0;
		}
	}

	for (int i = 2; i < MAX; i++)
	{
		if (arr[i] != 0)
			primeNum.push_back(i);
	}
}



int main() {

	aratos();

	cin >> N;

	for (int i = 0; i < primeNum.size(); i++)
	{
		bool check = true;
		if (primeNum[i] < N)
			continue;
		else
		{
			string str=to_string(primeNum[i]);
			for (int i = 0; i < str.size() / 2 + 1; i++) {
				if (str[i] == str[str.size() - i-1])
					continue;
				else {
					check = false;
					break;
				}
			}

			if (check == true)
			{
				cout << primeNum[i] << endl;
				break;
			}
		}

	}



	return 0;
}
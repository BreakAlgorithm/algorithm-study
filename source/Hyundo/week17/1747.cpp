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

//�����佺�׳׽��� ü �˰����� �̿��Ͽ� (1~1100000) ������ �Ҽ��� primeNum�� ����
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

	//��ü �Ҽ��� ������ŭ check
	for (int i = 0; i < primeNum.size(); i++)
	{
		bool check = true;
		//���� �Ҽ��� N���� ���� ��� �������� �ʴ´�.
		if (primeNum[i] < N)
			continue;

		//1. ���� �Ҽ��� N���� ŭ
		else
		{
			//�Ӹ������ Ȯ���ϱ� ���� int to string
			string str=to_string(primeNum[i]);
			//���� ���� �ڸ����� ���� �ڸ������� �Ӹ���� Ȯ��
			for (int i = 0; i < str.size() / 2 + 1; i++) {
				//2. �Ӹ���� ����� check = true�� for�� ����
				if (str[i] == str[str.size() - i-1])
					continue;
				else {
					check = false;
					break;
				}
			}

			//(1) (2) ���ǿ� ��� �ش��ϴ� ù�� ° ���� =(3).���� ���� ��
			//(1)(2)(3) ���ǿ� �ش��ϴ� ���ڸ� ����ϰ� �ݺ����� ����
			if (check == true)
			{
				cout << primeNum[i] << endl;
				break;
			}
		}

	}



	return 0;
}
#include<iostream>
#include<vector>

#define MAX 4000001

using namespace std;

bool arr[MAX];

vector<int> primeNum;

//�����佺�׳׽��� ü �˰����� �̿��Ͽ� (1~4000000) ������ �Ҽ��� primeNum�� ����
void aratos() {
	int i = 2;
	arr[1] = 1;
	for (i = 2; i < MAX; i++) {
		if (arr[i] == 1)
			continue;
		for (int j = i + i; j < MAX; j += i) {
			arr[j] = 1;
		}
	}
	for (int i = 2; i <= MAX; i++) {
		if (arr[i] == 0) {
			primeNum.push_back(i);
		}
	}
}

int main()
{
	aratos();

	int count=0;
	int N;

	cin >> N;
	int top = 0,bot = 0,sum = 0;

	int maxIdx = primeNum.size();
	//�Ʒ� ������ ����� ��� �� �̻� count�� �������� �ʴ´�.
	while (bot <= top && top < maxIdx && primeNum[bot] <= N) {
		//�־��� N������ sum�� ������ top�� ++�Ͽ� ����index�� �Ҽ��� ���Ѵ�.
		if (sum < N) {
			sum += primeNum[top++];
		}
		//�־��� N������ sum�� ũ�� bot�� ++�Ͽ� ����index�� �Ҽ��� ����.
		else if (sum >= N) {
			sum -= primeNum[bot++];
		}
		//�Ҽ��� ���� �Է°� N�� ���� ��� count�� �����ش�.
		if (sum == N) count++;
	}


	cout << count << endl;

	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001

using namespace std;

int N;
int M;
int lesson[MAX];

int main()
{
	cin >> N >> M;
	int tmp;
	int left = 0;
	int right = 0;
	for (int i = 0; i < N; i++) {
		cin >>lesson[i];
		right += lesson[i]; 
		left = left < lesson[i] ? lesson[i] : left;
	}

	while (left <= right) 
	{
		//������ ��緹�� ũ�� mid
		//�ݺ����� ���鼭 left���� right���� �缳�� �Ǹ鼭 mid���� �ٲ�
		int mid = (left + right) / 2;

		int sum = 0; 
		int cnt = 0;
		for (int i = 0; i < N; i++){
			if (sum + lesson[i] > mid){
				sum = 0; 
				cnt++; 
			} 
		sum += lesson[i]; 
		} 
		//�������� ���� �͵��� ���� mid�� ���� ���� ��� cnt�� ���� ��緹�� ������ ä��
		if (sum != 0) 
			cnt++; 

		cout <<" left = "<< left << " right = " << right<<" ";
		//���� ������ m���� �۰ų� ������ �ִ밪 ����
		if (cnt <= M) 
			right = mid - 1;
		//���� ������ m���� ũ�� �ּڰ� ����
		else 
			left = mid + 1; 

		cout <<" mid = "<< mid <<" cnt = "<<cnt<< endl;
	}

	cout << left << endl;

	return 0;
}
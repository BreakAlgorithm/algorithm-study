#include<iostream>
#include<vector>

using namespace std;

int T;

int arr[100001];

vector<int> primeNum;

void aratos() {
	int i = 2;
	for (i = 2; i < 100001; i++) {
		arr[i] = i;
	}

	for (i = 2; i < 100001; i++) {
		if (arr[i] == 0)
			continue;
		for (int j = i + i; j < 100001; j += i) {
			arr[j] = 0;
		}
	}

	for (int i = 2; i < 100001; i++)
	{
		if(arr[i]!=0)
			primeNum.push_back(arr[i]);
	}
}

void solution(int num)
{
	if (num == 0||num==1)
		return;
		
	if (arr[num] != 0) {
		cout << num <<" "<<1<< endl;
	}

	int tmpNum=num;
	int countNum[100001] = { 0, };

	for (int i=0;num!=1;) {
		if (num % primeNum[i] == 0)
		{
			//���� �� ����� ������ ������ count
			countNum[primeNum[i]]++;
			//���ڸ� ������ �� �� ���� ���ڸ� num�� ����				
			num = num / primeNum[i];
			i = 0;
			continue;
		}
		else
			i++;
	}


	for (int i = 2; i < tmpNum; i++)
	{
		if (countNum[i] != 0)
		{
			cout << i << " " << countNum[i] << endl;
		}
	}

}


int main() {
	cin >> T;

	aratos();

	for (int i = 0; i < T; i++)
	{
		int tmp;
		cin >> tmp;
		solution(tmp);
	}

	return 0;
}
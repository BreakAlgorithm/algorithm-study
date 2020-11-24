#include<iostream>
#include<vector>
#define MAX 1000001

using namespace std;

int T;

int arr[MAX];

vector<int> primeNum;


//�����佺�׳׽��� ü �˰����� �̿��Ͽ� (1~1000001) ������ �Ҽ��� primeNum�� ����
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
		if(arr[i]!=0)
			primeNum.push_back(arr[i]);
	}
}

void solution(int num)
{
	//���� ���� ���ڰ� �ƴϹǷ�  return
	if (num == 0||num==1)
		return;
		
	//�Է¹��� ���ڰ� �Ҽ���� "num 1" ���·� ���
	if (arr[num] != 0) {
		cout << num <<" "<<1<< endl;
		return;
	}

	//�Է°��� �����ϹǷ� ���Ƿ� ������ num��
	int tmpNum=num;
	//���μ����ظ� �����Ͽ��� ���� �� ������ ��� Ƚ���� ����
	int countNum[MAX] = { 0, };

	for (int i=0;num!=1;) {
		//���μ� ���ش� �Ҽ��� �̷�����Ƿ� �Է°� Num�� primeNum �迭�� ����� �����鼭 ����
		//�������� 0�ΰ�� : �ش� ���ڷ� ���μ� ���ذ� �̷������ ���
		if (num % primeNum[i] == 0)
		{
			//���� �� ����� ������ ������ count
			countNum[primeNum[i]]++;
			//���ڸ� ������ �� �� �������� num�� ����				
			num = num / primeNum[i];
			//i=0���� �ʱ�ȭ�� ���� �ش� �Ҽ��� �ٽ� ���μ����ذ� ����Ǵ� ��츦 üũ
			i = 0;
			continue;
		}
		//�ش� index�� �Ҽ��� ���μ� ���ذ� �̷������ �ʴ� ��� ���� �Ҽ��� ����
		else
			i++;
	}


	//���
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
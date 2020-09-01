#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int S = 0;
int N = 0;
int answer = 0;

void DFS(int sum, int idx)
{
	//arr�� ������ ��� ��쿡�� �Լ� ����
	if (idx >= N)
	{
		return;
	}
	
	//������ �ε����� ���� ���ϱ� ���� ���¸� tmpSum�� ����
	int tmpSum = sum;
	sum += arr[idx];
	
	if (sum== S) {

		answer++;
	}

	DFS(tmpSum, idx + 1); //���� �ε����� ���� ������ ���� ����� �ٽ� ����
	DFS(sum, idx + 1);    //���� �ε����� ���� ���� ���·� �ٽ� ����
}


int main()
{
	int tmp = 0;
	//input
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}

	DFS(0, 0);
	//���� ���
	printf("%d", answer);

	return 0;
}
#include<iostream>
#include<vector>
#define MAX 1000001

using namespace std;

int N, M;
int arrA[MAX], arrB[MAX];
vector<int> result;

int main() {
	std::ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N;i++)
		cin >> arrA[i];
	for (int i = 0; i < M; i++)
		cin >> arrB[i];

	int a=0, b=0;
	//ù��° �迭�� �ι�° �迭�� ���� ����Ʈ�� �ϳ��� �ΰ� ����
	while (true)
	{
		if (a>=N)
		{   //a�� �̹� ������ ������ ��� �������� B �迭�� ä���.
			for (int i = b; i < M; i++)
			{
				result.push_back(arrB[i]);
			}
			break;
		}
		else if (b>=M)
		{   //brk �̹� ������ ������ ��� �������� A�迭�� ä���.
			for (int i = a; i < N; i++)
			{
				result.push_back(arrA[i]);
			}
			break;
		}
		else if (arrA[a] <= arrB[b])
			result.push_back(arrA[a++]);
		else
			result.push_back(arrB[b++]);
	}

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
}
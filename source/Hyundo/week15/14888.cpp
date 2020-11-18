#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 12

using namespace std;

int N; // ������ ����
int arr[MAX]; //������ ���� �����ϴ� �迭
int oper[4] = { 0, };//������ �����ȣ�� ������ �����ϴ� �迭
// + - x /
vector<int> answer; // ������ ���꿡 ���� ����� �����ϴ� ����

//choice �� ���� ���ڿ� ���� �´� ������ ���ִ� �Լ�
int fundamental(int a, int b,int choice) {
	//������ ������ ����� ��� �ش��ϴ� ������ ������ �ϳ� �ٿ��ش�.
	switch (choice) {
	case 0:
		oper[0]--;
		return a + b;
	case 1:
		oper[1]--;
		return a - b;
	case 2:
		oper[2]--;
		return a * b;
	case 3:
		oper[3]--;
		return a / b;
	default:
		break;
		return 0;
	}

}

void dfs(int x, int sum)
{
	if (x > N-1) {
		answer.push_back(sum);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (oper[i] > 0) {
				dfs(x + 1, fundamental(sum, arr[x], i));
			//���� �ܰ迡�� fundamental ������ ���� ������ �ٽ� �����Ͽ� ����ϱ� ����
			//�ش� ������ ���� �ٽ� �÷��־� ���� ���꿡�� ����Ѵ�.
			oper[i]++;
		}
	}
}



int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> oper[i];

	//�ʱ� max�� min ���� ���� ù��° ������ �����Ѵ�.
	int max = arr[0];
	int min = arr[0];
	//ù��° ������ ���� sum���� ����ϰ� �ι�° �������� sum���� ������ �����Ѵ�.
	dfs(1, arr[0]);

	//answer ���� ����� ���� ���� ū ���� ���� ���� ã�´�.
	max = *max_element(answer.begin(), answer.end());
	min = *min_element(answer.begin(), answer.end());

	//�� ���
	cout << max << endl << min;

	return 0;
}
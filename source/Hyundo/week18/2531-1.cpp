#include<iostream>
using namespace std;

int N, d, k, c;
int arr[30003010], kind[3010];

int main(void)
{
	int cnt, max;

	cin >> N >> d >> k >> c;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	//���� �ʹ信 ���Ͽ� ���� ǥ��
	kind[c] = 1; cnt = 1;

	//k����ŭ ���� ����
	for (int i = 0; i < k; i++) {
		//�ߺ����� �ʴ� ������ ��� count����
		if (kind[arr[i]] == 0) cnt++;
		//���Ե� ������ ���� ���� �߰�
		kind[arr[i]]++;
		//Ȯ���� ���� �迭�� �ڿ� ����
		arr[N + i] = arr[i];
	}

	for (int i = 0; i < N; i++) {
		if (cnt > max)
			max = cnt;

		//ù��° ���ÿ� ���� ���� ����
		kind[arr[i]]--;
		
		//�����Ͽ��� �� ���� ������ ���̻� ���Ե��� �ʴ� ��� ������ ����
		if (kind[arr[i]] == 0) cnt--;

		//���� ������ �ʹ��� ���õ� ���� ���� ��� ������ �߰�
		if (kind[arr[i + k]] == 0) cnt++;
		//�߰����� ���ÿ� ���� ���� ����
		kind[arr[i + k]]++;
	}


	cout << max;
}
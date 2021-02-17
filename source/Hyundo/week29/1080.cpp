#include<iostream>

using namespace std;

int main() {

	bool arr1[51][51];
	bool arr2[51][51];
	bool chk[51][51];

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			if (tmp[j] == '0')
				arr1[i][j] = 0;
			else
				arr1[i][j] = 1;
		}
	}
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			if (tmp[j] == '0')
				arr2[i][j] = 0;
			else
				arr2[i][j] = 1;
		}
	}

	//arr1�� arr2�� ���� �ٸ��� 1�� ǥ��, ������ 0���� ǥ��
	//1�ΰ��� �����ϸ� �ű⼭ ���� 9ĭ ������ 
	//���Ŀ� �ٽ� �׻��¿��� 1�ΰ����� ã�ư��� 9ĭ �����
	//������ �� ���Ҵµ� 1�� ���� ������ -1 ����ϰ�
	//�ƴϸ� �ٲ� Ƚ�� ���

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr1[i][j] != arr2[i][j])
			{
				chk[i][j] = 1;
			}
			else
				chk[i][j] = 0;
		}
	}

	int cnt = 0;
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			if (chk[i][j] == 1)
			{
				cnt++;
				for (int a = i; a < i + 3; a++) {
					for (int b = j; b < j + 3; b++) {
						if (chk[a][b] == 1)
							chk[a][b] = 0;
						else
							chk[a][b] = 1;
					}
				}
			}
		}
	}

	bool ans = true;
	for (int i = 0; i < N ; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (chk[i][j] == 1)
				ans = false;
		}
	}

	if (ans == false)
		cout << "-1" << endl;
	else
		cout << cnt << endl;

	return 0;
}
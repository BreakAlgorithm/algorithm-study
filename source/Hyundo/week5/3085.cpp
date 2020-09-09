//���� 3085��
//for(for)������ �Ѱ��� ���� �¿�� �ٲ㺻 �Ŀ� üũ
//for(for)������ �Ѱ��� ���� ���Ϸ� �ٲ㺻 �Ŀ� üũ
//üũ �� ���η� ���� �� �� �ѹ� ���η� ���� �� �� �ѹ� üũ
//��� �� �����Ͽ� ���� �� ���� ������ ä��
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 50
int N;
string board[MAX];

//����� ���� ����
int answer = 1;

void solution() {
	//���η� ���� �� �� üũ
	for (int i = 0; i < N; i++)
	{
		int sum = 1;
		for (int j = 1; j < N; j++){
			if (board[i][j-1] == board[i][j])
				sum++;
			else {
				if(answer < sum)
					answer = sum;
				sum = 1;
			}
		}
		//j�� N���� Ȯ���Ͽ��� �� �ϳ��� �߰��� ��� 
		//else������ ���� ���ϹǷ� �̰����� üũ
		if (answer < sum)
			answer = sum;

	}
	//���η� ���� �� �� üũ
	for (int i = 0; i < N; i++)
	{
		int sum = 1;
		for (int j = 0; j < N - 1; j++)
		{
			if (board[j][i] == board[j+1][i])
				sum++;
			else {
				if (answer < sum)
					answer = sum;
				sum = 1;
			}
		}
		//j�� N���� Ȯ���Ͽ��� �� �ϳ��� �߰��� ��� 
		//else������ ���� ���ϹǷ� �̰����� üũ
		if (answer < sum)
			answer = sum;
	}
}


int main()
{
	//input
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> board[i];
	
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N-1; j++)
		{
			//�¿�� �ϳ��� �ٲ㰡�鼭 üũ
			swap(board[i][j], board[i][j + 1]);
			solution();
			swap(board[i][j], board[i][j + 1]);
			//���Ϸ� �ϳ��� �ٲ㰡�鼭 üũ
			swap(board[j][i], board[j+1][i]);
			solution();
			swap(board[j][i], board[j + 1][i]);
		}
	}

	cout << answer << endl;
	return 0;
}
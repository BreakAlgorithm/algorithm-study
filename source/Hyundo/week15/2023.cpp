#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N;
int answer=0;

//�Ҽ� �Ǻ�
bool primeCheck(int num) {
	//1�� �Ҽ����� ����
	if (num == 1)
		return false;
	//2���� num-1���� �����鼭 �ѹ��̶� �������� ���� ��� false return(�Ҽ��� �ƴ�)
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

//���� �Լ�(���� answer�� ���� ���� ���� ���ǿ� �ش��ϴ��� Ȯ��
//���ǿ� �ش��ϴ� ��� ���� ��Ʈ�� answer���� ���ο� ������ �ʱ�ȭ�Ͽ�
//���� �ܰ迡�� ���ο� answer������ ������ �� �ֵ��� ��
bool condition(int a,int x) {
	if (primeCheck(answer * 10 + a)) {
		answer = answer * 10 + a;
		return true;
	}
	else
		return false;
}


void dfs(int x)
{
	//����
	if (x > N)
	{
		cout << answer<<endl;
		return;
	}
	//���� answer���� ������ �ľ��ϰ� 1~9������ ���� ���� ���ο� ���ڸ� ���� dfs�� ��������� ����
	for (int i = 1; i < 10; i++)
	{
		if (condition(i, x)) {
			dfs(x + 1);
			//���� �ܰ迡�� answer���� �ٽ� ����ϱ� ���� 10���� �������־� ������ ���·� backtracking�ϴ� ����
			answer /= 10;
		}
	}
	return;
}


int main()
{
	cin >> N;

	dfs(1);

	return 0;
}
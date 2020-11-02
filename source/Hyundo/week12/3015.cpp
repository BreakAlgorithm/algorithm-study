#include <iostream>

#include <stack>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	stack<pair<int, int>> s; //Ű, ���� �� ��

	long long result = 0;

	for (int i = 0; i < N; i++)
	{
		int height;
		cin >> height;

		//���� ����� Ű�� ������ top�� �ִ� ������� ũ�ٸ�
		//�� ����� ���� ��� ���ķ� ���� �̷��� ����
		while (!s.empty() && s.top().first < height)
		{
			result += s.top().second;
			s.pop();
		}

		//�� �տ� ����� �����()
		if (s.empty())
			s.push({ height, 1 });
		else
		{
			//���� Ű�� ��� ���� ó��
			if (s.top().first == height)
			{
				pair<int, int> cur = s.top();
				s.pop();
				result += cur.second;
				//���� �� ���� ū ����� ���� �̷�
				if (!s.empty())
					result++;
				//�����ؼ� ���� Ű�� �����Ƿ�
				cur.second++;
				s.push(cur);
			}
			//�� ���� ����� ���� ���
			else
			{
				s.push({ height, 1 });
				//���� �� ���� ū ����� ���� �̷�
				result++;
			}
		}
	}

	cout << result << "\n";
	return 0;
}

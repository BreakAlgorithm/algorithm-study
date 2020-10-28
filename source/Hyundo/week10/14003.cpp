#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

const int MAX = 1000001;

int N;
int seq[MAX], pos[MAX];

// �̺� Ž������ LIS�� ����
int getLisLen()
{
	vector<int> lis;
	lis.push_back(seq[0]);
	for (int i = 1; i < N; ++i)
	{
		int cand = seq[i];
		//���� seq[i-1]���� ���� seq[i]�� �� ũ�ٸ�
		if (lis.back() < cand)
		{
			//�� Ŭ ��쿡�� lis�� push_back�� �ǰ� ����� �����Ѵ�.
			lis.push_back(cand);
			//���� ���� ��ġ�� pos�� �����Ѵ�.
			pos[i] = lis.size() - 1;
		}
		//���� seq[i-1]���� ���� seq[i]�� �� �۴ٸ�
		else
		{
			//lower_bound(value) = value �� ���ų� ū ���� ó�� ��Ÿ���� ��ġ�� �ݺ��ڷ� ��ȯ
			vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), cand);
			//lower_bound�� ���� ���� seq[i]�� �ڸ��� ã�´�.
			*it = cand;
			// ã�� ��ġ�� pos�� �����Ѵ�.
			pos[i] = int(it - lis.begin());
		}
	}

	//���������� index�� �̵��ϸ鼭 index�� ũ�鼭 seq[index]�� �� Ŀ�� ��쿡�� push_back�� �����Ͽ�
	//���� size�� ��ȯ�Ѵ�.
	return lis.size();
}

void printLis()
{
	int len = getLisLen();
	cout << len << endl;

	stack<int> st;
	int idx = len - 1;
	//pos ���� �񱳸� ���� �ѱ��̷κ��� �ϳ��� �ٿ����� ������ ��쿡�� ����ϸ�
	//���� �� �κм����� ������ ����� �� �ִ�.
	//�̴� idx�� �� ũ���� seq[idx]�� ���� �� ���� ��쿡�� pos�� ���� �پ��� �����Ǳ� �����̴�.
	for (int i = N - 1; i >= 0; --i)
		if (pos[i] == idx)
		{
			st.push(seq[i]);
			--idx;
		}

	while (!st.empty())
	{
		cout << st.top() << ' ';
		st.pop();
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		scanf("%d", &seq[i]);

	printLis();

	return 0;
}
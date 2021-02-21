#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int ans = 0;
vector<pair<int, int>> time;

int DFSEnd(int count, int i) {
	//cout << "End// count : " << count << " i :" << i << endl;

	//������ ��ġ���� �̵��� ��� �� count�� return
	if (i == N-1)
		return count;

	int start;
	for (start = i; start < N; start++)
	{
		if (time[start].first >= time[i].second)
		{
			//������ġ�� �����½ð� ���Ŀ� ����Ǵ� ȸ�ǿ� ���Ͽ� DFSEnd ����
			return DFSEnd(count+1, start);
			break;
		}
	}

	//������ġ�κ��� ���̻� ����� ���� ���� ��� return
	if (start == N)
		return count;

}

int DFSFront(int count, int i) {
	//cout << "Front// count : " << count << " i :" << i << endl;
	if (i == 0)
		return count;

	int end;
	for (end = i; end >= 0; end--)
	{
		if (time[end].second <= time[i].first)
		{
			return DFSFront(count + 1, end);
			break;
		}
	}

	if (end == N)
		return count;

}


int main() {

	int cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		time.push_back(make_pair(a, b));
	}

	sort(time.begin(), time.end());

	/*
	for (int i = 0; i < N; i++)
	{
		cout <<i<<" = "<< time[i].first << " " << time[i].second << endl;
	}
	*/

	for (int i = 0; i < N; i++)
	{
		//cout << "i = " << i << endl;
		int tmp = DFSFront(0, i) + DFSEnd(1, i);
		if (tmp > ans)
			ans = tmp;
	}

	cout << ans+1 << endl;

	return 0;
}
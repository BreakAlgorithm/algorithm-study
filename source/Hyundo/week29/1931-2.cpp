#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector< pair<int, int> > time;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second) 
		return a.first < b.first;
	//������ �ð��� ���ٸ� ���� �ð� �������� ����
	return a.second < b.second; 
	//������ �ð� �������� ����
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		time.push_back(make_pair(a, b));
	}

	sort(time.begin(), time.end(), compare);

	int lastTime = time[0].second;
	int ans = 1;
	for (int i = 1; i < N; i++){
		//����ȸ���� ���۽ð�(time[i].first)�� ���� ȸ�� �����½ð�(time[i-1].second)
		//���� ũ�ų� ������ ans++
		//���Ŀ� ����ȸ���� �����½ð��� lastTime�� �ʱ�ȭ
		if (lastTime <= time[i].first){
			lastTime = time[i].second;
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}
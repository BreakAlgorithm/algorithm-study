#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

#define MAX 300001

using namespace std;

vector<vector<int>>map(MAX);
bool visit[MAX];

int n, m, k, x;


void bfs(int start) {
	int dist = 0;
	queue<int> q;
	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		int q_size = q.size();

		//���� ���÷κ��� ����� ��� ���ÿ� ���Ͽ� visit ǥ�� (1�� �̵�)
		//���� q�� ��� �ִ� ���� : dist��ŭ �̵����� �� ������ ����
		for (int i = 0; i < q_size; i++) {
			int cur = q.front();
			q.pop();
			//���� ���ÿ� ����� ��� ���ø�ŭ �ݺ�
			for (int j = 0; j < map[cur].size(); j++)
			{	
				int next = map[cur][j];
				//�̹� �湮�� ���ø� pass
				if (visit[next])continue;
				visit[next] = true;
				q.push(next);
			}
		}
		//���� ���÷κ��� ����� ���ÿ� ���Ͽ� 1�� �̵��� ���������� �̵��Ÿ� �߰�
		dist++;
		//���� ���� �̵�Ƚ���� �־��� �Ÿ����� k�� ���� q�� ���� �ʾҴٸ�
		if (dist == k && !q.empty()) {
			priority_queue<int, vector<int>, greater<int>>pq;
			while (!q.empty()) {
				pq.push(q.front());
				q.pop();
			}
			while (!pq.empty()) {
				cout << pq.top() << endl;
				pq.pop();
			}
			return;
		}
	}
	cout << -1;
	return;
}


int main()
{
	cin >> n >> m >> k >> x;
	int c1;
	int c2;
	for (int i = 0; i < m; i++) {
		cin >> c1 >> c2;
		map[c1].push_back(c2);
	}
	bfs(x);

	return 0;
}
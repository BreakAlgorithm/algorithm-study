#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>
#include <queue>

#define INF 1LL << 60

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

ll dist[111];
ll cost[111];
bool getGee[111];
vector<pii> adj[111];//���� ���� ���� ����

bool visit[111];

int main()
{
	int V, E, start, end;


	//������ �� , ���� ����, ���� ����, ���� ���ܰ���
	scanf("%d %d %d %d", &V, &start, &end, &E);
	//���� ���� ����
	for (int i = 0; i < E; i++)
	{
		int from, to, val;
		scanf("%d %d %d", &from, &to, &val);

		adj[from].push_back({ to, val });
	}
	//�� ���ÿ��� �� �� �ִ� ���� �ִ�
	for (int i = 0; i < V; i++)
		scanf("%lld", &cost[i]);

	//�� ���ú� ����ġ -INF�� �ʱ�ȭ
	for (int i = 0; i < V; i++)
		dist[i] = -INF;

	//���� ������ �ʱⰪ ����
	dist[start] = cost[start];

	// ��������
	bool update = true;
	bool ok = false;

	int cnt = 0;
	while (update && cnt != V)
	{	
		update = false;

		for (int i = 0; i < V; i++)
			for (auto j : adj[i])
			{
				//������ġ ���� �� + ������ġ ���� �� - ������� ��� > ������ġ ���� ��
				if (dist[i] != -INF && dist[i] + cost[j.first] - j.second > dist[j.first])
				{
					dist[j.first] = dist[i] + cost[j.first] - j.second;
					update = true;

					//������ ��ġ���� ������ �̷����
					if (cnt == V - 1)
						//���� ���� ����Ŭ�� �ĺ��� �ش��ϴ� ������ true ǥ��
						getGee[i] = true;
				}
			}
		cnt++;
	}

	// bfs
	bool getChk = false;
	
	queue<int> q;
	for (int i = 0; i < V; i++)
		if (getGee[i])
			q.push(i);

	//���� ���� ����Ŭ�� �ĺ��� �ش��ϴ� ������ ���� bfs�� ���������� ���� �� Ȯ��
	while (!q.empty())
	{
		int here = q.front();
		q.pop();

		if (visit[here])
			continue;

		visit[here] = true;

		for (int i = 0; i < adj[here].size(); i++)
		{	//������ ���� ���������� ���� ���� üũ
			if (adj[here][i].first == end)
			{
				getChk = true;
				break;
			}
			if (!visit[adj[here][i].first])
				q.push(adj[here][i].first);
		}

		if (getChk)
			break;
	}

	if (dist[end] == -INF)
		printf("gg");
	else if (getChk)
		printf("Gee");
	else
		printf("%lld", dist[end]);


	return 0;
}
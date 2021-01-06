#include<iostream>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

int V;
int answer=0;
int maxNode;

vector<vector<pair<int,int>>> arr(100001);
bool visited[100001] = { 0, };//if( visited[i] = 1)  ->  arleady visited


void DFS(int ver, int dis) {

	//�ִ� �Ÿ� ���� + ���� �� leaf nodeã��
	if (dis > answer) {
		answer = dis;
		maxNode = ver;
	}

	visited[ver] = 1;

	for (int i = 0; i < arr[ver].size(); i++) {
		//������ �湮�� ���� �ִ� ��忡���� ���̻��������� ����
		if (visited[arr[ver][i].first] != 1)
			DFS(arr[ver][i].first, dis + arr[ver][i].second);
	}
}


int main()
{
	cin >> V;
	int from;
	for (int i = 0; i < V; i++)
	{
		cin >> from;
		int to, dis;
		while (1) {
			cin >> to;
			if (to == -1)
				break;
			else {
				cin >> dis;
				arr[from].push_back({ to,dis });
			}
		}
	}
	//ù��° DFS .���� �ٱ��� �ִ� ������ ã�´�.
	DFS(1, 0);
	memset(visited, 0, sizeof(visited));
	answer = 0;
	//�ι�° DFS . ���� �ٱ��� �ִ� �������κ��� �Ÿ��� ���� �� ������ ã�´�.
	DFS(maxNode, 0);
	cout << answer;

	return 0;
}
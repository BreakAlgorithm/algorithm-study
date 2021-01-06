#include<iostream>
#include<vector>
#define INF 999999

using namespace std;

void solution(int N, int M, int W) {
	//N���� ����     ������/����ġ
	vector<vector<pair<int, int>>> edge(N + 1);
	//�� ������ �ʱⰪ�� ������ ������ ����
	vector<int> dis(N + 1, INF);
	dis.at(1) = 0; //ù��° ��ġ�� 0���� ����

	//�� ���� ���� ����
	for (int i = 0; i < M; i++) {
		int S, E, T;
		cin >> S >> E >> T;
		//���δ� ������ �����Ƿ� ��������� ����
		edge.at(S).push_back({E,T});
		edge.at(E).push_back({S,T});
	}
	//�� ��Ȧ ���� ����
	for (int i = 0; i < W; i++) {
		int S, E, T;
		cin >> S >> E >> T;
		//��Ȧ�� ������ �����Ƿ� �ܹ��� ����
		//��Ȧ�� �ð��� �ڷ� ���Ƿ� -�� ����
		edge.at(S).push_back({ E,-T });
	}

	bool answer = false;
	//N���� �����ϴ��� dis[1]�� ������ ���� ���� �� ����
	//N��° ���࿡�� ������ �� ��츦 üũ
	//�̿��۾��ݺ�
	for (int i = 1; i <= N; i++) {	//������ ������ŭ ���� relax�۾� ����
		for (int j = 1; j <= N; j++) {	//�� ������ �ش��ϴ� �����鿡 ���� �۾�
			//���� �� ���� ������ ��Ȧ�� ���� ���
			for (int k = 0; k < edge.at(j).size(); k++) {
				int from = j; //������ġ
				int to = edge.at(j).at(k).first; //������ġ
				int weight = edge.at(j).at(k).second; //����or��Ȧ �� ����ġ
				//���� ��ġ�ǰ���ġ�� ��������ġ�� ���� ���� ������ġ ����ġ�� ��
				if (dis.at(from) + weight < dis.at(to)) {
					dis.at(to) = dis.at(from) + weight;
					//���� ����ġ�� ���� ��ȯ��� ���� Ȯ��
					//N��° ���࿡�� ������ �� ��� ���� ����Ŭ
					if (i == N) answer = true;
				}
			}
		}
	}
	if (answer == true)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main() {
	int TC;
	int N;
	int M;
	int W;

	cin >> TC;
	for (int i = 0; i < TC; i++)
	{
		cin >> N >> M >> W;
		solution(N, M, W);
	}
}
#include<iostream>
#include<vector>
#define INF 999999
#define MAX 501

using namespace std;

int N, M;

vector<vector<pair<int,int>>> edge(MAX);
vector<long long> dis(MAX, INF);

int solution(int count) {
	
	bool check = false;
	//��� �� ����
	for(int t=1 ; t <= N ; t++){ //���� ������ŭ ����
	for (int i = 1; i <= N; i++) { //���� �� �����鿡 ���� ��� ����
		for (int j = 0; j < edge.at(i).size(); j++) {

			int from = i;
			int to = edge.at(i).at(j).first;
			long long time = edge.at(i).at(j).second;
			//Relax����
			if (dis.at(i)!=INF && dis.at(from) + time < dis.at(to)) {
				check = true;
				//2��° ����ܰ��� ��쿡�� ���� ������ �Ǵ� ��� : ������ ���� ����Ŭ�� ���� ���
				if (count) return check; 

				dis.at(to) = dis.at(from) + time;
			}
		}
		}
	}
	return check;
}

int main() {

	dis.at(1) = 0;
	cin >> N >> M;

	long long A, B, C;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		edge.at(A).push_back({ B,C });
	}

	solution(0);//ù��° ����
	//�ι�° ����
	if (solution(1) == 1) {
		cout << -1;
	}
	else {
		for (int i = 2; i <= N; i++) {
			if (dis.at(i) == INF)
				cout << -1 << endl;
			else
				cout << dis.at(i) << endl;
		}
	}

	return 0;
}
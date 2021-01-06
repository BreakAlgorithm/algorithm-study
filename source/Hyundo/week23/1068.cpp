#include<iostream>
#include<vector>

using namespace std;

int answer=0;
int root;
int N;
int delNode;
vector<vector<int>> arr(51);


void DFS(int num) {
	//leafnode ���� �ÿ� ����++
	if (arr[num].size() == 0){
		answer++;
		return;
	}

	for (int i = 0; i < arr[num].size(); i++){
		if (arr[num][i] == delNode)//�ڽ� ��尡 �������� ���
		{
			if (arr[num].size() == 1)//�ڽ��� ������ 1�̶��
			{ //���� ��尡 leafnode�� �ǹǷ� ����++
				answer++;
			}
			continue;
		}
		//�� ��� �� �������� ���� �� ���� DFS����
		DFS(arr[num][i]);
	}
}

int main() {

	cin >> N;
	int root;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		if (tmp != -1)
		{
			arr[tmp].push_back(i);
		}
		else
			root = i;
	}
	cin >> delNode;

	//�������ϴ� ��尡 root����� ������ 0
	if (delNode == root)
		cout << "0";
	else {
		DFS(root);
		cout << answer;
	}
}
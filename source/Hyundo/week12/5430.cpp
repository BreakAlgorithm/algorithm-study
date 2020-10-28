#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)

#define MAX 100000

using namespace std;

int T = 0;
string p;
int N;
string sArr;
char str[MAX];
vector<int> vArr;
bool check = false;

//�迭 ��ü reverse
void R() {
	reverse(vArr.begin(), vArr.end());
}

//�迭 ù��° ���� pop
void D() {
	vArr.erase(vArr.begin());
}

//���� ���� ���� R�� Dó�� �� �����ϴ� �κ�
void sol() {
	//1. ���� �����ִ� string ���·� �Ǿ��ִ� arr�� ���Ϳ� push��
	strcpy(str, sArr.c_str());
	char* ptr = strtok(str, "[,]");

	while (ptr) {
		vArr.push_back(stoi(ptr));
		ptr = strtok(NULL, "[,]");
	}

	//2. ���� p���� ���Ͽ� R�� D�Լ� ����
	for (int i = 0; i < p.length(); i++)
	{
		if (p[i] == 'R')
			R();
		else if (p[i] == 'D') {
			if (vArr.empty()) {
				check = true;
				break;
			}
			else
				D();
		}
	}

	//3. ���� ��� ���
	if (check == true)
		cout << "error"<<endl;
	else {
		cout << "[";
		for (int i = 0; i < vArr.size() - 1; i++) {
			cout << vArr[i];
			cout << ",";
		}
		cout << vArr[vArr.size() - 1] << "]"<<endl;
	}
}

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		vArr.clear();
		check = false;
		cin >> p;
		cin >> N;
		cin >> sArr;
		sol();
	}

	return 0;
}
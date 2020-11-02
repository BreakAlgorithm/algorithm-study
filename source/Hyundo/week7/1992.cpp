#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

#define MAX 65

int N;
int image[MAX][MAX];
string str[MAX];
string answer;

bool compareString(vector<string> str) {
	bool check=true;
	for (int i = 1; i < str.size(); i++) {
		check = str[i - 1].compare(str[i]);
		if (check != 0)
			return false;
	}
	return true;
}

string solution(int h,int x,int y)
{ 
	if (h == 1)
		return to_string(image[x][y]);
	vector<string> req;
	req.push_back(solution(h / 2 ,x, y)); 
	req.push_back(solution(h / 2, x, y+(h / 2)));
	req.push_back(solution(h / 2, x+(h /2) , y));
	req.push_back(solution(h / 2, x+(h / 2), y+(h / 2)));
	
	//abcd�� �� ���ٸ� �� ���� ���� �̾Ƽ� �װ� print�ϴµ� �� ���� ()�� ��������
	//abcd�� ���� �� ������ �ƴ϶�� ���θ� ���� �ȿ� ������� ��� ����Ʈ
	if (compareString(req)&&(req[0]).size()==1)
			return req[0];
	else
		return "("+ req[0] + req[1] + req[2] + req[3]+")";
}


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < N; j++)
			image[i][j] = s[j] - '0';
	}
	cout << solution(N, 0, 0);
	return 0;
}
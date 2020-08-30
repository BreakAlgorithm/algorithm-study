#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

vector<long long> result;

void dfs(long long num, int digit) {
	if (digit > 9) return ;//�ִ�� 9876543210 10�ڸ� : digit 9
	result.push_back(num); //dfs �Լ��� ���� ���� �����ϴ� ��, result�� push
	//0~10���� ���� num���� �ٷ� �ڸ������� ū ��쿡�� digit�� �������� dfs����
	for(int i = 0; i < 10; i++) {
		if (num % 10 > i) {
			dfs(num * 10 + i, digit+1);
		}
	}
	return ;
}
int main() {

	int input;
	scanf("%d", &input);
	for (int i = 0; i < 10; i++)
		dfs(i,0);
	sort(result.begin(), result.end());
	cout << result[input] << endl;
	
}
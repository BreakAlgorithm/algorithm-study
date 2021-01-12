#include <iostream>

using namespace std;

int N;
int mem[10001], box[1000];

int dp(int from)
{   //from���κ��� �����Ͽ� ���� ���� �ڽ��� ������ �ִ� ���� ��ȯ
	int answer = mem[from + 1];
	if (answer != -1) {
		mem[from + 1] = answer;
		return answer;
	}
	answer = 0;
	//from(������ġ)�κ��� 1~N-next �Ÿ���ŭ ������ ��ġ���� ���� Ȯ��
	for (int next = from + 1; next <= N; next++)
		if (from == 0 || box[from] < box[next]) {
			int tmp = dp(next) + 1;
			if (tmp > answer)
				answer = tmp;
		}
	mem[from + 1] = answer;
	return answer;
}

int main(void)
{
	std::fill_n(mem, 1001, -1);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> box[i];
	//ù��° �ڽ� ���� ����
	cout << dp(0) << endl;

	for (int i = 0; i <= N; i++) {
		cout << i << " : " << mem[i] << endl;
	}

	return 0;

}

//�ϰ� �������� Ű�� ���� 100�� �ǵ���
//�־��� 9���� Ű�߿��� 2���� �����ϰ�
//7���� Ű������ 100�� ��츦 ã���� �ȴ�.
//�ϰ� �����̸� ã�� �� ���� ���� ���ٰ� �Ͽ���
//������ ������ ���� ������ ��쿡�� �ƹ��ų� ����Ѵ�. ��� ������ �����Ƿ�
//�׷��Ƿ� ���ʷ� ���� 100�� �Ǵ� ��� ���� ����Ѵ�.
//��� �Է� ���� ���� ���� �� �� ���� Ű��ŭ�� �����鼭 Ȯ���Ѵ�.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> height;

void solution() {
	int sum = 0;
	for (int i = 0; i < 9; i++)
		sum += height[i];
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - (height[i] + height[j]) == 100) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) {}
					else printf("%d\n", height[k]);
				}
				return;
			}
		}
	}
}

int main() {
	int tmp;
	for (int i = 0; i < 9; i++) {
		cin >> tmp;
		height.push_back(tmp);
	}
	sort(height.begin(), height.end());
	solution();
	
	return 0;
}
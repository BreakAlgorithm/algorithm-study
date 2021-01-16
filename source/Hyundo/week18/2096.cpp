#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int colMax[3] = { 0 },  //���� ��(i-1) �� �ִ� ��� ����
		colMin[3] = { 0 },  //���� ��(i-1) �� �ּڰ� ��� ����
		tempMax[3] = { 0 }, //���� ��(i) �� ���� ��� ����
		tempMin[3] = { 0 }; //���� ��(i) �� ���� ��� ����

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", tempMax + j);//tempMax �Է¹��� �� ����
			tempMin[j] = tempMax[j]; //tempMin ���� �Է¹��� �� ����
			tempMax[j] += max(colMax[1], (j == 1) ? max(colMax[0], colMax[2]) : colMax[j]);
			tempMin[j] += min(colMin[1], (j == 1) ? min(colMin[0], colMin[2]) : colMin[j]);
			//j�� 0�� ��� (max or min) (S[i-1][0], S[i-1][1])
			//j�� 1�� ��� (max or min) (S[i-1][0], S[i-1][1],s[i-1][2])
			//j�� 2�� ��� (max or min) (S[i-1][1], S[i-1][2]
			//���� �ִ밪or�ּڰ��� ������ �� �ִ�.
		}
		// colMax, colMin �迭�� temp �迭�� ������Ͽ� ���� �������� ���
		memcpy(colMax, tempMax, sizeof(int) * 3);
		memcpy(colMin, tempMin, sizeof(int) * 3);
	}
	//���� ������ �ٿ� ����� MAX ���� Min ���� ����Ѵ�.
	sort(colMax, colMax + 3);
	sort(colMin, colMin + 3);
	printf("%d %d\n", colMax[2], colMin[0]);
}



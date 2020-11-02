#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 200000

using namespace std;

int N, H;
int A[MAX];//���� �ٴ� ����
int B[MAX];//������ õ�� ����
vector<int> list;

int main()
{
	cin >> N >> H;
	//������ ������ �Է�
	for (int i = 0; i < N / 2; i++) {
		cin >> A[i] >> B[i];
	}

	int mid = H / 2;
	int min = 0;

	//����
	sort(A, A + N / 2);
	sort(B, B + N / 2);

	//������ ������ ��ֹ� ���� ����
	for (int i = 1; i < H+1; i++) {
		int l = 0;
		int r = N / 2 - 1;
		int bottomCnt = 0;
		while (l <= r)
		{
			//���ĵ� ���������κ��� �̺� Ž���� ���� �μž��ϴ� ��ֹ� �� ���� ���� ���� ã��
			//ã�� ��ġ�κ��� ���� ������ �μž� �ϴ� ��ֹ��� ������ ����
			mid = (l + r) / 2;
			if (B[mid] >= i)
			{
				bottomCnt = N / 2 - mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		int topCnt = 0;
		
		l = 0;
		r = N / 2 - 1;
		while (l <= r)
		{
			//���ĵ� �������κ��� �̺� Ž���� ���� �μž��ϴ� ��ֹ� �� ���� ���� ���� ã��
			//ã�� ��ġ�κ��� ���� ������ �μž� �ϴ� ��ֹ��� ������ ����
			mid = (l + r) / 2;
			if (H-A[mid] < i)
			{
				topCnt = N / 2 - mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		//������ �������� ������ ���� ���� �������� �μž� �ϴ� ��ֹ� ���� ����
		list.push_back(topCnt + bottomCnt);
	}
	//����Ʈ ������ �ּڰ��� ��������� ����
	int res = *min_element(list.begin(), list.end());
	int num = 0;
	//����Ʈ ���� �ּڰ��� ������ ���� ã��
	for (int i = 0; i < list.size(); i++){
		if (list[i] == res)
			num++;
	}
	// �� �� ���
	cout << res<<" "<<num;

	return 0;
}
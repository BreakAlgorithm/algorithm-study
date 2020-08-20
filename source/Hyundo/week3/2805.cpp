

#include <iostream>
#include <algorithm>

using namespace std;


int solution(int* arr, int n, int m)
{
	int high = 0;
	int sum = 0;
	int k = n - 2; //�迭�� ���� ������ ���̵��� sum�� �����ٷ��� ������ �ֱ� ���� �ʿ�
	sort(arr, arr + n);							  //�迭 ����
	for (high = arr[n - 1] - 1; high >= 0; high--) { //���ĵ� �迭 �� ���� ū ���� ��������
		while (high + 1 == arr[k]) k--;			  //�� ���� �迭�� ������ ���̵���
		sum += (n - k - 1);						  //sum�� ���� ����� ����Ͽ�
		if (sum >= m) break;					  //m�� ���Ͽ� ������ �´� ��� 
	}
	return high;								  //�� ���� high�� return
}


int main()
{
	int arr[4] = { 20,15,10,17 };
	printf("\n%d\n", solution(arr, 4, 7));
	return 0;
}
#include<iostream>

using namespace std;

void CountSort(int a[], int n, int b[], int k);

int main()
{
	int arr[8] = { 5,3,4,1,5,4,1,4 };
	int ary[8] = { 0 };
	printf("���� ��\n");
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", arr[i]);
	}

	CountSort(arr, 8, ary, 5);
	printf("\n���� ��\n");

	for (int i = 0; i < 8; i++)
	{
		printf("%d ", ary[i]);
	}
	return 0;
}

void CountSort(int a[], int n, int b[], int k)
{
	int i, j;
	int* N = new int[k];

	//N �迭 �ʱ�ȭ (N[] = �������� �� ���ڰ� ��Ÿ���� Ƚ���� ���� �迭)
	for (i = 0; i < k; i++) N[i] = 0;  //O(k)

	//�� Ű�� ���� ����
	for (j = 0; j < n; j++)  N[a[j]-1] += 1;  //O(n)
	//�� Ű�� ���� �� ����
	for (i = 1; i < k; i++) N[i] += N[i - 1];  //O(k)
	//���� ����� �迭 B�� ����
	//�ڿ������� �����Ͽ� �������� ����
	for (j = n-1; j >= 0; j--) { 
		b[N[a[j]-1]-1] = a[j];
		N[a[j]-1] -= 1;
	} // O(n)
	//-> O(k)+O(n)=O(max(k,n)
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Merge(int array[], int low, int mid, int high)
{
	int B[10] = {0};
	int i, leftPtr, rightPtr, bufPtr;
	leftPtr = low;
	rightPtr = mid + 1;
	bufPtr = low;

	//���� ���ĵ� ����Ʈ�� �պ�
	while (leftPtr <= mid && rightPtr <= high)
		if (array[leftPtr] < array[rightPtr])
			B[bufPtr++] = array[leftPtr++];
		else
			B[bufPtr++] = array[rightPtr++];

	//���� ���� ����
	if (leftPtr > mid)
		for (i = rightPtr; i <= high; i++)
			B[bufPtr++] = array[i];
	else
		for (i = leftPtr; i <= mid; i++)
			B[bufPtr++] = array[i];

	//���ĵ� �ӽ� �迭�� ���� ���� �迭�� ����
	for (i = low; i <= high; i++)
		array[i] = B[i];
}

void MergeSort(int array[],int low, int high)
{
	int mid;
	if (low < high) {
		mid = (low + high) / 2; //�߰� ��ġ ����Ͽ� ����Ʈ �յ� ����
		MergeSort(array, low, mid); // ���� �κ� ����Ʈ ����
		MergeSort(array, mid + 1, high); // ���� �κ� ����Ʈ ����
		Merge(array, low, mid, high); //���ĵ� �κ� �迭 �պ�
	}
}


int main()
{
	int array[10] = { 30,20,40,35,5,10,45,50,25,15 };

	MergeSort(array,0,9);
	
	for (int j = 0; j < 10; j++)
	{
		cout << array[j] << endl;
	}
	return 0;
}


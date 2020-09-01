#include <iostream>
#include <algorithm>

int Partition(int A[], int Left, int Right);
void QuickSort(int A[], int Left, int Right);

using namespace std;

int main()
{
	int array[10] = { 30,20,40,35,5,10,45,50,25,15 };

	//������ ���� ( left = 0(�迭�� ����) , right = 9(�迭�� ��)
	QuickSort(array, 0, 9);

	//���� ��� ���
	for (int j = 0; j < 10; j++)
	{
		cout << array[j] << endl;
	}
	return 0;
}


int Partition(int A[], int left, int right)
{
	int partElem, value, temp;
	partElem = left;
	value = A[partElem];

	//left�� right�� ������ ������ �ݺ�
	do {
		//A[left]�� ���ҿ��Ұ����� ������ left�� �ݺ�������Ŵ
		do { } while (A[++left] < value);
		//A[right]�� ���ҿ��Ұ����� ũ�� right�� �ݺ����ҽ�Ŵ
		do { } while (A[--right] > value);
		//�� ���� ��ȯ
		if (left < right) swap(A[left], A[right]);
		else break;
	} while (left<right);

	//���ҿ����� �ڸ��� ã����
	A[partElem] = A[right];
	A[right] = value;

	return right;
}

void QuickSort(int A[], int left, int right)
{
	if (right > left)
	{
		int middle = Partition(A, left, right + 1);
		//���ҿ��Ҹ� �������� ���ʿ��� ������
		QuickSort(A, left, middle - 1);
		//���ҿ��Ҹ� �������� �����ʿ��� ������
		QuickSort(A, middle + 1, right);
	}
}

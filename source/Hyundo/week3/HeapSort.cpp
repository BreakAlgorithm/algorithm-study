#include<iostream>
#include<algorithm>

using namespace std;

void MakeHeap(int a[], int root, int lastNode);
void pirntHeap(int ary[], int n);

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void HeapSort(int ary[], int n){
	int i;
	//1���� �迭�� ������ ��ȯ
	// n/2 -> n/2-1 ->...-> 1
	// 4,8 -> 3,8 -> 2,8 -> 1,8
	//�迭 ��ü�� ���� ���� ������ �����ϰ� ���� ������ �Ѹ������� �� ������ �Ž��� �ö󰡸鼭
	//�Ʒ� �κк��� ���� ������ �������� ��
	//n���� ��带 ���� ���� ���� ���� n/2���� �� ��带 ����
	printf("--------1���� �迭�� ������ ��ȯ--------\n");
	for (i = n / 2; i > 0; i--) {
		MakeHeap(ary, i - 1, n - 1);
		pirntHeap(ary, 10);
	}
	printf("-----------���� ���� ���� ����-----------\n");
	//�������� �ִ밪�� �����ϰ�
	//���� ���ҵ�� �ٽ� ���� ���� (n-1)ȸ �ݺ�
	for (i = n-1 ; i > 0; i--) {
		swap(ary[0], ary[i]);
		MakeHeap(ary, 0, i - 1);
		pirntHeap(ary, 10);
	}
}

void MakeHeap(int a[], int root, int lastNode) {
	int parent, leftSon, rightSon, son, rootValue;
	parent = root;
	rootValue = a[root];//������ �Ѹ� 
	leftSon = 2 * parent + 1;
	rightSon = leftSon + 1;
	while (leftSon <= lastNode) {
		if (rightSon <= lastNode && a[leftSon] < a[rightSon])
			son = rightSon;
		else
			son = leftSon;
		if (rootValue < a[son]) {
			a[parent] = a[son];
			parent = son;
			leftSon = parent * 2 + 1;
			rightSon = leftSon + 1;
		}
		else break;
	}
	a[parent] = rootValue;
}

int main() {

	int ary[10] = { 15,4,8,11,6,3,1,6,5,17 };
	printf("--------------���� �� �迭--------------\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", ary[i]);
	}
	printf("\n");
	HeapSort(ary, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", ary[i]);
	}

	return 0;
}

void pirntHeap(int ary[],int n)
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", ary[i]);
	}
	printf("\n\n");
}
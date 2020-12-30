// ���� �ε������� ����, ������ �������� ���ӵǴ� ������ ���� �ִ밪 ���ϱ�
#include <stdio.h>
int right_max_sum(int A[], int left, int right) 
{
	if(left == right)
		return A[left];

	return (A[left] > A[left]+ right_max_sum(A, left + 1, right))? A[left] : A[left]+ right_max_sum(A, left + 1, right);
}

int left_max_sum(int A[], int left, int right) 
{
	if(left == right)
		return A[right];

	return (A[right] > A[right]+ left_max_sum(A, left, right-1))? A[right] : A[right]+ left_max_sum(A, left, right-1);
}

int main() {

	int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int max1 = right_max_sum(A, 3, 5);// A[3] = 4, A[3]+A[4] = 3, A[3]+A[4]+A[5] = 5 �߿��� �ִ밪 ��, 5
	int max2 = right_max_sum(A, 3, 4);// A[3], A[3]+A[4] �߿��� �ִ밪 ��, 4
	int max3 = right_max_sum(A, 5, 7);// �ִ밪 3

	int max4 = left_max_sum(A, 4, 6); // A[6], A[5]+A[6], A[4]+A[5]+A[6], �߿��� �ִ밪, �� 3
	int max5 = left_max_sum(A, 0, 4); // �ִ밪 3
	int max6 = left_max_sum(A, 4, 7); // �ִ밪 -2

	printf("max1 value = %d\n", max1);
	printf("max2 value = %d\n", max2);
	printf("max3 value = %d\n", max3);
	
	printf("max4 value = %d\n", max4);
	printf("max5 value = %d\n", max5);
	printf("max6 value = %d\n", max6);
}

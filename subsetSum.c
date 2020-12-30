#include <stdio.h>
int right_max_sum(int A[], int left, int right) 
{
	if(left == right)
		return A[left];

	return (A[left] > A[left] + right_max_sum(A, left + 1, right))? A[left] : A[left] + right_max_sum(A, left + 1, right);
}

int left_max_sum(int A[], int left, int right) 
{
	if(left == right)
		return A[right];

	return (A[right] > A[right] + left_max_sum(A, left, right - 1))? A[right] : A[right] + left_max_sum(A, left, right - 1);
}

int max_subarray(int *A, int left, int right) 
{
	int mid = (left + right) / 2;
	int V1, V2, V3;
	int max;

    	if(right == left)
        		return A[left];

	V1 = max_subarray(A, left, mid);
	V2 = max_subarray(A, mid + 1, right);
	V3 = left_max_sum(A, left, mid) + right_max_sum(A, mid, right) - A[mid];

	if(V1 > V2 && V1 > V3)  return V1;
    	else    return V2 > V3 ? V2 : V3;
}
int main() 
{
	int A1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // tc #1: max는 6
	int A2[] = {2, -1, 5, -2, 2, -3, 1}; // tc #2: max는 6
	int A3[] = {3, -1, 1, 2, 3, 1, -1, 5}; // tc #3: max는 13
	int A4[] = {1, 2, 3}; // tc #4: max는 6
	int A5[] = {-1, -2, -3, -4}; // tc #5: max는 -1
	int A6[] = {5}; // tc #6: max는 5
	int lastIndex, max;

	lastIndex = sizeof(A1) / sizeof(int) - 1;
	max = max_subarray(A1, 0, lastIndex);
	printf("max value1 = %d\n", max );

	lastIndex = sizeof(A2) / sizeof(int) - 1;
	max = max_subarray(A2, 0, lastIndex);
	printf("max value2 = %d\n", max );
	
	lastIndex = sizeof(A3) / sizeof(int) - 1;
	max = max_subarray(A3, 0, lastIndex);
	printf("max value3 = %d\n", max );
	
	lastIndex = sizeof(A4) / sizeof(int) - 1;
	max = max_subarray(A4, 0, lastIndex);
	printf("max value4 = %d\n", max );
	
	lastIndex = sizeof(A5) / sizeof(int) - 1;
	max = max_subarray(A5, 0, lastIndex);
	printf("max value5 = %d\n", max );
	
	lastIndex = sizeof(A6) / sizeof(int) - 1;
	max = max_subarray(A6, 0, lastIndex);
	printf("max value6 = %d\n", max );

}
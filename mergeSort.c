// mergeSort
#include <stdio.h>
int sorted[8]; // 정렬된 배열
void merge(int *data, int start, int mid, int end)
{
    int i = start;
    int j = mid+1;
    int k = start;
	int t;
    
    while(i <= mid && j <= end)
	{
        if(data[i] <= data[j])
            sorted[k] = data[i++];
		else
            sorted[k] = data[j++];

        k++;
    }

    if(i > mid)
	{
        for(t = j; t <= end; t++)
            sorted[k++] = data[t];
    }
	else
	{
        for(t = i; t <= mid; t++)
            sorted[k] = data[t];
    }
    
    for(t = start; t <= end; t++)
        data[t] = sorted[t];
} 

void merge_sort(int *data, int start, int end)
{
    if(start < end)
	{
        int mid = (start + end) / 2;
        merge_sort(data, start, mid); // 좌측 정렬 
        merge_sort(data, mid+1, end); // 우측 정렬 
        merge(data, start, mid, end);
    }
}

int main(void)
{
 
    int data[8] = {3, 6, 7, 1, 2, 4, 8, 5};
    int i;

    merge_sort(data, 0, 7);
    for(i = 0; i < 8; i++)
        printf("%d ", data[i]);
}
#include <stdio.h>
#include <stdlib.h>

//最大子序列  动规解法应该是最优的 
//时间复杂度为 O(n)

int MaxSubArray(int *arr, int len, int *s, int *e)
{
	int i; 
	int MaxSum = 0, sum = 0, MaxStart = 0, MaxEnd = 0,start = 0, end = 0;
	for(i=0; i < len; i++){
		if(sum == 0) start=i;
		sum += arr[i];
		end = i;
		if(sum < 0) {
		//前面几项之和为负数，对后面是负贡献 舍去重新统计最大和
			end = i-1;
			sum=0;
		}
		else{
			if(sum > MaxSum) {
				MaxSum = sum;
				MaxStart = start;
				MaxEnd = end;
			}
		}
	}
	*s = MaxStart;
	*e = MaxEnd;
	return MaxSum;
}

int main()
{
	int arr[] ={1, -2, 3, 5, -1, 2};
	int maxSum,start,end,i;
	maxSum = MaxSubArray(arr,  sizeof(arr) / sizeof(arr[0]), &start, &end);
	printf("%d %d\n",start,end);
	for(i=start; i <= end; i++)
		printf("%d,", arr[i]);
	printf("= %d \n", maxSum);
	return 0;
}

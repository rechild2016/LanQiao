#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
/*
给定n个十六进制正整数，输出它们对应的八进制数。
*/
char *table1[16] = { "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
						"1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };
char *table2[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };
//转二进制，一位转四位
void toBinary(char **nums, int n)
{
	int len, i, j, k, pos;
	for (i = 0; i < n; i++)
	{
		len = strlen(nums[i]);
		j = 399998;
		for (k = len - 1; k >= 0; k--)
		{
			if (nums[i][k] >= 'A' && nums[i][k] <= 'F')
				pos = nums[i][k] - 'A' + 10;
			else
				pos = nums[i][k] - '0';
			strncpy(nums[i] + j, table1[pos], 4);
			j -= 4;
		}
		j += 4;

		memset(nums[i], '0', j);
	}
}
//转八进制，三位转一位
void toOctal(char **nums, int n)
{
	int i, j, k, r, s;
	for (i = 0; i < n; i++)
	{
		j = 0;
		k = 399999;
		while (nums[i][j] == '0')
			j++;

		s = 400001;
		while (k >= j - 3)
		{
			for (r = 0; r < 8; r++)
			{
				if (strncmp(nums[i] + k, table2[r], 3) == 0)
				{
					nums[i][s--] = r + '0';
					break;
				}
			}
			k -= 3;
		}
		s++;
		while (nums[i][s] == '0') //跳过前导'0'
			s++;
		//打印
		puts(nums[i] + s);
	}
}
int main(void)
{
	//读入数据
	int n;
	scanf("%d", &n);

	char **nums = malloc(sizeof(char*)*n);
	int i;
	for (i = 0; i < n; i++)
	{
		nums[i] = malloc(sizeof(char) * 400003);
		memset(nums[i], 0, 400003);
		scanf("%s", nums[i]);
	}

	//先转二进制
	toBinary(nums, n);

	//再转八进制
	toOctal(nums, n);

	//释放内存
	for (i = 0; i < n; i++)
		free(nums[i]);
	free(nums);

	return 0;
}


/**
预处理指令
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_COLS 20	/*能处理的最大序列号*/
#define MAX_INPUT 1000 /*每个输入行的最大长度*/

/*声明函数原型*/
int read_column_numbers(int columns[], int max);
void rearrange(char *output, char const *input, int n_columns, int const columns[]);

int main(int argc, char const *argv[])
{
	/*需要处理的角标*/
	int n_columns;
	/*需要处理的文案*/
	int columns[MAX_COLS];
	/*输入的文案*/
	char input[MAX_INPUT];
	/*输出的文案*/
	char output[MAX_INPUT];

	n_columns = read_column_numbers(columns, MAX_COLS);

	/*获取输入的字符串，并写入input数组中，当换行即尾部是NULL的时候结束*/
	while (gets(input) != NULL)
	{ //当我们还可以输入另一行的时候
		printf("Original input: %s\n", input);

		rearrange(output, input, n_columns, columns);

		printf("rearranged line : %s\n", input);
	}
	return EXIT_SUCCESS;
}

/**
 * 读取列标号，如果超出范围不理会
 */
int read_column_numbers(int columns[], int max)
{
	int num = 0;
	int ch;
	/**这个逻辑对于入门还是很不友善的
	*1.判断是否超过了最大值
	*2.将输入的值存储 scanf("%d", &columns[num]) == 1 代表读取转换成功
	*3.输入的值必须大于0
	*/
	while (num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0)
	{
		num += 1;
	}

	/**
	 * 确认读取的脚本号是偶数个
	 */
	if (num >> 1 != 0)
	{
		//标准输出
		puts("Last column number is not paired");
		//终止程序
		exit(EXIT_FAILURE);
	}
	/**
	 * 丢弃该行中包含最后一个数字的那部分内容
	 */
	// while ((ch=getchar())!=EOF && ch!='\n')
	// ;

	ch = getchar();
	while (ch != EOF && ch != '\n')
	{
		ch = getchar();
	}

	return num;
}
/**
 * 处理输入行
 */
void rearrange(char *output, char const *input, int n_columns, int const columns[])
{
	int col;		/* columns数组的下标*/
	int output_col; /*输出列表计算器*/
	int len;		/*输入行的长度*/

	len = strlen(input);
	output_col = 0;
	for (col = 0; col < n_columns; col += 2)
	{
		int nchars = columns[col + 1] - columns[col] + 1;

		if (columns[col] >= len || output_col == MAX_INPUT - 1)
			break;
		if (output_col + nchars > MAX_INPUT - 1)
		{
			nchars = MAX_INPUT - output_col - 1;
			strncpy(output + output_col, input + columns[col], nchars);
			output_col += nchars;
		}
		output[output_col] = '\0';
	}
}



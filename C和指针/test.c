
#include <stdio.h>
#define MAX 101

int main(int argc, char const *argv[])
{

    // int a = 0;
    // while (a < 5)
    // {
    //     a++;
    //     if (a == 4)
    //     {
    //         continue;
    //     }
    //     printf("num is %d \n", a);
    // }

    // for (int i = 1; i < 5; i++)
    // {
    //     if (i == 3)
    //     {
    //         continue;
    //     }
    //     printf(" %d \n", i);
    // }

    // do
    // {
    //     /* code */
    // } while (/* condition */);

    // switch (expression)
    // {
    // case /* constant-expression */:
    //     /* code */
    //     break;
    // case /* constant-expression */:
    //     /* code */
    //     break;
    // default:
    //     break;
    // }
    //     int i = 0;
    // outer_next:
    //     if (i > 2)
    //     {
    //         printf("(i > 2)  %d \n", i);
    //         goto outer_end;
    //     }
    //     i++;
    //     if (i < 4)
    //     {
    //         printf("(i < 4)  %d \n", i);
    //         goto outer_next;
    //     }
    // outer_end:
    //     printf(" outer_end");

    // for (int i = 0; i < 10; i += 1)
    // {
    //     printf("%d \n", i);
    // }

    // int num;
    // scanf("请输入空格行数 %d", &num);
    // while (num >= 0)
    // {
    //     printf("\n");
    //     num--;
    // }

    // int year;
    // int leap_year;
    // scanf("请输入年份 %d", &year);
    // if (year % 400 == 0)
    // {
    //     leap_year = 1;
    // }
    // else if (year % 100 == 0)
    // {
    //     leap_year = 0;
    // }
    // else if (year % 4 == 0)
    // {
    //     leap_year = 1;
    // }
    // else
    // {
    //     leap_year = 0;
    // }
    // if (leap_year)
    // {
    //     printf(" 是闰年 \n");
    // }
    // else
    // {
    //     printf(" 不是是闰年 \n");
    // }

    int n[MAX];
    int i, j;

    for (i = 1; i < MAX; i++)
    {
        n[i] = 1;
    }

    n[1] = 0;
    n[2] = 1;
    for (i = 2; i < MAX; i++)
    {
        if (n[i] == 1)
        {
            //能被它本身整除 比如从2的倍数开始 4 6 8...肯定不是质数
            for (j = i + i; j < MAX; j += i)
            {
                n[j] = 0;
            }
        }
    }
    for (i = 1; i < MAX; i++)
    {
        if (n[i] != 0)
        {
            printf(" %d \n", i);
        }
    }

    return 0;
}

/*
从一个字符串中去除多余的空格
“当函数发现字符串中如果有一个地方由一个或多个连续的空格组成，就把它们改成单个空格字符。”
*/
void deblank(char string[])
{
    int i, j;
    int flag = 0;
    for (i = 0; string[i] != '\0'; i++)
    {
        while (string[i] == ' ' && flag == 1)
        {
            /*
            后面往前移动
             */
            for (j = i; i < string[j] != '\0'; j++)
            {
                string[j] = string[j + 1];
            }
            //当你遍历整个字符串时要确保它以NUL字符结尾。
            string[j] = '\0';
        }

        if (string[i] == ' ')
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
    }
}


#include <stdio.h>

int caseOne();
size_t my_strlen(char *string);
int main(int argc, char const *argv[])
{
    char input[] = "this is a test";
    int result = my_strlen(&input[0]);
    printf("string length is %d \n",result);
    return 0;
}

int caseOne()
{
    int a = 112;
    int b = -1;
    float c = 3.14;
    int *d = &a;
    /*
     d是个(int *)类型的指针，d里面存放的是a的地址。
    *是：间接访问操作符。所以 *d 是代表着 访问了b代表的地址。 其实就是a的地址。所以访问到的值就是a地址上存放的数值
    所以：*d = a =112;
      */
    printf("d is %p \n", d);
    printf("a 的地址是  %p \n", &a);
    printf("*d is %d \n", *d);
    printf("a is %d \n", a);
    float *e = &c;
    return 0;
}

/**
 * 计算字符串长度
 */
size_t my_strlen(char *string)
{
    int length = 0;
    while (*string++ != '\0')
    {
        length++;
    }

    return length;
}

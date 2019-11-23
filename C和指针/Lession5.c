
#include <stdio.h>


int count_one_bits(unsigned value);

int main(int argc, char const *argv[])
{

    count_one_bits(0110011);
    return 0;
}

/**
 *计算一个无符号值中为1的位的个数。 
 *传入值应该为 2进制 
 */
int count_one_bits(unsigned value){

    int ones;

    for ( ones = 0; value!=0 ; value=value >> 1)
    {
        //一个数用2取模不是不是0，就是1 
        if (value%2!=0)/* 当前最低位是1 */
        {
            ones++;
        }
        
    }
    
    printf(" %d \n",ones);
    return ones;
}
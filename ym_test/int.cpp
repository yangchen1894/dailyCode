#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char* argv[]) {
    std::string a = argv[1];
    const char *sValue = a.c_str();
    char *pEnd;
//    long value = strtol(sValue, &pEnd, 10);
    /* // long long value = (long long)strtoll(sValue, &pEnd, 10); */
    uint32_t value = strtoul(sValue, &pEnd, 10);
    /* // 检查是否转换成功 */
  /* if (pEnd == sValue) { */
    /*     printf("没有转换任何数字\n"); */
    /*     return 1; */
    /* } */

    /* // 检查是否溢出 */
    /* if (value < INT_MIN || value > INT_MAX) { */
    /*     printf("转换结果超出 int 的范围\n"); */
    /*     return 1; */
    //}

    //int i = (int)value;
    std::cout << "转换结果" << value << std::endl;
    return 0;
}


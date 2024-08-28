#include <stdio.h>

char *MyStrcpy(char *destination, const char *source)
{
    char *start = destination; // 保存目标字符串的起始地址

    while (*source != '\0')
    {                           // 只要源字符串的当前字符不为 '\0'，就继续复制
        *destination = *source; // 将源字符串的当前字符复制到目标字符串的当前字符
        destination++;          // 移动到下一个位置
        source++;               // 移动到下一个源字符串位置
    }

    *destination = '\0'; // 在目标字符串的最后添加 '\0' 表示字符串结束
    return start;        // 返回目标字符串的起始地址
}

int main()
{
    char source[] = "Hello, World!";
    char destination[20];

    MyStrcpy(destination, source);
    printf("Copied string: %s\n", destination);

    return 0;
}
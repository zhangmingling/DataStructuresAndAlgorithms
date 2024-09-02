#include <stdio.h>

char *MyStrcpy(char *dest, const char *src)
{
    char *start = dest; // 保存目标字符串的起始地址

    while (*src != '\0') // 只要源字符串的当前字符不为 '\0'，就继续复制
    {
        *dest = *src; // 将源字符串的当前字符复制到目标字符串的当前字符
        dest++;       // 移动到下一个位置
        src++;        // 移动到下一个源字符串位置
    }

    *dest = '\0'; // 在目标字符串的最后添加 '\0' 表示字符串结束
    return start; // 返回目标字符串的起始地址
}

int main()
{
    char src[] = "Hello, World!";
    char dest[20];

    MyStrcpy(dest, src);
    printf("Copied string: %s\n", dest);

    return 0;
}
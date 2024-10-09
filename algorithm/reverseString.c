#include <stdio.h>
#include <string.h>

// 定义函数用于翻转字符串
void reverseString(char *str) {
    int len = strlen(str); // 获取字符串长度
    int i;
    char temp;
    
    // 使用双指针法交换字符
    for (i = 0; i < len / 2; i++) {
        temp = str[i]; // 暂存前面的字符
        str[i] = str[len - i - 1]; // 将末尾的字符移到前面
        str[len - i - 1] = temp; // 将暂存的字符移到末尾
    }
}

int main() {
    char str[] = "123456"; // 定义字符串
    reverseString(str); // 调用函数翻转字符串
    printf("翻转后的字符串: %s\n", str); // 输出结果
    return 0;
}

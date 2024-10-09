#include <stdio.h>

// 定义函数计算最小翻转次数
int minFlips(int A[], int N) {
    int flipCount1 = 0; // 记录变为模式1的翻转次数
    int flipCount2 = 0; // 记录变为模式2的翻转次数
    
    // 遍历硬币序列，计算两种模式的翻转次数
    for (int i = 0; i < N; i++) {
        // 模式1：期望偶数位为1，奇数位为0
        if (i % 2 == 0) {
            if (A[i] != 1) flipCount1++; // 期望1但实际不是，需翻转
        } else {
            if (A[i] != 0) flipCount1++; // 期望0但实际不是，需翻转
        }
        
        // 模式2：期望偶数位为0，奇数位为1
        if (i % 2 == 0) {
            if (A[i] != 0) flipCount2++; // 期望0但实际不是，需翻转
        } else {
            if (A[i] != 1) flipCount2++; // 期望1但实际不是，需翻转
        }
    }
    
    // 返回两种模式中需要翻转次数较小的那个
    return flipCount1 < flipCount2 ? flipCount1 : flipCount2;
}

int main() {
    // 测试用例1
    int A1[] = {1, 0, 1, 0, 1, 1};
    int N1 = sizeof(A1) / sizeof(A1[0]);
    printf("最小翻转次数: %d\n", minFlips(A1, N1)); // 输出 1

    // 测试用例2
    int A2[] = {1, 1, 0, 1, 1};
    int N2 = sizeof(A2) / sizeof(A2[0]);
    printf("最小翻转次数: %d\n", minFlips(A2, N2)); // 输出 2

    // 测试用例3
    int A3[] = {0, 1, 0};
    int N3 = sizeof(A3) / sizeof(A3[0]);
    printf("最小翻转次数: %d\n", minFlips(A3, N3)); // 输出 0

    // 测试用例4
    int A4[] = {0, 1, 1, 0};
    int N4 = sizeof(A4) / sizeof(A4[0]);
    printf("最小翻转次数: %d\n", minFlips(A4, N4)); // 输出 2

    return 0;
}

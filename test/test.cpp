#include <iostream>

using namespace std;

int main() {
    int num;
    cout << "请输入一个四位数: ";
    cin >> num;

    // 确保输入是四位数
    if (num < 1000 || num > 9999) {
        cout << "请输入一个有效的四位数！" << endl;
        return 1;
    }

    // 分别提取四位数字
    int d1 = (num / 1000) % 10; // 第一位
    int d2 = (num / 100) % 10;  // 第二位
    int d3 = (num / 10) % 10;   // 第三位
    int d4 = num % 10;          // 第四位

    // 1. 每一位加5并取余10
    d1 = (d1 + 5) % 10;
    d2 = (d2 + 5) % 10;
    d3 = (d3 + 5) % 10;
    d4 = (d4 + 5) % 10;

    // 2. 互换位置
    // 第1位和第4位互换，第二位和第三位互换
    int temp = d1;
    d1 = d4;
    d4 = temp;

    temp = d2;
    d2 = d3;
    d3 = temp;

    // 3. 合并为整数输出
    int encrypted_num = d1 * 1000 + d2 * 100 + d3 * 10 + d4;

    // 输出加密后的结果
    cout << "加密后的结果是: " << encrypted_num << endl;

    return 0;
}
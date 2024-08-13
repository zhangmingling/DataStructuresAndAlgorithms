#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // 用于 usleep 函数

// 全局变量，需要被两个线程访问
int global_variable = 1; // 初始值大于0

// 线程函数，用于每隔300ms自加变量
void *increment_thread(void *arg)
{
    while (1)
    {
        usleep(300000); // 300ms，注意单位是微秒
        global_variable++;
    }
    return NULL;
}

// 线程函数，用于检查并打印能被3整除的变量值
void *check_and_print_thread(void *arg)
{
    while (1)
    {
        if (global_variable % 3 == 0)
        {
            printf("The variable value %d is divisible by 3\n", global_variable);
        }
        usleep(100000); // 每隔100ms检查一次，注意单位是微秒
    }
    return NULL;
}

// int main()
// {
//     pthread_t thread1, thread2;

//     // 创建线程1，用于自加变量
//     pthread_create(&thread1, NULL, increment_thread, NULL);

//     // 创建线程2，用于检查并打印能被3整除的变量值
//     pthread_create(&thread2, NULL, check_and_print_thread, NULL);

//     // 主线程等待两个线程结束
//     pthread_join(thread1, NULL);
//     pthread_join(thread2, NULL);

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// 链表节点结构
struct list_node_t
{
    void *p_before;     // 上一级节点
    void *p_next;       // 下一级节点
    void *p_data;       // 存储数据的节点
    uint32_t data_size; // 存储数据大小
};

// @brief 插入一个数据至 list 尾部，该函数内部自己申请 list 节点
// @param p_list_head 链表头指针
// @param data 存储的数据指针
// @param data_size 存储的数据大小
// @return 0: 正确 -2: 传入指针为空错误 -1: 内存申请错误

// 插入数据到链表尾部
int insert_data_to_list(void *p_list, const void *data, uint32_t data_size)
{
    if (p_list == NULL || data == NULL)
    {
        return -2; // 传入指针为空错误
    }

    struct list_node_t *new_node = (struct list_node_t *)malloc(sizeof(struct list_node_t));
    if (new_node == NULL)
    {
        return -1; // 内存申请错误
    }

    new_node->p_data = malloc(data_size);
    if (new_node->p_data == NULL)
    {
        free(new_node);
        return -1; // 内存申请错误
    }
    memcpy(new_node->p_data, data, data_size);
    new_node->data_size = data_size;

    struct list_node_t *current = (struct list_node_t *)p_list;
    while (current->p_next != NULL)
    {
        current = (struct list_node_t *)current->p_next;
    }

    current->p_next = new_node;
    new_node->p_before = current;
    new_node->p_next = NULL;

    return 0; // 正确
}

// 删除链表中的节点并释放其空间
int delete_list_node(void *p_node)
{
    if (p_node == NULL)
    {
        return -2; // 传入指针为空错误
    }

    struct list_node_t *node = (struct list_node_t *)p_node;
    if (node->p_before != NULL)
    {
        ((struct list_node_t *)node->p_before)->p_next = node->p_next;
    }
    if (node->p_next != NULL)
    {
        ((struct list_node_t *)node->p_next)->p_before = node->p_before;
    }

    free(node->p_data);
    free(node);

    return 0; // 正确
}

int print_list(void *p_list)
{
    if (p_list == NULL)
    {
        printf("p_list is NULL\n");
        return -2;
    }

    struct list_node_t *temp;
    temp = (struct list_node_t *)p_list;
    while (temp->p_next != NULL)
    {
        printf("%s ", (char *)(((struct list_node_t *)(temp->p_next))->p_data));
        temp = temp->p_next;
    }
    puts("");
    return 0;
}

int main()
{
    // 创建链表头节点
    struct list_node_t list_head;

    // 插入数据到链表
    const char *data1 = "hello";
    insert_data_to_list(&list_head, data1, strlen(data1) + 1);

    const char *data2 = "new";
    insert_data_to_list(&list_head, data2, strlen(data2) + 1);

    const char *data3 = "world";
    insert_data_to_list(&list_head, data3, strlen(data3) + 1);

    // 打印链表
    print_list(&list_head);

    // 删除第二个节点
    delete_list_node(list_head.p_next);

    // 打印链表
    print_list(&list_head);

    return 0;
}
#include "sequeue.h"

int main(int argc, const int *argv[])
{
    sequeue *sq;
    sq = queue_create();
    if (sq == NULL)
    {
        return -1;
    }
    enqueue(sq, 10);
    enqueue(sq, 20);
    enqueue(sq, 30);

    while (!queue_empty(sq))
    {
        printf("dequeue: %d\n", dequeue(sq));
    }

    queue_free(sq);

    return 0;
}
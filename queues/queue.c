#include "queue.h"
#include "../lists/list.h"
#include "../lists/list.c"

Queue *queue_create()
{
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->list = database_create();
    return queue;
}
void queue_push(Queue *queue, char *data)
{
    database_insert(queue->list, data, queue->list->amount);
}
char *queue_pop(Queue *queue)
{
    char *temp = queue->list->head->data;
    database_delete(queue->list, 0);
    return temp;
}
int queue_len(Queue *queue)
{
    int size = queue->list->amount;
    return size;
}
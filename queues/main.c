#include "../lists/list.h"
#include "../lists/list.c"

ListBase *queue_create()
{
    ListBase *queue = database_create();
    return queue;
}
void queue_push(ListBase *queue, char *data)
{
    database_insert(queue, data, queue->amount);
}
char *queue_pop(ListBase *queue)
{
    if(queue->amount)
    {
        char *temp = queue->head->data;
        database_delete(queue, 0);
        return temp;
    }
    return NULL;
}
int queue_len(ListBase *queue)
{
    int size = queue->amount;
    return size;
}

int main()
{
    ListBase *queue = queue_create();
    queue_push(queue, "test");
    queue_push(queue, "blast");
    queue_push(queue, "boost");
    queue_push(queue, "beeb");
    printf("%s", queue_pop(queue));
    printf("%s", queue_pop(queue));
    printf("%s", queue_pop(queue));
    printf("%i", queue_len(queue));

}
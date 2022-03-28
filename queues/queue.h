#ifndef QUEUE_H
#define QUEUE_H
#include "../lists/list.h"

typedef struct Queue
{
    ListBase *list;
} Queue;

Queue *queue_create();
void queue_push(Queue *queue, char *data); 
char* queue_pop(Queue *queue);
int queue_len(Queue *queue) 
#endif
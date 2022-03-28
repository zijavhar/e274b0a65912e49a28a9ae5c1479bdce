#include "../lists/list.h"
#include "../lists/list.c"

ListBase *stack_create()
{
    ListBase *stack = database_create();
    return stack;
}

void robot_put(ListBase *stack, char *data)
{
    database_insert(stack, data, 0);
}

char *robot_pop(ListBase *stack)
{
    if(stack->amount)
    {
        char *temp = stack->head->data;
        database_delete(stack, 0);
        return temp;
    }
    return NULL;
}

int robot_len(ListBase *stack)
{
    return stack->amount;
}

int main()
{
    ListBase *stack = stack_create();
    robot_put(stack, "abc");
    robot_put(stack, "yryd");
    robot_put(stack, "testt");    
    printf("%s", robot_pop(stack));
    printf("%s", robot_pop(stack));
    printf("%s", robot_pop(stack));
    printf("%s", robot_pop(stack));
    printf("%i", robot_len(stack));

}
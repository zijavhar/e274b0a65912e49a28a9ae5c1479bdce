#ifndef LIST_H
#define LIST_H

typedef struct ListItem
{
    char *data;
    struct ListItem *next;
    struct ListItem *prev;
} ListItem;

typedef struct ListBase
{
    ListItem *head;
    ListItem *tail;
    int amount;
} ListBase;

ListBase *database_create();
int database_insert(ListBase *db, char *data, int index);
char *database_read(ListBase *db, int index);
int database_search(ListBase *db, char *data);
int database_delete(ListBase *db, int index);

#endif
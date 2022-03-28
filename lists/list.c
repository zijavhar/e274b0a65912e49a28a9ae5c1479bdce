#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// creates a list with initial item(head)
ListBase *database_create()
{
   ListBase *db = (ListBase*) malloc(sizeof(ListBase));
   db->head = NULL;
   db->tail = NULL;
   db->amount = 0;

   return db; 
};
// insert into list
int database_insert(ListBase *db, char *data, int index)
{
    ListItem *temp_item = (ListItem*) malloc(sizeof(ListItem));
    int k = 0;
    char *p = data;
    while (*data) {
        k++;
        data++;
    }
    char *temp_data = (char*) malloc(sizeof(k * sizeof(char))); 
    temp_data = p;

    temp_item->data = temp_data;
    temp_item->next = NULL;
    temp_item->prev = NULL;
    // first time insertion
    if (db->head == NULL)
    {
        db->head = temp_item;
        db->tail = temp_item;
        db->amount++;
        return 0;
    }
    // zero index
    if (index <= 0)
    {
        temp_item->next = db->head;
        db->head = temp_item;
        db->amount++;
        return 0;
    }
    // if index is greater then we insert it at the end of the list
    if (index >= db->amount) {
        ListItem *temp_tail = db->tail;
        temp_item->prev = temp_tail;
        temp_tail->next = temp_item;
        db->tail = temp_item;
        db->amount++;
        return 0;
    }

    // otherwise loop to find the index
    ListItem *curr = db->head;
    int i = 0;

    while (i != index) {
        curr = curr->next;
        i++;
    }
    temp_item->next = curr->next;
    temp_item->prev = curr;
    curr->next = temp_item;
    db->amount++;
    return 0;
};
// ouputs whole list
void list_out(ListBase *db)
{
    ListItem *t = db->head; 
    int index = 0;
    printf(" the size of list: %i \n", db->amount);
    while(t)
    {
        printf("| value: %s index: %i | \n", t->data, index); 
        t = t->next;
        index++;
    }
}
// returns the data of listitem by index
char *database_read(ListBase *db, int index)
{
    ListItem *temp = db->head;
    int i = 0;
    while (temp) {
        if (i == index) {
            return temp->data;
        }
        temp = temp->next;
        i++;
    }
    return NULL;
};
// go through list to find the data
int database_search(ListBase *db, char *data)
{
    ListItem *temp = db->head;
    int i = 0;
    while (temp) {
        if(strcmp(temp->data, data) == 0) {
            return i;
        }
        temp = temp->next;
        i++;
    }
    return -1;
};
// delete the item by index
int database_delete(ListBase *db, int index)
{
    ListItem *temp = db->head;
    int i = 0;
    // begining of the list
    if (index == 0) {
        db->head = db->head->next;
        free(temp);
        db->amount--;
        return 0;
    }
    // end of the list
    if (index == db->amount) {
        ListItem *tail = db->tail;
        db->tail = db->tail->prev;
        free(tail);
        db->amount--;
        return 0;
    }
    // otherwise
    while (temp)
    {
        if (i == index) {
            temp->prev->next = temp->next;
            free(temp);
            return 0;
        }
        temp = temp->next;
        i++;
    }
    db->amount--;
    return 1;
    
};


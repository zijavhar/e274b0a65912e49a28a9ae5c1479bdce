#include "list.h"
#include "list.c"

int main()
{
    ListBase *db = database_create();
    database_insert(db, "a", 0);
    database_insert(db, "b", 1);
    database_insert(db, "c", 2);
    database_insert(db, "d", 3);
    char *t = database_read(db, 0);
    int p = database_search(db, "a");
    int d = database_delete(db, 3);
    list_out(db);
    printf("%i", p);
}
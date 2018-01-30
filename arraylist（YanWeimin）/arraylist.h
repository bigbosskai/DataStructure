#ifndef _ARRAY_LIST
#define _ARRAY_LIST

#define LIST_INIT_SIZE 100
#define LISTINCR 10
#define ERROR 1
#define OK 0
typedef char elemtype;
typedef struct _t
{
    elemtype *elem;
    int length;
    int listsize;
}arraylist;
int initlist_sq(struct _t *l);
int listinsert_sq(struct _t *l,int i,elemtype e);
int listdelete_sq(struct _t *l,int i,elemtype *e);
int locateelem_sq(struct _t *l,elemtype e,int(*compare)(elemtype,elemtype));//return 1 is the first elem ;
void  mergelist_sq(struct _t *l1,struct _t *l2,struct _t *l3);

#endif
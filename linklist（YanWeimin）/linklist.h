#ifndef _LINK_LIST
#define _LINK_LIST
#define ERROR 1
#define OK 0
typedef char elemtype;
typedef struct _t
{
	elemtype data;
	struct _t *next;
}lnode,*linklist;

int listgetelem_l(struct _t *l,int i,elemtype *el);
int listinsert_l(struct _t *l,int i,elemtype e);
int listdelete_l(struct _t *l,int i,elemtype *e);
void initlist_l(struct _t **l);
int listgetlength(struct _t *l);
void mergelist_l(struct _t *l1,struct _t *l2,struct _t *l3);
void print(struct _t *l); 
#endif

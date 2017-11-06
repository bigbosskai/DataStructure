#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

 int initlist_sq(struct _t *l)
{
    l->elem=(elemtype*)malloc(sizeof(elemtype)*LIST_INIT_SIZE);
    if(!l->elem)
    {
        return ERROR;
    }
    l->length=0;
    l->listsize=LIST_INIT_SIZE;
    return OK;
}
int listinsert_sq(struct _t *l,int i,elemtype e)
{
    elemtype *newbase;
    elemtype *p,*q;
    if(i<1 || i>l->length+1){
        return ERROR;
    }
    if(l->length>l->listsize)
    {
        newbase=(elemtype*)realloc(l->elem,(l->listsize+LISTINCR)*(sizeof(elemtype)));
        if(!newbase)
        {
            exit(0);
        }
        l->elem=newbase;
        l->listsize+=LISTINCR;
    }
    p=&l->elem[i-1];
    for(q=&l->elem[l->length-1];q>=p;q--)
    {
        *(q+1)=*q;
    }
    *p=e;
    l->length++;
    return OK;

}
int listdelete_sq(struct _t *l,int i,elemtype *e)
{
    elemtype *q,*p;
    if((i<1)||(i>l->length))
    {
        return ERROR;
    }
    q=l->elem+i-1;
    *e=l->elem[i-1];
    for(p=&l->elem[l->length-1];q<=p;q++)
    {
        *q=*(q+1);
    }
    l->length--;
    return OK;
}
int locateelem_sq(struct _t *l,elemtype e,int(*compare)(elemtype,elemtype))//return 1 is the first elem 
{
	int i=1;
	elemtype *p=l->elem;
	while(i<=l->length && !(*compare)(*p,e)){
	p++;
	i++;
	}
	if(i<=l->length) 
	{
		return i;
	}//return i;
	else return 0;
}
void  mergelist_sq(struct _t *l1,struct _t *l2,struct _t *l3)
{
	elemtype *pa,*pb,*pa_last,*pb_last,*pc;
	if(!l1 || !l2 || !l3) return;
	pa=l1->elem;
	pb=l2->elem;
	pa_last=pa+l1->length-1;
	pb_last=pb+l2->length-1;
	l3->listsize=l3->length=l1->length+l2->length;
	pc=l3->elem=(elemtype*)malloc(sizeof(elemtype)*l3->listsize);
	if(!l3->elem) exit(1);
	while(pa<=pa_last&&pb<=pb_last)
	{
		if(*pa<*pb)
		{
			*pc++=*pa++;//先取指针所值的值在指针++ 
		}
		else{
			*pc++=*pb++;
		}
	}
	while(pa<=pa_last){*pc++=*pa++;}
	while(pb<=pb_last){*pc++=*pb++;}
}


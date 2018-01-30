#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
int listgetelem_l(struct _t *l,int i,elemtype *el)
{
	//l has no data head
	//el is ith node data
	linklist p;
	int j=1;
	if(!l) return ERROR;
	p=l->next;
	while(p&&i<j)
	{
		p=p->next;
		j++;
	}
	if(!p||j>i) return ERROR;
	*el=p->data;
	return OK;
}
int listinsert_l(struct _t *l,int i,elemtype e)
{
	//delete ith node 1<=i<=len(node)
	linklist p;
	linklist node;
	int j=0;
	p=l;
	while(p&& j<i-1)
	{
		p=p->next;
		j++;
	}
	if(!p||j>i-1) return ERROR;
	node=(struct _t*)malloc(sizeof(struct _t));
	node->data=e;
	node->next=p->next;
	p->next=node;
	return OK;
}//list_insert
int listdelete_l(struct _t *l,int i,elemtype *e)
{
	//l has head 
	//delete ith node
	linklist p=l,q;
	int j=0;
	while(p->next&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(!(p->next)||j>i-1) return ERROR;
	q=p->next;
	p->next=q->next;
	*e=q->data;
	free(q);
	return OK;
}
void initlist_l(struct _t **l)
{
	*l=(linklist)malloc(sizeof(struct _t));
	(*l)->next=NULL;
	if(!(*l)) exit(1);
	return ;
}
int listgetlength(struct _t *l)
{
	int i=-1;
	linklist p=l;
	while(p)
	{
		i++;
		p=p->next;
	}
	return i;//return len(node)
}
void mergelist_l(struct _t *l1,struct _t *l2,struct _t *l3)
{
	//malloc l3's nodes
	//nondecreasing l1 and l2
	struct _t *node,*remaining;
	struct _t *pa=l1->next;
	struct _t *pb=l2->next;
	struct _t *pc=l3;
	if(!l1||!l2||!l3) return;
	while(pa&&pb)
	{
		node=(linklist)malloc(sizeof(struct _t));
		if(!node){
			printf("malloc failure!\n");
			exit(1);
		}
		if(pa->data <= pb->data)
		{
			node->next=pc->next;
			node->data=pa->data;
			pc->next=node;
			pa=pa->next;
			pc=node;
		}
		else
		{
			node->next=pc->next;
			node->data=pb->data;
			pc->next=node;
			pb=pb->next;
			pc=node;
		}
	}
	while(pa)
	{
		node=(struct _t*)malloc(sizeof(struct _t));
		if(!node) exit(1);
		node->next=pc->next;
		node->data=pa->data;
		pc->next=node;
		pa=pa->next;
		pc=node;
	}
	while(pb)
	{
		node=(struct _t*)malloc(sizeof(struct _t));
		if(!node) printf("malloc failure!\n");
		node->next=pc->next;
		node->data=pb->data;
		pc->next=node;
		pb=pb->next;
		pc=node;
	}	
}
void print(struct _t *l)
{
	linklist pa=l->next;
	while(pa)
	{
		printf("%c",pa->data);
		pa=pa->next;
	}
	printf("\n");
	return;
}
 

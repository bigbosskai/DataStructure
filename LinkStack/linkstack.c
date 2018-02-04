#include<stdio.h>
#include"linkstack.h"
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
/////////////////////////////////////////////////LinkList////////////////////////////////////////////////////////
typedef void LinkList;
/*
typedef struct _tag_LinkListNode LinkListNode;
struct _tag_LinkListNode
{
	LinkListNode* next;
};
*/
typedef struct _tag_LinkListNode
{
	struct _tag_LinkListNode* next;
}LinkListNode;

LinkList* LinkList_Create();

void LinkList_Destroy(LinkList* list);

void LinkList_Clear(LinkList* list);

int LinkList_Length(LinkList* list);

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);

LinkListNode* LinkList_Get(LinkList* list, int pos);

LinkListNode* LinkList_Delete(LinkList* list, int pos);


typedef struct _tag_LinkList{
	//这个句柄里面，需要保存所有节点的信息。需要有一个起始点
	LinkListNode header;
	int length;
}TLinkList;


LinkList* LinkList_Create(){
	TLinkList *ret=(TLinkList*)malloc(sizeof(TLinkList));
	if(ret==NULL){
		return NULL;
	}
	memset(ret,0,sizeof(TLinkList));

	ret->header.next=NULL;
	ret->length=0;
	return ret;
}

void LinkList_Destroy(LinkList* list){
	if(list==NULL){
		return;
	}
	free(list);
	return;
}


void LinkList_Clear(LinkList* list){
	TLinkList *tlist=(TLinkList*)list;
	if(list==NULL){
		return;
	}
	tlist->length=0;
	tlist->header.next=NULL;
	return;
}


int LinkList_Length(LinkList* list){
	TLinkList *tlist=(TLinkList*)list;
	if(tlist==NULL){
		return -1 ;
	}
	return tlist->length;
}


int LinkList_Insert(LinkList* list, LinkListNode* node, int pos){
	//pos
	TLinkList *tlist=NULL;
	LinkListNode * current=NULL;
	int i;
	if(list==NULL || node==NULL){
		return -1;
	}
	tlist=(TLinkList*)list;
	//指向头结点
	current=&tlist->header;
	//node->next = current->next;
	//current->next = node;
	for(i=0;i<pos&&(current->next!=NULL); i++){
		current=current->next;
	}
	node->next = current->next;
	current->next = node;
	tlist->length++;
	return 0;
}


LinkListNode* LinkList_Get(LinkList* list, int pos){
	TLinkList *tlist=NULL;
	LinkListNode * current=NULL;
	LinkListNode *ret=NULL;
	int i;
	tlist=(TLinkList*)list;
	//这里tlist->length-1也可以
	if(list==NULL||pos<0||pos>(tlist->length-1)){
		return NULL;
	}
	//指向头结点
	current=&tlist->header;
	//node->next = current->next;
	//current->next = node;
	for(i=0;i<pos&&(current->next!=NULL); i++){
		current=current->next;
	}
	ret = current->next;
	return ret;
}


LinkListNode* LinkList_Delete(LinkList* list, int pos){
	TLinkList *tlist=NULL;
	LinkListNode * current=NULL;
	LinkListNode *ret=NULL;
	int i;
	tlist=(TLinkList*)list;
	if(list==NULL||pos<0||pos>tlist->length-1){
		return NULL;
	}
	//指向头结点
	current=&tlist->header;
	//node->next = current->next;
	//current->next = node;
	for(i=0;i<pos&&(current->next!=NULL); i++){
		current=current->next;
	}
	ret = current->next;
	current->next = ret->next;
	tlist->length--;
	return ret;
}


///////////////////////////////////////////////LinkList///////////////////////////////////////////////////////////

typedef struct _tag_LinkStack_Node{
    LinkListNode node;
    void *elem;
}TLSNode;


LinkStack* LinkStack_Create(){
    return LinkList_Create();
}

void LinkStack_Destroy(LinkStack* stack){
    //
    LinkStack_Clear(stack);
    LinkList_Destroy(stack);
    return ;
}

void LinkStack_Clear(LinkStack* stack){
    //
    while( LinkStack_Size(stack)>0 ){
        LinkStack_Pop(stack);
    }
    return ;
}


int LinkStack_Push(LinkStack* stack, void* item){
    TLSNode * ptls = (TLSNode*)malloc(sizeof(TLSNode));
    int ret = -1;
    if(!ptls){
        return -1;
    }
    ptls->elem = item;
    ret = LinkList_Insert(stack, &ptls->node,0);
    return ret;
}


void* LinkStack_Pop(LinkStack* stack){
    TLSNode * ptls = NULL;
    void *myitem;
    ptls = (TLSNode*)LinkList_Delete(stack,0);
    if(ptls==NULL){
        return NULL;
    }
    myitem = ptls->elem;
    if(ptls!=NULL){
        free(ptls);
    }
    return myitem;
}


void* LinkStack_Top(LinkStack* stack){
    void *myitem;
    TLSNode * ptls = NULL;
    ptls = (TLSNode*)LinkList_Get(stack,0);
    if(ptls==NULL){
        return NULL;
    }
    myitem = ptls->elem;
    return myitem;
}


int LinkStack_Size(LinkStack* stack){
    return LinkList_Length(stack);
}


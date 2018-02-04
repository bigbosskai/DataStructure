#include<stdio.h>
#include<stdlib.h>
#include"dlinklist.h"

typedef struct _tag_DLinkList{
    DLinkListNode header;
    DLinkListNode*slider;
    int length;
}TDLinkList;

DLinkList* DLinkList_Create(){
    TDLinkList *ret=(TDLinkList*)malloc(sizeof(TDLinkList));
    if(ret!=NULL){
        ret->header.next=NULL;
        ret->header.pre=NULL;
        ret->slider = NULL;
        ret->length = 0;
    }
    return ret;
}

void DLinkList_Destroy(DLinkList* list){
    if(list!=NULL){
        free(list);
    }
    return ;
}

void DLinkList_Clear(DLinkList* list){
    TDLinkList *sList = (TDLinkList*)list;
    if(sList != NULL){
        sList->header.next = NULL;
        sList->header.pre  = NULL;
        sList->length = 0;
        sList->slider = NULL;
    }
    return ;
}

int DLinkList_Length(DLinkList* list){
    TDLinkList *sList = (TDLinkList*)list;
    int ret = -1;
    if(sList != NULL){
        ret = sList->length;
    }
    return ret;
}

int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos){
    int ret = 0,i=0;
    TDLinkList *sList = (TDLinkList*)list;

    if(sList==NULL || node==NULL || pos<0){
        return -1;
    }
    DLinkListNode *current = (DLinkListNode*)sList;
    DLinkListNode *next = NULL;
    //如果current->next=NULL 要求在8号位置插入程序就会断
    for(i=0 ;(i<pos)&&(current->next!=NULL); i++){
        current=current->next;
    }
    next = current->next;

    current->next = node;
    node->next = next;

    if(next != NULL){
        next->pre = node;
    }
    node->pre = current;
    if(sList->length==0){
        sList->slider=node;
    }
    //如果实在第一个位置插入需要特殊处理
    if( current ==(DLinkListNode*)sList){
        node->pre = NULL;
    }

    sList->length++;


    return ret;
}

DLinkListNode* DLinkList_Get(DLinkList* list, int pos){
    TDLinkList *sList = (TDLinkList*)list;
    DLinkListNode * ret = NULL;
    int i;
    if((sList!=NULL) && (pos>=0) && (pos<sList->length) ){
        DLinkListNode *current = (DLinkListNode*)sList;
        for(i=0; i<pos; i++){
            current = current->next;
        }
        ret = current->next;
    }
    return ret;
}

DLinkListNode* DLinkList_Delete(DLinkList* list, int pos){
    TDLinkList *sList =(TDLinkList *)list;
    DLinkListNode* ret = NULL;
    int i;
    if(sList ==NULL ||pos<0){
        return NULL;
    }
    {

        DLinkListNode *current =(DLinkListNode*)sList;
        DLinkListNode *next = NULL;
        for(i=0; i<pos; i++){
            current = current->next;
        }
        ret = current->next;
        next = ret->next;

        current->next = next;
        if(next !=NULL){
            next->pre=current;
            if(current ==(DLinkListNode*)sList){
                next->pre = NULL;
            }
        }
        if(sList->slider == ret){
            sList->slider=next;
        }

        sList->length--;
    }
    return ret;
}

//-- add
DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node){
    TDLinkList *sList =(TDLinkList*)list;
    DLinkListNode *ret = NULL;
    int i;
    if(sList !=NULL){
        DLinkListNode *current =(DLinkListNode*)sList;
        for(i=0; i<sList->length; i++){
            if(current->next == node){
                ret = current->next;
                break;
            }
            current = current->next;
        }
        if(ret!=NULL){
            DLinkList_Delete(list,i);
        }
    }
    return ret;
}

DLinkListNode* DLinkList_Reset(DLinkList* list){
    TDLinkList *sList =(TDLinkList*)list;
    DLinkListNode *ret = NULL;
    if(sList !=NULL){
        ret = sList->slider;
        sList->slider = sList->header.next;
    }
    return ret;
}

DLinkListNode* DLinkList_Current(DLinkList* list){
    TDLinkList * sList = (TDLinkList*)list;
    DLinkListNode * ret = NULL;
    if(sList != NULL){
        ret = sList->slider;
    }
    return ret;
}

DLinkListNode* DLinkList_Next(DLinkList* list){
    TDLinkList *sList = (TDLinkList*)list;
    DLinkListNode * ret = NULL;
    if((sList!=NULL) &&(sList->slider!=NULL)){
        ret = sList->slider;
        sList->slider = ret->next;
    }
    return ret;
}

DLinkListNode* DLinkList_Pre(DLinkList* list){
    TDLinkList *sList = (TDLinkList*)list;
    DLinkListNode * ret = NULL;
    if((sList != NULL) && (sList->slider!=NULL)){
        ret = sList->slider;
        sList->slider = ret->pre;
    }
    return ret;
}

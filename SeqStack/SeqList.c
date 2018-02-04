#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeqList.h"

typedef struct _tag_SeqList{
	int capacity;
	int length;
	unsigned int *node;
}TSeqList;

SeqList* SeqList_Create(int capacity){
	TSeqList *ret=NULL;
	if(capacity<0){
		return NULL;
	}
	ret=(TSeqList*)malloc(sizeof(TSeqList) + sizeof(unsigned int)*capacity);
	if(!ret){
		return NULL;
	}
	memset(ret,0,sizeof(TSeqList));
	ret->node=ret+1;
	/*
	ret=(TSeqList*)malloc(sizeof(TSeqList));
	if(!ret){
		return NULL;
	}
	ret->node=(unsigned int *)malloc(sizeof(unsigned int)*capacity);
	if(!ret->node){
		free(ret);
		return NULL;
	}
	*/
	ret->capacity=capacity;
	ret->length=0;
	return ret;
}

int  SeqList_Create01(SeqList **handle, int capacity){
	return 0;
}

void SeqList_Destroy(SeqList* list){
	if(!list){
		return;
	}
	free(list);
	return;
}
//clear zero
void SeqList_Clear(SeqList* list){
	TSeqList *tlist=(TSeqList*)list;
	if(!list){
		return;
	}
	tlist->length=0;
	return;
}

int SeqList_Length(SeqList* list){
	TSeqList *tlist=(TSeqList*)list;
	if(!list){
		return -1;
	}
	return tlist->length;
}

int SeqList_Capacity(SeqList* list){
	TSeqList *tlist=(TSeqList*)list;
	if(!list){
		return -1;
	}
	return tlist->capacity;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos){
	int i;
	TSeqList *tlist=NULL;
	if(list==NULL || node==NULL){
		return -1;
	}
	tlist=(TSeqList*)list;
	//full?
	if(tlist->length>=tlist->capacity){
		return -2;
	}
	
	//pos  
	if(pos<0||pos>=tlist->capacity){
		return -1;
	}
	//inseart on tial
	if(pos>=tlist->length){
		pos=tlist->length;
	}  
	for(i=tlist->length; i>pos; i--){
		tlist->node[i]=tlist->node[i-1];
	}
	tlist->node[pos] = (unsigned int)node;
	tlist->length++;
	return 0;
}

SeqListNode* SeqList_Get(SeqList* list, int pos){
	SeqListNode *ret=NULL;
	TSeqList *tlist=NULL;
	tlist=(TSeqList*)list;
	if(list==NULL|| pos<0 || pos>=tlist->length ){
		return NULL;
	}
	ret=(SeqListNode*)tlist->node[pos];
	return ret;
}

SeqListNode* SeqList_Delete(SeqList* list, int pos){
	int i;
	SeqListNode* ret=NULL;
	TSeqList *tlist=NULL;
	tlist=(TSeqList*)list;
	
	if(list==NULL|| pos<0 || pos>=tlist->length){
		return NULL;
	}
	
	
	//return delete node
	ret=(SeqListNode*)tlist->node[pos];
	
	//delete
	for(i=pos+1; i<tlist->length; i++){
		tlist->node[i-1]=tlist->node[i];
	}
	
	//tlist->length--;
	tlist->length--;
	return ret;
}




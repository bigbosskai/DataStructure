#include <stdio.h>
#include <stdlib.h>
#include"SeqList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct _T{
	char name[64];
	int age;
}T;
int main(int argc, char *argv[]) {
	int i=0;
	T t1,t2,t3;
	t1.age=31;
	t2.age=32;
	t3.age=33;
	SeqList *list=NULL;
	list=SeqList_Create(10);
	SeqList_Insert(list,(SeqListNode*)&t1,0);	
	SeqList_Insert(list,(SeqListNode*)&t2,1);
	SeqList_Insert(list,(SeqListNode*)&t3,2);
	
	printf("list length:%d\n",SeqList_Length(list));
	for(i=0; i<SeqList_Length(list); i++){
		T *tmp=(T*)SeqList_Get(list,i);
		if(tmp){
			printf("tmp->age:%d\n",tmp->age);	
		}
	}
	int len=SeqList_Length(list);
	for(i=0; i<len; i++){
		SeqList_Delete(list,i);
	}
	SeqList_Destroy(list);
	return 0;
}

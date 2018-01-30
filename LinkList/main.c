#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct _taqT{
	LinkListNode node;
	char name[20];
	int age;
}T;
int main(int argc, char *argv[]) {
	T t1,t2,t3;
	LinkList *list;
	int length,i;
	t1.age=31;
	t2.age=32;
	t3.age=33;
	list=LinkList_Create();
	printf("list is: %d\n",list);
	length=LinkList_Length(list);
	printf("length :%d\n",length);
	
	//
	LinkList_Insert(list,(LinkListNode*)&t1,LinkList_Length(list));
	LinkList_Insert(list,(LinkListNode*)&t2,LinkList_Length(list));
	LinkList_Insert(list,(LinkListNode*)&t3,LinkList_Length(list));
	length=LinkList_Length(list);
	printf("length :%d\n",length);
	
	for(i=0; i<length; i++){
		T *tmp=(T*)LinkList_Get(list,i);
		printf("age: %d\n",tmp->age);
	}
	while(LinkList_Length(list)>0){
		T *tmp=(T*)LinkList_Delete(list,0);
		printf("age :%d\n",tmp->age);
	}
	
	return 0;
}

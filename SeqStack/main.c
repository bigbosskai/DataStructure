#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "seqstack.h"


int main()
{

	int a[20], i = 0;
	int *pTmp = NULL;
	SeqStack* stack = NULL;

	stack = SeqStack_Create(20);

	for (i=0; i<10; i++)
	{
		a[i] = i+1;
		//SeqStack_Push(stack, &a[i]);
		SeqStack_Push(stack, a+i);
	}


	pTmp = (int *)SeqStack_Top(stack);
	printf("top:%d \n", *pTmp);

	printf("capacity:%d \n", SeqStack_Capacity(stack));

	printf("size:%d \n", SeqStack_Size(stack));

	//ÔªËØ³öÕ»
	while (SeqStack_Size(stack) > 0)
	{
		printf("pop:%d \n", *((int *)SeqStack_Pop(stack)) );
	}

	SeqStack_Destroy(stack);

	system("pause");
	return 0;
}

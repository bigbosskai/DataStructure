#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"
int main()
{
    int a[10],i,*ptmp;
    LinkStack *stack =  NULL;
    stack = LinkStack_Create();

    for(i=0; i<10; i++){
        a[i]=i+1;
        LinkStack_Push(stack,&a[i]);
    }
    printf("top: %d\n",*(int*)LinkStack_Top(stack));

    printf("size: %d\n",LinkStack_Size(stack));

    while( LinkStack_Size(stack)>0 ){
        ptmp = (int*)LinkStack_Pop(stack);
        printf("ptmp: %d\n",*ptmp);
    }
    LinkStack_Destroy(stack);
    printf("Hello world!\n");
    return 0;
}

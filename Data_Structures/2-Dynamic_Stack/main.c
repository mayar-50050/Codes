#include <stdio.h>
#include <stdlib.h>
#include "../Stack.h"

stack_ds_t stack1;
stack_ds_t stack2;
return_status_t ret = R_OK;
uint32 value;
uint32 size=0;
int index=0;
uint8 ch='y';

int main()
{
    printf("Enter the size you want\n");
    scanf("%d",&size);
    ret = stack_init(&stack1,size);
    ret = stack_init(&stack2,size);
    for(int i=0; (i<10) && (ch=='y') && (ret != R_NOK) ;i++)
    {
        printf("Enter a value to push\n");
        scanf("%d",&value);
        ret = stack_push(&stack1,value);
        printf("Do you want to continue?\t (y/n)? \n");
        fflush(stdin);
        scanf("%c",&ch);
        fflush(stdin);
        index=i+1;
    }
    stack_display(&stack1);
    free(stack1.data);
    free(stack2.data);
    return 0;
}

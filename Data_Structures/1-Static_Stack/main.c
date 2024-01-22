#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
stack_ds_t main_stack;
stack_ds_t main_stack2;
return_status_t ret = R_NOK;

int main()
{
    ret = stack_init(&main_stack);
    ret |= stack_init(&main_stack2);
    printf("ret= %i\n",ret);

    for(int i =0;i<7;i++)
    {
        ret = stack_push(&main_stack,15+i);
    }
    printf("ret= %i\n",ret);
    printf("===============\n");
    ret |=stack_copy(&main_stack2,&main_stack);
    printf("ret= %i\n",ret);
    ret |=stack_display(&main_stack2);
    printf("ret= %i\n",ret);

    return 0;
}

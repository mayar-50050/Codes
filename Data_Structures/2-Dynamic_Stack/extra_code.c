#include <stdio.h>
#include <stdlib.h>
#include "../Stack.h"

stack_ds_t stack1;
stack_ds_t stack2;
return_status_t ret = R_OK;
uint32 value;
uint32 size=0;
uint8 ch='y';
int index=0;
FILE *LOG;

int main()
{
    //while(ret != R_NOK);
    LOG=fopen("Log.txt","w");
    printf("Enter the size you want\n");
    fprintf(LOG,"Enter the size you want\n");

    scanf("%d",&size);
    ret = stack_init(&stack1,size);
    ret = stack_init(&stack2,size);
    for(int i=0; (i<size) && (ch=='y') && (ret != R_NOK) ;i++)
    {
        printf("Enter a value to push\n");
        fprintf(LOG,"Enter a value to push\n");
        scanf(LOG,"%d",&value);
        ret = stack_push(&stack1,value);
        printf("Do you want to continue?\t (y/n)? \n");
        fprintf(LOG,"Do you want to continue?\t (y/n)? \n");
        fflush(stdin);
        scanf("%c",&ch);
        fflush(stdin);
        index=i+1;
    }
    printf("++++++++++++++++++++++\n");
    fprintf(LOG,"++++++++++++++++++++++\n");


    ret = stack_copy(&stack2,&stack1);
    //printf("ret = %d \n",ret);
    for(int i=0;i<index;i++)
    {
        stack_top(&stack2,&value);
        ret = stack_pop(&stack2);
        printf("(%i) ret = %d ,\t value= %d\n",i,ret,value);
        fprintf(LOG,"(%i) ret = %d ,\t value= %d\n",i,ret,value);
    }
    free(stack1.data);
    free(stack2.data);
    fclose(LOG);
    return 0;
}

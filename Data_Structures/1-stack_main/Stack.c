#include "Stack.h"

return_status_t stack_init(stack_ds_t *my_stack)
{
    return_status_t Status= R_OK;
    uint8 index=0;
    if(NULL == my_stack)
    {
        Status=R_NOK;
    }
    else
    {
        my_stack->stack_pointer=-1;
    }
    return Status;
}


/*///////////////////////////////////////////////////////*/
stack_status_t stack_status (stack_ds_t *my_stack)
{
    stack_status_t stat=STACK_EMPTY;
    if( NULL != my_stack)
    {
        if(my_stack->stack_pointer < 0)
        {
            stat = STACK_EMPTY ;
        }
        else
        {
            if(my_stack->stack_pointer < STACK_MAX_SIZE)
            { 
                stat = STACK_NOT_FULL;
            }
            else
            {
                stat = STACK_FULL;
            }
        }
    }
    return stat;
}


/*///////////////////////////////////////////////////////*/
return_status_t stack_push (stack_ds_t *my_stack,uint32 data)
{
    return_status_t Status= R_OK;
    stack_status_t temp = stack_status(my_stack);
    if((NULL == my_stack )|| (temp == STACK_FULL) )
    {
        Status=R_NOK;
    }
    else
    {
        
        my_stack->stack_pointer++;
        my_stack->data[my_stack->stack_pointer]=data;
    }
    return Status;
}


/*///////////////////////////////////////////////////////*/
return_status_t stack_pop (stack_ds_t *my_stack)
{
    return_status_t Status= R_OK;
    stack_status_t temp = stack_status(my_stack);
    if((NULL == my_stack )|| (temp == STACK_FULL))
    {
        Status=R_NOK;
    }
    else
    {
        my_stack->stack_pointer--;
    }
    return Status;
}


/*///////////////////////////////////////////////////////*/
uint32 stack_top (stack_ds_t *my_stack)
{
    uint32 Stack_Top=0;
    return_status_t Status= R_OK;
    stack_status_t temp = stack_status(my_stack);
    if((NULL == my_stack )|| (temp == STACK_EMPTY))
    {
        Status=R_NOK;
    }
    else
    {
        Stack_Top =my_stack->data[my_stack->stack_pointer];
    }
    return Stack_Top;
}


/*///////////////////////////////////////////////////////*/
return_status_t stack_display (stack_ds_t *my_stack) 
{
    return_status_t Status= R_OK;
    stack_ds_t *display_stack = NULL;
    stack_status_t temp = stack_status(my_stack); 
    if((NULL == my_stack )|| (temp == STACK_EMPTY) )
    {
        Status=R_NOK;
    }
    else
    {
        Status |= stack_copy(display_stack,my_stack);
        uint8 Size = stack_size(my_stack);
        uint8 index=0;

        for(index=0 ;index <Size; index++)
        {
            printf("%d\n",stack_top(display_stack));
            stack_pop(display_stack);
        }
    }
    return Status;
}


/*///////////////////////////////////////////////////////*/
return_status_t stack_copy (stack_ds_t *dest, stack_ds_t *src)
{
    return_status_t Status = R_OK;
    uint8 Size = stack_size(src);
    uint8 index=0;
    stack_ds_t dummy;

    if(( NULL != src) && (stack_status(src) != STACK_EMPTY))
    {
        Status = stack_init(dest);
        for(index=0;( (index<Size) && (Status != R_NOK) );index++)
        {
        Status |= stack_push(&dummy,stack_top(src));
        Status |= stack_pop(src); 
        }
        for(index=0;( (index<Size) && (Status != R_NOK) );index++)
        {
        Status |= stack_push(src,stack_top(&dummy));
        Status |= stack_push(dest,stack_top(&dummy));
        Status |= stack_pop(&dummy); 
        }
    }

    else
    {
        Status = R_NOK;
    }

    return Status;
}


/*///////////////////////////////////////////////////////*/
uint8 stack_size(stack_ds_t *my_stack)
{
    return ((my_stack->stack_pointer)+1);
}
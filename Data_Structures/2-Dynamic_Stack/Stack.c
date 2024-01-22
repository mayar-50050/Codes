#include "Stack.h"

return_status_t static stack_resize (stack_ds_t *my_stack);
/*
    @brief:     Intilize the default values of a new stack
    @argum:     my_stack is a pointer to the stack
    @argum:     Size is the intial wanted size of the stack
    @retval:    return_status_t is to describe the function progress
*/
return_status_t stack_init(stack_ds_t *my_stack,uint32 Size)
{
    return_status_t Status= R_OK;
    if(NULL == my_stack)
    {
        Status=R_NOK;
    }
    else
    {
        my_stack->stack_pointer=-1;
        my_stack->stack_max_size=Size;
        my_stack->data =(uint32 *) calloc(Size,sizeof(uint32));
    }

    return Status;
}


/*///////////////////////////////////////////////////////*/
/*
    @brief:     Starus cheak of the stack
    @argum:     my_stack is a pointer to the stack
    @retval:    stack_status_t is to describe the function progress
                ->STACK_FULL
                ->STACK_EMPTY
                ->STACK_NOT_FULL
*/
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
            if(my_stack->stack_pointer < (my_stack->stack_max_size -1))
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
/*
    @brief:     Add data to the stack
    @argum:     my_stack is a pointer to the stack
    @argum:     Data is the value to add
    @retval:    return_status_t is to describe the function progress
*/
return_status_t stack_push (stack_ds_t *my_stack,uint32 Data)
{
    return_status_t Status= R_OK;
    stack_status_t temp = stack_status(my_stack);
    if((NULL == my_stack )|| (temp == STACK_FULL) )
    {
        Status=R_NOK;
        if(temp == STACK_FULL)
        {
            printf("Stack is Full!\n");
            #ifdef _resize_
            uint8 ch='n';
            fflush(stdin);
            printf("Do you want to resize the stack (y/n)? \n");
            fflush(stdin);
            scanf("%c",&ch);
            fflush(stdin);
            if(ch=='y')
            {
                stack_resize(my_stack);
                Status=R_OK;
                goto L_Resize;
            }
            #endif
        }
    }
    else
    {
        L_Resize:
        my_stack->stack_pointer++;
        my_stack->data[my_stack->stack_pointer]=Data;
    }
    return Status;
}


/*///////////////////////////////////////////////////////*/
/*
    @brief:     Remove data from the stack
    @argum:     my_stack is a pointer to the stack
    @retval:    return_status_t is to describe the function progress
*/
return_status_t stack_pop (stack_ds_t *my_stack)
{
    return_status_t Status= R_OK;
    stack_status_t temp = stack_status(my_stack);
    if((NULL == my_stack )|| (temp == STACK_EMPTY))
    {
        Status=R_NOK;
        if(temp == STACK_EMPTY)
        {
            printf("Stack is empty!\n");
        }
    }
    else
    {
        my_stack->stack_pointer--;
    }
    return Status;
}


/*///////////////////////////////////////////////////////*/
/*
    @brief:     Read data at the top of the stack
    @argum:     my_stack is a pointer to the stack
    @argum:     top_val is a pointer to the the value read
    @retval:    return_status_t is to describe the function progress
*/
return_status_t stack_top (stack_ds_t *my_stack, uint32 *top_val)
{
    return_status_t Status= R_OK;
    stack_status_t temp = stack_status(my_stack);
    if((NULL == my_stack )|| (temp == STACK_EMPTY))
    {
        Status=R_NOK;
        if(temp == STACK_EMPTY)
        {
            printf("Stack is empty!\n");
        }
    }
    else
    {
        *top_val =my_stack->data[my_stack->stack_pointer];
    }
    return Status;
}


/*///////////////////////////////////////////////////////*/
/*
    @brief:     Display data in stack
    @argum:     my_stack is a pointer to the stack
    @retval:    return_status_t is to describe the function progress
*/
return_status_t stack_display (stack_ds_t *my_stack)
{
    return_status_t Status= R_OK;
    stack_ds_t display_stack ;
    stack_init(&display_stack,stack_size(my_stack));
    stack_status_t temp = stack_status(my_stack);
    if((NULL == my_stack )|| (temp == STACK_EMPTY) )
    {
        Status=R_NOK;
        if(temp == STACK_EMPTY)
        {
            printf("Stack is empty!\n");
        }
    }
    else
    {
        Status = stack_copy(&display_stack,my_stack);
        uint32 Size = stack_size(my_stack);
        uint32 index=0;
        uint32 value = 0;
        for(index=0 ;index < Size; index++)
        {
            stack_top(&display_stack,&value);
            printf("%i- %d\n",(index+1),value);
            stack_pop(&display_stack);
        }
    }
    free(display_stack.data);
    return Status;
}


/*///////////////////////////////////////////////////////*/
/*
    @brief:     Copy data from a stack to another
    @argum:     src is a pointer to the stack to copy from
    @argum:     dest is a pointer to the stack to copy to
    @retval:    return_status_t is to describe the function progress
*/
return_status_t stack_copy (stack_ds_t *dest, stack_ds_t *src)
{
    return_status_t Status = R_OK;
    uint32 Size = stack_size(src);
    uint32 index=0;
    uint32 value=0;
    stack_ds_t dummy;
    stack_init(&dummy,stack_size(src));
    //stack_init(dest,src->stack_max_size);

    if(( NULL != src) && (stack_status(src) != STACK_EMPTY) && (( NULL != dest)))
    {
        for(index=0; (index<Size);index++)
        {
            stack_top(src,&value);
            stack_push(&dummy,value);
            stack_pop(src);
        }

        for(index=0;( (index<Size) );index++)
        {
            stack_top(&dummy,&value);
            stack_push(src,value);
            stack_push(dest,value);
            stack_pop(&dummy);
        }
    }

    else
    {
        Status = R_NOK;
    }
    free(dummy.data);

    return Status;
}


/*///////////////////////////////////////////////////////*/
/*
    @brief:     know te number of elements inside the stack
    @argum:     my_stack is a pointer to the stack
    @retval:    uint32 is number of elements
*/
uint32 stack_size(stack_ds_t *my_stack)
{
    return ((my_stack->stack_pointer)+1);
}


/*///////////////////////////////////////////////////////*/
/*
    @brief:     Change stack size
    @argum:     my_stack is a pointer to the stack
    @retval:    return_status_t is to describe the function progress
*/
return_status_t static stack_resize (stack_ds_t *my_stack)
{
    return_status_t Status = R_OK;
    if( NULL != my_stack)
    {
        my_stack->data =(uint32 *) realloc(my_stack->data,
                        (my_stack->stack_max_size+1)*(my_stack->data[0]));
        (my_stack->stack_max_size)++;
    }
    else
    {
        Status = R_NOK;
    }

    return Status;
}

#ifndef _STACK_H_
#define _STACK_H_

/********************Include libries**************/
#include <stdio.h>
#include <stdlib.h>
#include "platform_types.h"

/*                      MACROS                  */
#define STACK_MAX_SIZE
#define _resize_


/*                  STRUCTURES              */
typedef struct stack_ds
{
    uint32 stack_max_size;
    sint32 stack_pointer;
    uint32 *data;
}stack_ds_t;

typedef enum stack_status_i
{
    STACK_EMPTY = 0,
    STACK_FULL,
    STACK_NOT_FULL,
}stack_status_t;

typedef enum return_status
{
    R_NOK,
    R_OK
}return_status_t;

/*                  PROTOTYPES              */
return_status_t stack_init(stack_ds_t *my_stack,uint32 Size);
return_status_t stack_push (stack_ds_t *my_stack,uint32 Data);
return_status_t stack_pop (stack_ds_t *my_stack);
return_status_t stack_display (stack_ds_t *my_stack);
return_status_t stack_copy (stack_ds_t *dest, stack_ds_t *src);
return_status_t stack_top (stack_ds_t *my_stack, uint32 *top_val);
stack_status_t stack_status (stack_ds_t *my_stack);
uint32 stack_size(stack_ds_t *my_stack);




#endif /*_STACK_H_*/

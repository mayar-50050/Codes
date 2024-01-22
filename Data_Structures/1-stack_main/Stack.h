#ifndef _STACK_H_
#define _STACK_H_

/********************Include libries**************/
#include "platform_types.h"
/*                      MACROS                  */
#define STACK_MAX_SIZE 5
#define NULL ((void *)0)

/*                  STRUCTURES              */
typedef struct stack_ds
{
    sint32 stack_pointer;
    uint32 data[STACK_MAX_SIZE];
}stack_ds_t;

typedef enum stack_status_i
{
    STACK_EMPTY =0,
    STACK_FULL,
    STACK_NOT_FULL,
}stack_status_t;

typedef enum return_status
{
    R_NOK,
    R_OK
}return_status_t;

/*                  PROTOTYPES              */
return_status_t stack_init(stack_ds_t *my_stack);
return_status_t stack_push (stack_ds_t *my_stack,uint32 Data);
return_status_t stack_pop (stack_ds_t *my_stack);
return_status_t stack_display (stack_ds_t *my_stack);
return_status_t stack_copy (stack_ds_t *dest, stack_ds_t *src);
stack_status_t stack_status (stack_ds_t *my_stack);
uint8 stack_size(stack_ds_t *my_stack);
uint32 stack_top (stack_ds_t *my_stack);



#endif /*_STACK_H_*/

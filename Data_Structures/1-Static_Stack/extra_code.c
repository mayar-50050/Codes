/*
    printf("ret = %d  [stack_init()]\n",ret);

    ret = stack_pop(&main_stack);
    printf("ret = %d  [stack_pop()]\n",ret);

    ret = stack_push(&main_stack,15);
    printf("ret = %d  [stack_push()]\n",ret);


    printf("Top = %d  [stack_top()]\n",stack_top(&main_stack));*/

    /* printf("Top = %d  [stack_top()]\n",stack_top(&main_stack));
        printf("===============\n");*/

    printf("STATUS ==%d\n",stack_status(&main_stack));
    printf("===============\n");
    for(int i =0;i<5;i++)
    {
        ret = stack_push(&main_stack,15+i);
        printf("ret = %d  [stack_push()]\n",ret);

    }
    printf("===============\n");
    printf("STATUS ==%d\n",stack_status(&main_stack));

    /*stack_copy(&main_stack2,&main_stack);
    for(int i =0;i<3;i++)
    {
        printf("Top = %d  [stack_top()]\n",stack_top(&main_stack2));
        ret = stack_pop(&main_stack2);
    }*/
/////////////////////////////////////////////////
/*
    ret = stack_push(&main_stack,15);
    ret = stack_push(&main_stack,70);
    printf("Top = %d  [stack_top()]\n",stack_top(&main_stack));
    ret = stack_pop(&main_stack);
    printf("Top = %d  [stack_top()]\n",stack_top(&main_stack));
    */
    for(int i =0;i<4;i++)
    {
        ret = stack_push(&main_stack,15+i);
        //printf("ret = %d  [stack_push()]\n",ret);
    }
    printf("===============\n");
    printf("STATUS ==%d\n",stack_status(&main_stack));
    stack_copy(&main_stack2,&main_stack);
    for(int i =0;i<4;i++)
    {
        printf("Top = %d  [stack_top()]\n",stack_top(&main_stack2));
        ret = stack_pop(&main_stack2);
    }
    printf("STATUS ==%d\n",stack_status(&main_stack2));
    return 0;

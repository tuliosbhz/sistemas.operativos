

struct stack_el{
    char *str;              /* String to be printed in show() */
    int n;                  /* Integer to be printed in show() */
    struct stack_el *next;  /* Link to next stack element */
};
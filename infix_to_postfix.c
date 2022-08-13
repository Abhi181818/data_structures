#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
int peek(struct stack *sp)
{
    return sp->arr[sp->top];
}
int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
        return 0;
}
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
        return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
        return 0;
}

void push(struct stack *ptr, char value)
{

    if (isFull(ptr))
    {
        printf("full");
    }
    else
    {
        ptr->top += 1;
        ptr->arr[ptr->top] = value;
    }
}
char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("empty");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top -= 1;
        return val;
    }
}
char *infixtopost(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(peek(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char *infix = "a-c*d/e";
    
    printf("Infix to Postfix:  %s", infixtopost(infix));

    return 0;
}

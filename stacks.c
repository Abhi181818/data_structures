#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};

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

void push(struct stack *ptr, int value)
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
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Empty");
        return 0;
    }
    else
    {
        int val=ptr->arr[ptr->top];
        ptr->top-=1;
        return val;
    }
}
int main()
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 4;
    s->top = -1;
    s->arr = malloc(s->size * sizeof(int));
    push(s, 10);
    push(s, 40);
    push(s, 60);
    push(s, 69);
    printf("pushed values \n");
    for (int i = s->size-1; i >=0; i--)
    {
        printf("Values %d \n", s->arr[i]);
    }
    printf("removed value \n");
    printf("%d  \n",pop(s));
    printf("stack after removing ::\n");

     for (int i = s->size-1; i >=0; i--)
    {
        printf("Values %d \n", s->arr[i]);
    }
    return 0;
}
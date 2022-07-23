#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void traverse(struct Node *node)
{

    while (node != NULL)
    {
        printf(" Values : %d \n", node->data);
        node = node->next;
    }
}

// delete first
struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// delete at begining
struct Node *deleteAtPosition(struct Node *head, int position)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < position - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

    return head;
}

// delet at last
struct Node *deleteLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    // dynamic memory
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    // linking head and second
    head->data = 69;
    head->next = second;

    // second node linking to third
    second->data = 68;
    second->next = third;

    // third node
    third->data = 67;
    third->next = fourth;

    // fourth node
    fourth->data = 66;
    fourth->next = fifth;

    // fifth node
    fifth->data = 60;
    fifth->next = NULL;

    traverse(head);

    printf("After deleting \n");

    // head = deleteFirst(head);
    head = deleteAtPosition(head, 2);
    traverse(head);

    return 0;
}
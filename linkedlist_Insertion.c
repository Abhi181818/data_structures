#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

// print all values in list
void traverse(struct Node *node)
{

    while (node != NULL)
    {
        printf(" Values : %d \n", node->data);
        node = node->next;
    }
}

// at begining funciton
struct Node *atBeggining(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// atposition
struct Node *atPosition(struct Node *head, int data, int position)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != position - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return (head);
}

// insert at end
struct Node *atEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// insert after node
struct Node *afterNode(struct Node *head, struct Node *previousNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = previousNode->next;
    previousNode->next = ptr;
    return head;
}

// reverse a linked list
struct Node *reverse(struct Node *head)
{
    struct Node *crntNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *prevNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *nextNode = (struct Node *)malloc(sizeof(struct Node));
    prevNode = NULL;
    crntNode = head;
    nextNode = head;
    while (nextNode != NULL)
    {
        nextNode = nextNode->next;
        crntNode->next = prevNode;
        prevNode = crntNode;
        crntNode = nextNode;
    }
    head = prevNode;

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

    printf("After adding at end \n");
    // insert at begining
    // head = atBeggining(head, 99);

    // insert at position
    // head = atPosition(head, 1010, 2);

    // insert at end
    // head = atEnd(head, 99);

    // insert after node
    // head = afterNode(head, second, 1022);

    // reverse list
    head = reverse(head);
    traverse(head);

    return 0;
}

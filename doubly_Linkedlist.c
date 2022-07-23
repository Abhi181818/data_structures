#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
void traverse(struct Node *head)
{

    while (head != NULL)
    {
        printf("%d \n", head->data);
        head = head->next;
    }
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fisrtNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *secondNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *thirdNode = (struct Node *)malloc(sizeof(struct Node));

    head->data = 69;
    head->next = fisrtNode;
    head->prev = NULL;

    fisrtNode->data = 68;
    fisrtNode->next = secondNode;
    fisrtNode->prev = head;

    secondNode->data = 67;
    secondNode->next = thirdNode;
    secondNode->prev = fisrtNode;

    thirdNode->data = 66;
    thirdNode->prev = secondNode;
    thirdNode->next = NULL;

    traverse(head);

    return 0;
}

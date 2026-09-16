#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node* insertAtBeginning(struct Node *start, int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return start;
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = start;

    if (start != NULL)
    {
        start->prev = newNode;
    }

    start = newNode;

    return start;
}
struct Node* insertAtEnd(struct Node *start, int value)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return start;
    }

    newNode->data = value;
    newNode->next = NULL;
    if (start == NULL)
    {
        newNode->prev = NULL;
        start = newNode;
        return start;
    }
    temp = start;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return start;
}
void display(struct Node *start)
{
    struct Node *temp = start;

    if (start == NULL)
    {
        printf("Doubly Linked List is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");

    while (temp != NULL)
    {
        printf("%d", temp->data);

        if (temp->next != NULL)
        {
            printf(" <-> ");
        }

        temp = temp->next;
    }

    printf("\n");
}
int main()
{
    struct Node *start = NULL;
    int choice, value;

    while (1)
    {
        printf("\n===== DOUBLY LINKED LIST =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Display List\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);

                start = insertAtBeginning(start, value);

                printf("Node inserted at beginning successfully.\n");
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);

                start = insertAtEnd(start, value);

                printf("Node inserted at end successfully.\n");
                break;

            case 3:
                display(start);
                break;

            case 4:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

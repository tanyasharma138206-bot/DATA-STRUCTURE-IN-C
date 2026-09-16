#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *start = NULL;
void insertEnd(int value)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (start == NULL)
    {
        start = newNode;
        return;
    }

    temp = start;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}
void deleteFirst()
{
    struct Node *temp;

    if (start == NULL)
    {
        printf("\nList is empty. Cannot delete.\n");
        return;
    }

    temp = start;
    start = start->next;

    if (start != NULL)
    {
        start->prev = NULL;
    }

    free(temp);

    printf("\nFirst node deleted successfully.\n");
}
void deleteLast()
{
    struct Node *temp;

    if (start == NULL)
    {
        printf("\nList is empty. Cannot delete.\n");
        return;
    }

    temp = start;
    if (temp->next == NULL)
    {
        start = NULL;
        free(temp);
        printf("\nLast node deleted successfully.\n");
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->prev->next = NULL;

    free(temp);

    printf("\nLast node deleted successfully.\n");
}
void deleteSpecific(int value)
{
    struct Node *temp;

    if (start == NULL)
    {
        printf("\nList is empty. Cannot delete.\n");
        return;
    }

    temp = start;
    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("\nNode with value %d not found.\n", value);
        return;
    }
    if (temp == start)
    {
        start = temp->next;

        if (start != NULL)
        {
            start->prev = NULL;
        }

        free(temp);

        printf("\nNode %d deleted successfully.\n", value);
        return;
    }
    if (temp->next == NULL)
    {
        temp->prev->next = NULL;
        free(temp);

        printf("\nNode %d deleted successfully.\n", value);
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);

    printf("\nNode %d deleted successfully.\n", value);
}
void display()
{
    struct Node *temp;

    if (start == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    temp = start;

    printf("\nDoubly Linked List:\n");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}
int main()
{
    int n, value, choice, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insertEnd(value);
    }

    do
    {
        printf("\n===== DOUBLY LINKED LIST =====");
        printf("\n1. Delete First Node");
        printf("\n2. Delete Last Node");
        printf("\n3. Delete Specific Node");
        printf("\n4. Display List");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                deleteFirst();
                break;

            case 2:
                deleteLast();
                break;

            case 3:
                printf("\nEnter value to delete: ");
                scanf("%d", &value);
                deleteSpecific(value);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nProgram terminated.\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}


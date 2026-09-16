#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;
};

void insertAtStarting(struct Node **start, int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = start;
    start = newNode;

    printf("Node inserted at starting successfully.\n");
}


void insertAtEnd(struct Node **start, int value) {
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (start == NULL)
    {
        start = newNode;
        printf("Node inserted at end successfully.\n");
        return;
    }


    temp = start;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    printf("Node inserted at end successfully.\n");
}

void display(struct Node *start)
{
    struct Node *temp = start;

    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *start = NULL;
    int choice, value;

    while (1)
    {
        printf("\n--- Singly Linked List ---\n");
        printf("1. Insert at Starting\n");
        printf("2. Insert at End\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtStarting(&start, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(&start, value);
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



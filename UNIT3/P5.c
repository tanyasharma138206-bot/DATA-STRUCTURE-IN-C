#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};


struct Node* createList(int n)
{
    struct Node *start = NULL;
    struct Node *newNode;
    struct Node *temp;
    int i, value;

    for (i = 1; i <= n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        if (newNode == NULL)
        {
            printf("Memory allocation failed.\n");
            exit(1);
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (start == NULL)
        {
            start= newNode;
        }
        else
        {
            temp = start;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    return start;
}


void displayList(struct Node *start)
{
    struct Node *temp = start;

    if (start == NULL)
    {
        printf("\nLinked List is empty.\n");
        return;
    }

    printf("\nDoubly Linked List:\n");

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
    struct Node *start;
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Number of nodes must be greater than 0.\n");
        return 0;
    }


    start = createList(n);


    displayList(start);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
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
            printf("Memory allocation failed!\n");
            exit(1);
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;
        if (start == NULL)
        {
            start = newNode;
        }
        else
            {
            temp = start;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    return start;
}
void display(struct Node *start)
{
    struct Node *temp = start;

    if (start == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    printf("\nLinked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}
int main()
{
    struct Node *start = NULL;
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Number of nodes must be greater than 0.\n");
        return 0;
    }
    start = createList(n);
    display(start);

    return 0;
}

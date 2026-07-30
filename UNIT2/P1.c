#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int top = -1;

// Push operation
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = value;
        printf("%d pushed into stack.\n", value);
    }
}

// Pop operation
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Deleted element: %d\n", stack[top]);
        top--;
    }
}

// Peek operation
void peek()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Top element is: %d\n", stack[top]);
    }
}

// Update operation
void update(int position, int value)
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else if (position < 1 || position > top + 1)
    {
        printf("Invalid Position\n");
    }
    else
    {
        stack[position - 1] = value;
        printf("Element updated successfully.\n");
    }
}

// Display operation
void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int choice, value, position;

    while (1)
    {
        printf("\n===== STACK MENU =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Update\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                peek();
                break;

            case 5:
                printf("Enter position (1 to %d): ", top + 1);
                scanf("%d", &position);
                printf("Enter new value: ");
                scanf("%d", &value);
                update(position, value);
                break;

            case 6:
                printf("Exiting Program...\n");
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}


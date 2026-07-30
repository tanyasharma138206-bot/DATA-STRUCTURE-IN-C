#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++top] = ch;
    }
}

char pop()
{
    if (top == -1)
    {
        return '\0';
    }
    else
    {
        return stack[top--];
    }
}

int main()
{
    char str[MAX];
    int i;

    printf("Enter a string: ");
    gets(str);

    for (i = 0; i < strlen(str); i++)
    {
        push(str[i]);
    }

    printf("Reversed string: ");

    while (top != -1)
    {
        printf("%c", pop());
    }

    printf("\n");

    return 0;
}



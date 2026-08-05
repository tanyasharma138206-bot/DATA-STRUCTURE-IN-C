#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}
int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return 1;
    }
    return stack[top--];
}

int main()
{
    int n, i;
    long long fact = 1;

    printf("Enter a number: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        push(i);
    }
    while (top != -1)
    {
        fact = fact * pop();
    }

    printf("Factorial of %d = %lld\n", n, fact);

    return 0;
}



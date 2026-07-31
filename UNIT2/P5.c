#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return 1;
    }
    return stack[top--];
}

int main()
{
    int base, exponent, i;
    long long power = 1;

    printf("Enter the base: ");
    scanf("%d", &base);

    printf("Enter the exponent: ");
    scanf("%d", &exponent);
    for(i = 1; i <= exponent; i++)
    {
        push(base);
    }
    while(top != -1)
    {
        power = power * pop();
    }

    printf("%d ^ %d = %lld\n", base, exponent, power);

    return 0;
}

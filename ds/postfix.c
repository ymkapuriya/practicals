#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int stack[SIZE];
int top = -1; //stack is empty

void push(int value)
{
    if (top >= SIZE)
    {
        printf("Stack is full");
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

int pop()
{
    if (top < 0)
    {
        printf("Stack underflow");
        return -1;
    }
    else
    {
        int value = stack[top];
        top--;
        return value;
    }
}

void display()
{
    printf("\n Stack status \n");
    for (int i = 0; i <= top; i++)
    {
        printf(" %d -> ", stack[i]);
    }
    printf("\n################");
}

int is_digit(char ch)
{
    if (ch >= 49 && ch <= 57)
    {
        return 1;
    }
    return 0;
}

int is_operator(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        return 1;
    default:
        return 0;
    }
}

int calculate(int op1, int op2, char op)
{
    switch (op)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    }
}

int main()
{
    char *input;
    input = (char *)malloc(sizeof(char) * SIZE);
    printf("Enter postfix string :");
    scanf("%s", input);
    printf("Input : %s", input);
    int op1, op2, res;

    for (int i = 0; input[i] != '\0'; i++)
    {
        char ch = input[i];
        if (is_digit(ch))
        {
            push(ch);
        }
        else if (is_operator(ch))
        {
            display();
            op2 = pop() - 48;
            op1 = pop() - 48;
            res = calculate(op1, op2, ch) + 48;
            push(res);
        }
        else
        {
            printf("This is not valid input");
            return 0;
        }
    }
    res = pop() - 48;
    printf("Output : %d", res);
    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define ASCII_0 48

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

int calculate(int o1, int o2, char op)
{
    switch (op)
    {
    case '+':
        return o1 + o2;
    case '-':
        return o1 - o2;
    case '*':
        return o1 * o2;
    case '/':
        return o1 / o2;
    default:
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    char ch;
    int o1, o2, res;
    char *input;
    input = (char *)malloc(sizeof(char) * SIZE);
    printf("Enter input string : ");
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++)
    {
        ch = input[i];
        if (is_operator(ch))
        {
            // ch is operator
            o2 = pop() - ASCII_0;
            o1 = pop() - ASCII_0;
            //printf("%d %d", o1, o2);
            res = calculate(o1, o2, ch) + ASCII_0;
            push(res);
        }
        else
        {
            // operand
            push(ch);
        }
    }
    res = pop() - ASCII_0;
    printf("\nEvaluation of %s = %d\n", input, res);
    return 0;
}

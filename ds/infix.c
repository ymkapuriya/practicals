#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
char stack[SIZE];
int top = -1;

char peep()
{
    if (top == -1)
    {
        return -1;
    }
    return stack[top];
}

void push(char value)
{
    if (top == SIZE)
    {
        printf("Stack is full");
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

char pop()
{
    if (top == -1)
    {
        printf("\n Stack is empty");
        return -1;
    }
    char v = stack[top];
    top--;
    return v;
}

int is_empty()
{
    return top == -1;
}

void display()
{
    printf("\n ############## \n");
    for (int i = 0; i <= top; i++)
    {
        printf("%c -> ", stack[i]);
    }
    printf("\n################");
}
int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    if (op == '*' || op == '/')
    {
        return 2;
    }
}
int is_operator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return 1;
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    /* code */
    char *input;
    char *output;

    input = (char *)malloc(sizeof(char) * SIZE);
    output = (char *)malloc(sizeof(char) * SIZE);
    int o = 0;
    char ch, currentTop, ch2;

    printf("Enter input infix string : ");
    scanf("%s", input);
    printf("Input : %s", input);

    for (int i = 0; input[i] != '\0'; i++)
    {
        ch = input[i];
        if (is_operator(ch))
        {
            // letter is operator
            currentTop = peep();
            if (precedence(ch) < precedence(currentTop))
            {
                ch2 = pop();
                output[o] = ch2;
                o++;
            }
            push(ch);
        }
        else
        {
            // letter is operand
            output[o] = ch;
            o++;
        }
    }

    while (!is_empty())
    {
        ch2 = pop();
        output[o] = ch2;
        o++;
    }

    output[o] = '\0';
    printf("Output is %s ", output);
    display();
    printf("\n");
    return 0;
}

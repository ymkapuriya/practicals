#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define EMPTY '_'
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
        return EMPTY;
    }
    char v = stack[top];
    top--;
    return v;
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

int is_empty()
{
    return top == -1;
}

int is_operator(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '(':
        return 1;
    default:
        return 0;
    }
}

int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    char *input;
    char *output;
    input = (char *)malloc(sizeof(char) * SIZE);
    output = (char *)malloc(sizeof(char) * SIZE);
    printf("Input string : ");
    scanf("%s", input);
    printf("\nInput is %s", input);

    char ch, st;
    int o = 0;

    for (int i = 0; input[i] != '\0'; i++)
    {
        ch = input[i];
        if (ch == '(')
        {
            push(ch);
        }
        else if (is_operator(ch))
        {
            //stack top operator is having lower precedence
            st = peep();
            while (precedence(st) > precedence(ch))
            {
                st = pop();
                output[o++] = st;
                st = peep();
            }
            push(ch);
        }
        else
        {
            if (ch == ')')
            {
                //pop all the element till first opening bracket
                while (1)
                {
                    st = pop();
                    if (st == EMPTY)
                    {
                        printf("Invalid input string");
                        return 0;
                    }
                    if (st == '(')
                    {
                        break;
                    }
                    else
                    {
                        output[o++] = st;
                    }
                }
            }
            else
            {
                //copy to output
                output[o++] = ch;
            }
        }
    }

    while (!is_empty())
    {
        ch = pop();
        output[o++] = ch;
    }

    output[o] = '\0';
    printf("\n Output %s \n", output);
    return 0;
}

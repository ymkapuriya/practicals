#include <stdio.h>
#define SIZE 10
int stack[SIZE];
int top = -1;

int peep(){
    if(top == -1){
        return -1;
    }
    return stack[top];
}

void push(int value)
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

int pop()
{
    if (top == -1)
    {
        printf("\n Stack is empty");
        return -1;
    }
    int v = stack[top];
    top--;
    return v;
}

void display()
{
    printf("\n ############## \n");
    for (int i = 0; i <= top; i++)
    {
        printf("%d -> ", stack[i]);
    }
    printf("\n################");
}

int main(int argc, char const *argv[])
{
    int ch;
    int number;
    while (1)
    {
        printf("\n\t 1. Push \n\t 2. Pop \n\t 3. Display \n\t 4. Exit");
        printf("\n Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter number :");
            scanf("%d", &number);
            push(number);
            break;
        case 2:
            number = pop();
            if (number != -1)
            {
                printf("\n You have popped %d", number);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid input");
            break;
        }
    }
    return 0;
}

#include <stdio.h>
#define SIZE 5
int stack[SIZE];
int top = -1; // empty

void push(int value)
{
    if (top == SIZE - 1)
    {
        printf("\n Stack is full");
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
    printf("\n Stack content ###### \n");
    for (int i = 0; i <= top; i++)
    {
        printf("%d -> ", stack[i]);
    }
    printf("\n###############");
}

int main(int argc, char const *argv[])
{
    int ch;
    int value;
    while (1)
    {
        printf("\n\t 1. Push \n\t 2. Pop \n\t 3. Display \n\t 4. Exit");
        printf("\n Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            //push
            printf("Enter element : ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            //pop
            value = pop();
            if(value != -1){
                printf("\n You have popped %d", value);
            }
            break;
        case 3:
            //display
            display();
            break;
        case 4:
            //exit
            return 0;
        default:
            printf("Invalid choice");
        }
    }

    return 0;
}
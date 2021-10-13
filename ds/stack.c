#include <stdio.h>
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

int main()
{
    int ch;
    int no;
    while (1)
    {
        printf("\n Stack operations : \n\t 1. Push \n\t 2. Pop \n\t 3. Display \n\t 4. Exit");
        printf("\n Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            //push
            printf("\nEnter number :");
            scanf("%d", &no);
            push(no);
            break;
        case 2:
            //pop
            no = pop();
            if(no != -1){
                printf("\nYou have popped %d", no);
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
            printf("\nInvalid choice");
            break;
        }
    }
    return 0;
}

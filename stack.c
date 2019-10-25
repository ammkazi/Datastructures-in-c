#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

// function declaration
struct node *push(struct node *top, int val);
struct node *pop(struct node *top);
struct node *display(struct node *top);
int peek(struct node *top);

// Execution begins from here.
int main(int argc, char const *argv[])
{
    int val, option;

    do
    {
        printf("\n~~~MAIN MENU~~~\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.PEEK\n");
        printf("4.DISPLAY\n");
        printf("5.EXIT\n");

        printf("Enter your choice : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter the element to be pushed on the stack: ");
            scanf("%d", &val);
            top = push(top, val);
            break;

        case 2:
            top = pop(top);
            break;

        case 3:
            val = peek(top);
            if (val == -1)
            {
                printf("Stack is Empty.\n");
            }
            else
            {
                printf("Top most element is : %d\n", val);
            }
            break;
        case 4:
            top = display(top);
            break;
        }
    } while (option != 5);

    return 0;
}

// Add the element to the top of the stack
struct node *push(struct node *top, int val)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    if (top == NULL)
    {
        //printf("Adding first element");
        newNode->next = NULL;
        top = newNode;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
    return top;
}

// Remove the top most element from the stack
// Message : Stack is Empty (If no elements present in stack)
struct node *pop(struct node *top)
{
    struct node *ptr;
    ptr = top;
    if (top == NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("\nRemoving : %d\n", ptr->data);
        top = top->next;
        free(ptr);
    }
    return top;
}

// Display the top most element in the stack
int peek(struct node *top)
{
    if (top == NULL)
    {
        return -1;
    }
    else
    {
        return top->data;
    }
}

// Display all the elements in the stack
struct node *display(struct node *top)
{
    struct node *ptr;
    ptr = top;

    if (top == NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Elements on stack : ");
        while (ptr != NULL)
        {
            printf("%d \t", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
    return top;
}
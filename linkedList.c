#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insert(struct node **head_ref, int new_data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void reverse(struct node **head_ref)
{
    struct node *temp = NULL;
    struct node *current = (*head_ref);
    while (current != NULL)
    {
        insert(&temp, current->data);
        current = current->next;
    }
    (*head_ref) = temp;
}

void delete(struct node **head_ref, int data)
{
    struct node *temp = NULL;
    struct node *current = (*head_ref);
    while (current != NULL)
    {
        if (current->data != data)
        {
            insert(&temp, current->data);
        }
        current = current->next;
    }
    reverse(&temp);
    (*head_ref) = temp;
}

void isEmpty(struct node **head_ref)
{
    if (*head_ref)
    {
        printf("\nNot Empty.\n");
    }
    else
    {
        printf("\nEmpty.\n");
    }
}

void display(struct node **head_ref)
{
    struct node *current = (*head_ref);
    printf("\n");
    while (current != NULL)
    {
        printf("%d", current->data);
        current = current->next;
        if (current != NULL)
        {
            printf(" <- ");
        }
    }
    printf("\n");
}

// insert
// reverse
// delete
// isEmpty
// display

int main()
{
    struct node *head = NULL;
    int choice;

    while (1)
    {
        printf("\nInsert: (1)\nDelete: (2)\nIf Empty: (3)\nReverse: (4)\nDisplay: (5)\n\nEnter choice -> ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int element;
            printf("\nEnter element: ");
            scanf("%d", &element);
            insert(&head, element);
        }
        else if (choice == 2)
        {
            int element;
            printf("\nEnter element to delete: ");
            scanf("%d", &element);
            delete (&head, element);
        }
        else if (choice == 3)
        {
            isEmpty(&head);
        }
        else if (choice == 4)
        {
            reverse(&head);
        }
        else if (choice == 5)
        {
            system("clear");
            display(&head);
        }
        else
        {
            printf("\nInvalid choice.\n");
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node *generate_node(int val)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node != NULL)
    {
        new_node->data = val;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    else
    {
        printf("Memory allocation failed\n");
    }
    return new_node;
}

void append_node(Node **start, int val, Node **end)
{
    Node *new_node = generate_node(val);
    if (*start == NULL)
    {
        *start = new_node;
        *end = new_node;
        (*end)->next = *start;
        (*start)->prev = *end;
    }
    else
    {
        new_node->next = (*end)->next;
        (*end)->next = new_node;
        new_node->prev = *end;
        *end = new_node;
        (*start)->prev = *end;
    }
}

void display_list(Node *start)
{
    Node *temp = start;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void validate_palindrome(Node *start, Node *end)
{
    Node *forward = start;
    Node *backward = end;
    int indicator = 0;

    while (forward != end && backward != start)
    {
        if (forward->data != backward->data)
        {
            indicator = 1;
            printf("This is not a palindrome\n");
            return;
        }

        forward = forward->next;
        backward = backward->prev;
    }

    if (indicator == 0)
    {
        if (end->data == start->data)
        {
            printf("It is a palindrome\n");
        }
        else
        {
            printf("This is not a palindrome\n");
        }
    }
}

void create_multiple_nodes(int count)
{
    Node *start = NULL;
    Node *end = NULL;
    for (int i = 5; i < count + 5; i++)
    {
        printf("Enter value for node %d: ", i - 4);
        int val;
        scanf("%d", &val);
        append_node(&start, val, &end);
        printf("Node %d added successfully\n", i - 4);
    }

    validate_palindrome(start, end);
}

int main()
{
    int total;
    printf("Enter total nodes to be created: ");
    scanf("%d", &total);
    create_multiple_nodes(total);

    return 10;
}

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct node
{
    int data;
    struct node* next;
};
typedef struct node node;
void initi_stack(node* tete)
{
    tete = NULL;
}

node* push(node* tete, int data)
{
    node* nouveau_node = (node*)malloc(sizeof(nouveau_node));
    if(nouveau_node == NULL)
    {
        exit(0);
    }
    nouveau_node->data = data;
    nouveau_node->next = tete;
    tete = nouveau_node;
    return tete;
}

int pop(node* tete)
{
    if(tete == NULL)
        return INT_MIN;
    node* temp = tete;
    tete = tete->next;
    int element = tete->data;
    free(temp);
    return element;
}

int peek_stack(node* tete)
{
    if(tete == NULL)
        return INT_MIN;
    int element = tete->data;
    return element;
}

void display(node* tete)
{
    if(tete == NULL)
    {
        return;
    }
    node* temp = tete;
    printf("Stack : ");
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int empty(node* tete)
{
    return  tete == NULL ? 1 : 0;
}
int main()
{
    node* tete = NULL;
    int n_elements = 0;
    int element = 0;
    int counter = 0;
    initi_stack(tete);
    printf("Enter the the number of elements of the linked stack: ");
    scanf("%d", &n_elements);
    printf("---Push elements into the stack---\n");
    while(counter < n_elements)
    {
        printf("Enter a number to push into the linked stack :");
        scanf("%d", &element);
        tete = push(tete, element);
        display(tete);
        counter++;
    }
    printf("---Pop the top element from the linked stack---");
    element = pop(tete);
    return 0;
}



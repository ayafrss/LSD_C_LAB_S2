#include <stdio.h>
#include <stdlib.h>
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

int readchar(){return getchar();}

node* push(node* tete, int data)
{
    node* nouveau_node = (node*)malloc(sizeof(nouveau_node));
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
    int resultat = 0;
    while(1)
    {
        char string = readchar();
        if(string > '0')
            tete = push(tete, string);
        if(string == '+')
        {
            int arg1 = pop(tete);
            int arg2 = pop(tete);
            resultat = arg1 + arg2;
            tete = push(tete, resultat);

        }
        if(string == '*')
        {
            int arg1 = pop(tete);
            int arg2 = pop(tete);
            resultat = arg2 * arg1;
            tete = push(tete, res);
        }
        if(string == '-')
        {
            int arg1 = pop(head);
            int arg2 = pop(head);
            res = arg2 - arg1;
            head = push(head, res);
        }
        if(string == '/')
        {
            int arg1 = pop(tete);
            int arg2 = pop(tete);
            resultat = arg2 / arg1;
            tete = push(tete, res);
        }
        if(string == '%')
        {
            int arg1 = pop(tete);
            int arg2 = pop(tete);
            resultat = arg2 % arg1;
            tete = push(tete, resultat);
        }
        if(string == '\n')
            break;
    }
    res = peek_stack(tete);
    printf("The result is %d\n\n", resultat);

    return 0;
}

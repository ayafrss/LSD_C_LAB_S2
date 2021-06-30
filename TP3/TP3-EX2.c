#include <time.h>
#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

node* create(int data)
{
    node* new_node = (node*)malloc(sizeof(node));
    nouveau_node->data = data;
    nouveau_node->next = NULL;
    return nouveau_node;
}

void display_list(node* tete)
{
    node* temp = tete;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("%d  \n\n", temp->data);
}

node* append(node* tete, int data)
{
    node* temp = tete;
    if(tete == NULL)
        return create(data);
    while(temp->next != NULL)
        temp = temp->next;
    node* nouveau_node = create(data);
    temp->next = nouveau_node;
    return tete;
}

node* sort_list(node* tete)
{
    node* x, *y, *z;
    x = tete;
    y = x->next;
    if(tete == NULL)
        return NULL;
    while(y != NULL)
    {
        x = tete;
        while(x->next != y)
        {
            if(y->data < x->data)
            {
                z->data = x->data;
                x->data = y->data;
                y->data = z->data;
                y = y->next;
            }
            x = x->next;
            if(y->data > x->data)
            {
                y = y->next;
            }
        }   
    }
    return tete;
}

node* create_random(node* tete, int k)
{
    for(int i = 0; i<k; i++)
    {
        int l = rand()%k;
        node* nouveau_node = create(l);
        tete = append(tete, l);
    }
    return tete;
}

int count(node* tete)
{
    node* temp = tete;
    int k = 0;
    while(temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    return k;
}

node* merge_list(node* tete_1, node* tete_2)
{
    node* resultat = NULL;
    if(tete_1 == NULL)
        return tete_2;
    else if(tete_2 == NULL)
        return tete_1;
    if(tete_1->data <= tete_2->data)
    {
        resultat->data = tete_1->data;
        resultat->next = merge_list(tete_1->next, tete_2);
    }
    if(tete_1->data >= tete_2->data)
    {
        resultat->data = tete_2->data;
        resultat->next = merge_list(tete_1, tete_2->next);
    }
    return resultat;
}

node* remove_middle(node* tete, node* node)
{
    node* temp = tete;
    node* temp_1 = NULL;
    while(temp != node)
    {
        temp_1 = temp;
        temp = temp->next;
    }
    temp_1->next = temp->next;
    //temp->next = NULL;
    free(temp);
    return tete;
}

node* remove_duplicated(node* tete)
{
    node* temp = tete;
    while(temp != NULL)
    {
        node* temp_1 = temp->next;
        if(temp->data == temp->next->data)
        {
            tete = remove_middle(tete, temp_1);

        }
        temp = temp->next;
    }
    return tete;
}
int main()
{
    srand (time(NULL));
    node* tete_1 = NULL;
    tete_1 = create_random(tete_1, 5);
    node* tete_2 = NULL;
    tete_2 = create_random(tete_2, 10);
    display_list(tete_1);
    display_list(tete_2);
    tete_1 = sort_list(tete_1);
    tete_2 = sort_list(tete_2);
    t_node* head = merge_list(tete_1, tete_2);
    display_list(tete);
    tete= remove_duplicated(tete);
    display_list(tete);
    return 0;
}

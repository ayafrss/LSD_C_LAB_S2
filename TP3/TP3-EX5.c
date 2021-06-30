#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* previous;
};
typedef struct node node;

struct file
{
    t_node* tete;
    t_node* tail;
};
typedef struct file file;

int empty(file file)
{
    if(file.tete == NULL && file.tail == NULL)
        return 1;
    return 0;
}

file* add_node_queue(file* file, int data)
{
    node* nouveau_node = (node*)malloc(sizeof(node));
    npuveau_node->data = data;
    nouveau_node->next = NULL;
    if(empty(*file) == 0)
    {
        file->tail->next = nouveau_node;
        file->tail = nouveau_node;
        return file;
    }
    else
    {
        file->tete = file->tail = nouveau_node;
        return queue;
    } 
}


int get_last_element(queue* queue)
{
    return queue->tail->data;
}

int readchar(){return getchar();}

int tasks_interval(int m)
{
    file* file = NULL;
    int resultat = 0;
    char string = readchar();
    file = add_node_queue(file, string);
    while(1)
    {
        char string = readchar();
        if(string == '\n')
            break;
        else
        {
            int z = get_last_element(queue);
            if(z == string)
                resultat += m;
            else
                resultat += 1;
            file = add_node_queue(file, string);
        }
    }
    return resultat;
}
int main()
{
    int resultat = tasks_interval(2);
    printf("Output: %d\n\n\n", resultat);
    return 0;
}

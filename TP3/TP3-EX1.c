#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node *next;
};
typedef struct node node;

node* creer(char data)
{
    node* nouveau_node = (node*)malloc(sizeof(node));
    if(nouveau_node = NULL)
    {
        printf("Error creating a new node");
        exit(0);
    }
    nouveau_node->data = data;
    nouveau_node->next = NULL;
    return nouveau_node;
}

node* node_ajout(node* head, char data)
{
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    node* nouveau_node = create(data);
    temp->next = nouveau_node;
    return temp;
}

node* stringTo_list(char string[], node* headlist)
{
    if(*string == ' ')
        return NULL;
    headlist = create(string[0]);
    node* temp = headlist;
    int i = 1;
    do
    {
        headlist = addnode(headlist, string[i]);
        i++;
    } while(i < sizeof(*string));
    return headlist;
}

int count(node* head)
{
    node* temp = head;
    int c = 0;
    while(temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}

int palindrome_check_opt(char string[])
{
    int k = strlen(string);
    int h = 0;
    if(strlen(string) == 1)
        return 0;
    for(int i = 0; i < k/2; i++)
    {
        if(string[h+i] != string[k-1-i])
            return 1;
    }
    return 0;
}
int main(int argc, char* argv[])
{
    if(argc < 2)
        printf("No argument passed through the command line.\n"); 
    else
    {
        printf("The string argument is: %s\n", argv[1]); 
        int l = palindrome_check_opt(argv[1]);
        if(palindrome_check_opt(argv[1]) == 0)
            printf("The string you entered is a palindrome.\n ");
        else
            printf("The string you entered is not a palindrome.\n");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int element;
	struct node * suivant;
};
typedef struct node node;
typedef struct node * list;

list create_node(int element);
void add_node(int element, list L);
list array_to_list(int size, int arr[]);
void print_list(list L);
void remove_node(list *L, int index);


list create_node(int element)
{
	list L = (node *)malloc(sizeof(node));
	L->element = element;
	L->suivant = NULL;
	return L;
}

void add_node(int element, list L)
{
	list temp = L;	
	list nouveau = create_node(element);
	if(L = NULL)
	{
		L = nouveau;
		return ;
	}
	while(temp->suivant != NULL)
		temp = temp->suivant;
	temp->suivant = nouveau;
	return ;
}

list array_to_list(int n, int arr[])
{
	list L = create_node(arr[0]); 
	for(int i=1; i < n; i++)
	{
		add_node(arr[i], L);
	}
	return L;
}

void print_list(list L)
{
	if(L == NULL)
		printf("[]");
	else
	{
		printf("[");
		list temp = L;
		while(temp->suivant != NULL)
		{
			printf("%d, ", temp->element);
			temp = temp->suivant;
		}
		if(temp!=NULL)
			printf("%d", temp->element);
		printf("]\n");
	}
}


void remove_node(list *L, int i)
{
	list temp = *L;
	unsigned l=0;
    if(*L!=NULL)
    {
        list temp=*L;
        while(temp!=NULL)
        {
            l+=1;
            temp=temp->suivant;
        }
    }
	if(i==0)
	{
		if(*L!=NULL)
		{
			list temp=*L;
			*L=(*L)->suivant;
			free(temp);
	}
		return;
	}
	else
	{
		list temp1 = *L;
        int j = 0;
        while(j<i-1)
        {
              temp1 = temp1->suivant;
              j++;
        }
        list temp2 = temp1;
        temp1= temp1->suivant;
        temp2->suivant = temp1->suivant;
        free(temp1);
        return ;
	}
}


int main()
{
	int x1,x2;
	printf("Entrer un nombre: \n");
	scanf("%d", &x1);
	list L = create_node(x1);
	printf("Entrer un nombre: \n");
	scanf("%d", &x2);
	add_node(x2, L);
	print_list(L);
	int arr[6] = {3, 4, 1, 9, 4, 6};
	list T = array_to_list(6, arr);
	print_list(T);
	remove_node(&T, 2);
	print_list(T);
	return 0;
}

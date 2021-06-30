#include <stdlib.h>
#include <stdio.h>

struct node
{
    int key;
    struct node* right;
    struct node* left;
};
typedef struct node node;


node* create_node(int key)
{
    node* new_node = (node*)malloc(sizeof(node));
    nouveau_node->key = key;
    nouveau_node->left = NULL;
    nouveau_node->right = NULL;
    return nouveau_node;
}

node* insert(node* binaryS_tree, int key)
{
    if(binaryS_tree == NULL)
        return create_node(key);
    node* nouveau_node = create_node(key);
    node* temp = binaryS_tree;
    node* temp_1 = NULL;
    while(temp != NULL)
    {
        if(temp->key > key)
        {
            temp_1 = temp;
            temp = temp->left;
        }
        if(temp->key < key)
        {
            temp_1 = temp;
            temp = temp->right;
        }
        else
            return NULL;
    }
    if(temp_1->key > key)
        temp_1->left = new_node;
    if(temp_1->key < key)
        temp_1->right = new_node;
    return temp_1;
}

int n_elem(node* binaryS_tree)
{
    int k = 1;
    if(binaryS_tree == NULL)
        return 0;
    k += n_elem(binaryS_tree->left) + n_elem(binaryS_tree->right);
    return k + 1;
}

int* convertBST_array(node* binaryS_tree, int* array)
{
    node* temp = binaryS_tree;
    node* temp_1 = NULL;
    array[0] = binaryS_tree->key;
    int i = 1;
    do
    {
        if(temp->right != NULL)
        {
            array[i] = temp->right->key;
            temp_1 = temp;
            temp = temp->right;
            i++;
        }
        else if(temp->left != NULL)
        {
            array[i] = temp->left->key;
            temp_1 = temp;
            temp = temp->left;
            i++;
        }    
    }while(temp != NULL);
    array[i] = temp_1->key; 
    return array;    
}

node* createBST_from_array(int* array, int s, int e) 
{
    if(s > e)
        return NULL;
    int m = (s+e)/2;
    node* balanced_BST = create_node(array[m]);
    balanced_BST->left = createBST_from_array(array, s, m-1);
    balanced_BST->right = createBST_from_array(array, m+1, e);
    return balanced_BST;
}

void print_BST(node* binaryS_tree)
{
    if(binaryS_tree == NULL)
        return;
    printf("%d  ",binaryS_tree->key);
    if(binaryS_tree->left == NULL || binaryS_tree->right == NULL)
        printf("NULL  ");
    print_BST(binaryS_tree->left);
    print_BST(binaryS_tree->right);
}
int main()
{
    node* binaryS_tree = NULL;
    binaryS_tree = insert(binaryS_tree, 1);
    binaryS_tree = insert(binaryS_tree, 2);
    binaryS_tree = insert(binaryS_tree, 3);
    print_BST(binaryS_tree);
    printf("\n\n");
    int* array = (int*)malloc(4*sizeof(int));
    array = convertBST_array(binaryS_tree, array);
    node* tree = createBST_from_array(array, 1, 4);
    print_BST(tree);
    printf("\n\n");
    return 0;
}

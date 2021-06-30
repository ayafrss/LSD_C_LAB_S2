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
    node* tete;
    node* tail;
};
typedef struct file file;

struct node_arbre 
{
    int cle;
    struct node_arbre* droite;
    struct node_arbre* gauche;
};
typedef struct node_arbre node_arbre;

int empty(file file)
{
    if(file.tete == NULL && file.tail == NULL)
        return 1;
    return 0;
}

file* add_node_queue(file* file, int data)
{
    node* nouveau_node = (node*)malloc(sizeof(node));
    nouveau_node->data = data;
    nouveau_node->next = NULL;
    if(empty(*file) == 0)
    {
        printf("TEST\n");
        file->tail->next = nouveau_node;
        file->tail = nouveau_node;
        return file;
    }
    else
    {
        file->tete = file->tail = nouveau_node;
        return file;
    } 
}

int remove_node_queue(file* file)
{
    if(file->tete != NULL)
    {
        int valeur = 0;
        valeur = file->tete->data;
        node* temp = file->tete;
        file->tete = temp->next;
        free(temp);
        return valeur;
    }
    else    
        exit(EXIT_FAILURE); 
}
//Max function
int max(int x, int y)
{
    if(x >= y)
        return x;
    else    
        return y;
}

node_arbre* create_tree(int cle, node_arbre* arbre_gauche, node_arbre* arbre_droite)
{
    node_arbre* binary_tree = (node_arbre*)malloc(sizeof(node_arbre));
    binary_tree->clecle
    binary_tree->gauche = arbre_gauche;
    binary_tree->doite = arbre_droite;
    return binary_tree;
}

int depth_recursive(node_arbrenary_tree)
{
    if(binary_tree == NULL)
        return 0;
    else
    {
        int depth_right = depth_recursive(binary_tree->droite);
        int depth_left = depth_recursive(binary_tree->gauche);
        if(depth_right > depth_left)
            return depth_right + 1;
        else    
            return depth_left + 1;
    }
}

int depth_iterative(node_arbrenary_tree)
{
    int depth = 0;
    if(binary_tree != NULL)
    {
        file* file = NULL;
        node_arbre* temp = binary_tree;
        add_node_queue(file, temp->cle);
        while(file != NULL)
        {
            temp->key = remove_node_queue(queue);
            if(temp->left != NULL)
                add_node_queue(queue, temp->left->key);
                depth++;
            if(temp->right != NULL)
                add_node_queue(queue, temp->right->key);
                depth++;
                if(temp->left != NULL && temp->right != NULL)
                    depth--;
        }
    }
    return depth;
}
//Calculating thed diameter of the tree
int diameter_recursive(t_node_tree* binary_tree)
{
    if(binary_tree == NULL)
        return 0;
    int depth_right = depth_recursive(binary_tree->right);
    int depth_left = depth_recursive(binary_tree->left);
    int diameter_right = diameter_recursive(binary_tree->right);
    int diameter_left = diameter_recursive(binary_tree->left);
    return max(depth_right + depth_left + 1, max(diameter_right, diameter_left));
}
//Calculate the sum of the leaves values (recursive)
int leaf_sum(t_node_tree* binary_tree, int sum)
{
    if(binary_tree == NULL)
        return 0;
    if(binary_tree->left == NULL && binary_tree->right == NULL)
    {
        sum = binary_tree->key;
        return sum;
    }
    int left_leafsum = leaf_sum(binary_tree->left, sum);
    int right_leafsum = leaf_sum(binary_tree->right, sum);
    return left_leafsum + right_leafsum;
}

/*int leaf_sum(t_node_tree* binary_tree)
{
    int sum = 0;
    if(binary_tree == NULL)
        return 0;
    queue* tmp_q = NULL;
    t_node_tree* temp = binary_tree;
    tmp_q = add_node_queue(tmp_q, temp->key);
    while(tmp_q != NULL)
    {
        temp->key = remove_node_queue(tmp_q);
        if(temp->left != NULL)
            tmp_q = add_node_queue(tmp_q, temp->left->key);
        else
            sum += temp->left->key;
        if(temp->right != NULL)
            tmp_q = add_node_queue(tmp_q, temp->right->key);
        else
            sum += temp->right->key;
    }
    return sum;
}*/
//menu
void menu()
{
    printf("---Binary Tree Demonstration ---\n\n");
    printf("0.Menu\n");
    printf("1.The depth/high of the tree\n");
    printf("2.The diameter of the tree\n");
    printf("3.The sum of leaves values\n");
    printf("4.Quit\n\n");
}
int main()
{
    int choice = 0;
    int k = 0;
    t_node_tree* left_binary_tree = NULL;
    t_node_tree* right_binary_tree = NULL;
    left_binary_tree = create_tree(1,NULL,NULL);
    right_binary_tree = create_tree(2, NULL, NULL);
    t_node_tree* binary_tree = create_tree(3, left_binary_tree, right_binary_tree);
    while(1)
    {
        printf("Enter a command(0-4) and 4 to quit: ");
        scanf("%d", &choice);
        if(choice == 4)
            break;
        switch(choice)
        {
            case 0:
                menu();
                break;
            case 1:
                k = depth_recursive(binary_tree);
                printf("the depth of the tree is: %d \n", k);
                break;
            case 2:
                k = diameter_recursive(binary_tree);
                printf("The diameter of the tree is %d\n", k);
                break;
            case 3:
                k = leaf_sum(binary_tree, k);
                printf("The sum of leaves values is %d\n", k);
                break;
            default:
                break;
        }
    }
    return 0;
}

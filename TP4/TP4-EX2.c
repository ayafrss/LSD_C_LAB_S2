#include <stdlib.h>
#include <stdio.h>

struct s_node
{
    int key;
    struct s_node* right;
    struct s_node* left;
};
typedef struct s_node t_node;

//Insert an element into the binary search tree (Iterative)
t_node* create_node(int key)
{
    t_node* new_node = (t_node*)malloc(sizeof(t_node));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
t_node* insert(t_node* binaryS_tree, int key)
{
    if(binaryS_tree == NULL)
        return create_node(key);
    t_node* new_node = create_node(key);
    t_node* temp = binaryS_tree;
    t_node* temp_1 = NULL;
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
//Search an element into the binary search tree (recursive)
t_node* search(t_node* binaryS_tree, int key)
{
    t_node* temp = NULL;
    if(binaryS_tree == NULL)
        exit(EXIT_FAILURE);
    if(binaryS_tree->key > key)
        return search(binaryS_tree->left, key);
    else
        return search(binaryS_tree->right, key);
}
//Print the maximum depth of the tree (recursive)
int max_depth(t_node* binary_tree)
{
    if(binary_tree == NULL)
        return 0;
    else
    {
        int depth_right = 0;
        int depth_left = 0;
        depth_left = max_depth(binary_tree->left);
        depth_right = max_depth(binary_tree->right);
        if(depth_right > depth_left)
        {
            printf("The maximum depth of the binary search tree is %d\n", depth_right + 1);
            return depth_right + 1;
        }
        else    
        {
            printf("The maximum depth of the binary search tree is %d\n", depth_left + 1);
            return depth_left + 1;
        }
    }
}
//Print the number of elements in the tree (recursive)
int n_elem(t_node* binaryS_tree)
{
    int k = 1;
    if(binaryS_tree == NULL)
        return 0;
    k += n_elem(binaryS_tree->left) + n_elem(binaryS_tree->right);
    return k + 1;
}
//menu
void menu()
{
    printf("---Binary Search Tree Demonstration ---\n\n");
    printf("0.Menu\n");
    printf("1.Insert an element into the binary search tree: \n");
    printf("2.Search an element into the binary search tree: \n");
    printf("3.Print the maximum depth of the tree: \n");
    printf("4.Print the number of elments in the tree: \n");
    printf("5.Quit\n");
}
int main()
{
    int choice = 0;
    int k = 0;
    t_node* binaryS_tree = NULL;
    t_node* temp = NULL;
    binaryS_tree = insert(binaryS_tree, 0);
    binaryS_tree = insert(binaryS_tree, 1);
    binaryS_tree = insert(binaryS_tree, 3);
    menu();
    while(1)
    {
        printf("Enter a command(0-5) and 5 to quit: ");
        scanf("%d", &choice);
        if(choice == 5)
            break;
        switch(choice)
        {
            case 0:
                menu();
                break;
            case 1:
                printf("Type the number you want to insert in the tree:");
                scanf("%d", &k);
                binaryS_tree = insert(binaryS_tree, k);
                continue;
                break;
            case 2:
                printf("Type the number you are searching for in the tree: ");
                scanf("%d", &k);
                temp = search(binaryS_tree, k);
                printf("TEST");
                continue;
                if(temp != NULL)
                    printf("The element %d does exist in the tree", k);
                else
                    printf("The element %d does not exist in the tree", k);
                break;
            case 3:
                max_depth(binaryS_tree);
                break;
            case 4:
                k = n_elem(binaryS_tree);
                printf("The number of elements in the tree is %d \n", k);
                break;
            default:
                break;
        }
    }
    return 0;
}
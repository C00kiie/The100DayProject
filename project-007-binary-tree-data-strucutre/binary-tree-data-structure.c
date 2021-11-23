#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int data;
    struct node_t* right;
    struct node_t* left;

    // member functions
    void (*debug)(struct node_t* this);
} node_t;


int insert(node_t** root, int value){
    // create a temp pointer to root, and use it
    node_t* temp = *root;

    // check if root is not null, if null make it
    if(temp == NULL){
        create_tree_node(root, value);
        return 0;
    }

    // check if left and right are null
    while(1){
        if (temp->data <= value){
            // now go right
            if (temp->right == NULL){
                create_tree_node(&temp->right, value);
                return 0;
            }
            temp = temp->right;
        }
        if(temp->data > value){
            // now go left
            if (temp->left == NULL){
                create_tree_node(&temp->left, value);
                return 0;
            }
            temp = temp->left;
        } 
    }

    return -1;
}
int create_tree_node(node_t** node, int value){
    *node = (node_t*) malloc(sizeof(node_t));
    if (*node == NULL)
    {
        perror("unable to allocate @17");
        exit(-1);
    }
    (*node)->data = value;
    return 0;
}

#define COUNT 1;
void print2DUtil(node_t *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = 0; i < space; i++)
    {
                printf(" ");
    }
    printf("%i\n",root->data);
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(node_t* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}
 
int main(){
    node_t* root = NULL;
    insert(&root, 1);
    //printf("%d", root->data);
    insert(&root,2);
    //printf("%d",root->right->data);
    insert(&root,0);
    insert(&root,0);
    insert(&root,0);
    insert(&root,0);
    insert(&root, 128);
    insert(&root, 4);
    insert(&root, 3);
    //printf("%d",root->left->data);
    
    print2D(root);

} 
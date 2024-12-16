
                                          /*     1
                             2                                   3
             4                            5                    6   -1(null)
  -1(null)      -1(null)         -1(null)   -1(null)  -1(null)  -1(null)*/



#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *createNode(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void inorderTraversal(struct node* root) {
  
    // Empty Tree
    if (root == NULL)
        return;
  
    inorderTraversal(root->left);
  
    printf("%d ", root->data);
  
    
    inorderTraversal(root->right);
}
void preorderTraversal(struct node* root) {
  
    if (root == NULL)
        return;

    printf("%d ", root->data);
  
    preorderTraversal(root->left);
  
    preorderTraversal(root->right);
}
void postorderTraversal(struct node* node) {
   
    if (node == NULL)
        return;
  
    postorderTraversal(node->left);

    postorderTraversal(node->right);
  
    printf("%d ", node->data);
}

struct node *insertNode() {
    int data;
    printf("Enter data : ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct node *root = createNode(data);
    printf("Enter left child of %d:\n", data);
    root->left = insertNode();

    printf("Enter right child of %d:\n", data);
    root->right = insertNode();

    return root;
}

int main() {
    struct node *root = NULL;
    printf("Constructing binary tree:\n");
    root = insertNode();
    
    printf("\nInorder traversal of the tree:\n");
    inorderTraversal(root);
    printf("\npreorder traversal of the tree:\n");
    preorderTraversal(root);
    printf("\npostorder traversal of the tree:\n");
    postorderTraversal(root);

    return 0;
}

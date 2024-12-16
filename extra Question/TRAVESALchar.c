#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *left, *right;
};

struct node *createNode(char data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void inorderTraversal(struct node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%c ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(struct node* root) {
    if (root == NULL)
        return;

    printf("%c ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct node* root) {
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%c ", root->data);
}

struct node *insertNode() {
    char data;
    printf("Enter data ('N' for null): ");
    scanf(" %c", &data);

    if (data == 'N') {
        return NULL;
    }

    struct node *root = createNode(data);
    printf("Enter left child of %c:\n", data);
    root->left = insertNode();

    printf("Enter right child of %c:\n", data);
    root->right = insertNode();

    return root;
}

int main() {
    struct node *root = NULL;
    printf("Constructing binary tree:\n");
    root = insertNode();

    printf("\nInorder traversal of the tree:\n");
    inorderTraversal(root);

    printf("\nPreorder traversal of the tree:\n");
    preorderTraversal(root);

    printf("\nPostorder traversal of the tree:\n");
    postorderTraversal(root);

    return 0;
}

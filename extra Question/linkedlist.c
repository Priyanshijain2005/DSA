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

void display(struct node *root) {
    if (root == NULL) {
        return;
    }
    display(root->left);
    printf(" %d ", root->data);
    display(root->right);
}

int main() {
    struct node *root = NULL;
    printf("Constructing binary tree:\n");
    root = insertNode();
    
    printf("\nInorder traversal of the tree:\n");
    display(root);

    return 0;
}

#include<stdio.h>
#include<stdlib.h>

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

struct node *insertNode(struct node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}


struct node* search(struct node*root,int data){
        if(root==NULL){
           return 0;
        }

        if(root->data==data){
           return root;
        }
        else{
            if(root->data>data){
                return search(root->left, data);
            }
            else{
               return search(root->right,data);
            }
        }
}
void preorderTraversal(struct node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preorderTraversal(root->left);
  
    preorderTraversal(root->right);
}

int main() {
    struct node *root = NULL;

    int data,searchVal;

    root=insertNode(root, 4);
    root=insertNode(root, 2);
    root=insertNode(root, 7);
    root=insertNode(root, 1);
    root=insertNode(root, 3);


    printf("Enter value to search: ");
    scanf("%d", &searchVal);

    struct node *ans = search(root, searchVal);
    preorderTraversal(ans);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insertNode(struct Node *root, int data) {
    if (root == NULL) return createNode(data);
    printf("Insert as left or right of %d? (l/r): ", root->data);
    char direction;
    scanf(" %c", &direction);

    if (direction == 'l') root->left = insertNode(root->left, data);
    else root->right = insertNode(root->right, data);
    return root;
}

void displayTree(struct Node *root, int space) {
    if (root == NULL) return;

    space += 5;
    displayTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++) printf(" ");
    printf("%d\n", root->data);
    displayTree(root->left, space);
}

void preOrder(struct Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct Node *root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(struct Node *root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

struct Node *findNode(struct Node *root, int data) {
    if (root == NULL || root->data == data) return root;
    struct Node *left = findNode(root->left, data);
    if (left) return left;
    return findNode(root->right, data);
}
void extractChildren(struct Node *root, int parent) {
    struct Node *node = findNode(root, parent);
    if (node) {
        printf("Left child: %d\n", node->left ? node->left->data : -1);
        printf("Right child: %d\n", node->right ? node->right->data : -1);
    } else {
        printf("Parent node not found.\n");
    }
}


int main() {
    struct Node *root = NULL;
    int choice, data, parent;
        while (1) {
            printf("\n1. Insert Node\n2. Display Tree\n3. Pre-order Traversal\n4. In-order Traversal\n5. Post-order Traversal\n6. Extract Children\n7. Exit\n");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Enter data to insert: ");
                    scanf("%d", &data);
                    root = insertNode(root, data);
                    break;
                case 2:
                    displayTree(root, 0);
                    break;
                case 3:
                    preOrder(root);
                    printf("\n");
                    break;
                case 4:
                    inOrder(root);
                    printf("\n");
                    break;
                case 5:
                    postOrder(root);
                    printf("\n");
                    break;
                case 6:
                    printf("Enter parent node: ");
                    scanf("%d", &parent);
                    extractChildren(root, parent);
                    break;
                case 7:
                    exit(0);
            }
        }

       
    
    return 0;
}

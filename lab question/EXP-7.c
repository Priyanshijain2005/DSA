#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int tree[MAX_SIZE];

int arrayIndex = -1;

void createTreeArray(int data) {
    if (arrayIndex >= MAX_SIZE - 1) {
        printf("Tree is full.\n");
        return;
    }
    tree[++arrayIndex] = data;
}

void displayTreeArray(int index, int space) {
    if (index > arrayIndex) return;

    space += 5;
    displayTreeArray(2 * index + 2, space);
    printf("\n");
    for (int i = 5; i < space; i++) printf(" ");
    printf("%d\n", tree[index]);
    displayTreeArray(2 * index + 1, space);
}

void traversePreOrderArray(int index) {
    if (index > arrayIndex) return;
    printf("%d ", tree[index]);
    traversePreOrderArray(2 * index + 1);
    traversePreOrderArray(2 * index + 2);
}

void traverseInOrderArray(int index) {
    if (index > arrayIndex) return;
    traverseInOrderArray(2 * index + 1);
    printf("%d ", tree[index]);
    traverseInOrderArray(2 * index + 2);
}

void traversePostOrderArray(int index) {
    if (index > arrayIndex) return;
    traversePostOrderArray(2 * index + 1);
    traversePostOrderArray(2 * index + 2);
    printf("%d ", tree[index]);
}

void extractChildrenArray(int parent) {
    if (parent > arrayIndex) {
        printf("Parent index out of range.\n");
        return;
    }
    printf("Left child: %d\n", (2 * parent + 1 <= arrayIndex) ? tree[2 * parent + 1] : -1);
    printf("Right child: %d\n", (2 * parent + 2 <= arrayIndex) ? tree[2 * parent + 2] : -1);
}

// Main Function
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
                    createTreeArray(data);
                    break;
                case 2:
                    displayTreeArray(0, 0);
                    break;
                case 3:
                    traversePreOrderArray(0);
                    printf("\n");
                    break;
                case 4:
                    traverseInOrderArray(0);
                    printf("\n");
                    break;
                case 5:
                    traversePostOrderArray(0);
                    printf("\n");
                    break;
                case 6:
                    printf("Enter parent node index: ");
                    scanf("%d", &parent);
                    extractChildrenArray(parent);
                    break;
                case 7:
                    exit(0);
            }
        }
    
    return 0;
}


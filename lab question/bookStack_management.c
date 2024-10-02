#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int top = -1;
char stack[SIZE]; // Change to char to store book titles

void push(char stack[], char ch) {
    if (top == SIZE - 1) {
        printf("Library is full\n");
    } else {
        stack[++top] = ch;
        printf("%c book is returned to the library\n", ch);
    }
}

void pop(char stack[]) {
    if (top == -1) {
        printf("Library is empty\n");
    } else {
        char book = stack[top--];
        printf("%c book is issued from the library\n", book);
    }
}

void peek(char stack[]) {
    if (top == -1) {
        printf("Library is empty\n");
    } else {
        char book = stack[top];
        printf("%c is the most recent book\n", book);
    }
}

void display(char stack[]) {
    if (top == -1) {
        printf("No books in the stack\n");
    } else {
        printf("All books are: ");
        for (int i = 0; i <= top; i++) {
            printf("%c ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    char ch;

    printf("Welcome to the Bookstack Management System!\n");

    do {  
        printf("\nMenu:\n");
        printf("1. Add a book\n");
        printf("2. Remove the most recent book\n");
        printf("3. View the most recent book\n");
        printf("4. Display all books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left in the buffer

        switch (choice) {
            case 1:
                printf("Enter the book (single character): ");
                scanf("%c", &ch);
                push(stack, ch);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                peek(stack);
                break;
            case 4:
                display(stack);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Enter a valid choice\n");
        }
    } while (choice != 5);

    return 0;
}

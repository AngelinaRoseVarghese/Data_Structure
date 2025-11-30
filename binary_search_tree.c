#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

int main() {
    struct node *root = NULL, *current, *parent, *newNode, *successor, *successorParent;
    int choice, value;

    while (1) {
        printf("\nChoose action: 1.Insert 2.Delete 3.Search 4.Exit: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting program.\n");
            break;
        }

        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &value);

            newNode = (struct node*)malloc(sizeof(struct node));
            newNode->data = value;
            newNode->left = newNode->right = NULL;

            if (root == NULL) {
                root = newNode;
            } else {
                current = root; parent = NULL;
                while (current != NULL) {
                    parent = current;
                    if (value < current->data) current = current->left;
                    else current = current->right;
                }
                if (value < parent->data) parent->left = newNode;
                else parent->right = newNode;
            }
            printf("Node %d inserted.\n", value);
        }

        else if (choice == 2) {
            printf("Enter value to delete: ");
            scanf("%d", &value);

            current = root; parent = NULL;
            while (current != NULL && current->data != value) {
                parent = current;
                if (value < current->data) current = current->left;
                else current = current->right;
            }

            if (current == NULL) {
                printf("Value %d not found.\n", value);
            } 
            else if (current->left == NULL && current->right == NULL) {
                if (parent == NULL) root = NULL;
                else if (parent->left == current) parent->left = NULL;
                else parent->right = NULL;
                free(current);
                printf("Node %d deleted.\n", value);
            } 
            else if (current->left == NULL || current->right == NULL) {
                struct node *child = (current->left != NULL) ? current->left : current->right;
                if (parent == NULL) root = child;
                else if (parent->left == current) parent->left = child;
                else parent->right = child;
                free(current);
                printf("Node %d deleted.\n", value);
            } 
            else {
                successorParent = current; successor = current->right;
                while (successor->left != NULL) { successorParent = successor; successor = successor->left; }
                current->data = successor->data;
                if (successorParent->left == successor) successorParent->left = successor->right;
                else successorParent->right = successor->right;
                free(successor);
                printf("Node %d deleted.\n", value);
            }
        }

        else if (choice == 3) {
            printf("Enter value to search: ");
            scanf("%d", &value);

            current = root;
            while (current != NULL && current->data != value) {
                if (value < current->data) current = current->left;
                else current = current->right;
            }

            if (current != NULL) printf("Value %d found in the tree.\n", value);
            else printf("Value %d not found in the tree.\n", value);
        }

        else {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        // Print tree inorder
        struct node *stack[50]; int top = -1; current = root;
        printf("Current Tree (Inorder): ");
        while (current != NULL || top != -1) {
            while (current != NULL) { stack[++top] = current; current = current->left; }
            current = stack[top--]; printf("%d ", current->data); current = current->right;
        }
        printf("\n");
    }

    return 0;
}

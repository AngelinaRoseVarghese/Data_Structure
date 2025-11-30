#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* create(int value) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = value;
    n->left = n->right = NULL;
    return n;
}

struct node* insert(struct node* root, int value) {
    if (root == NULL) return create(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

struct node* findMin(struct node* root) {
    while (root->left) root = root->left;
    return root;
}

struct node* delete(struct node* root, int value) {
    if (root == NULL) return root;

    if (value < root->data)
        root->left = delete(root->left, value);
    else if (value > root->data)
        root->right = delete(root->right, value);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }

    return root;
}

int search(struct node* root, int value) {
    if (root == NULL) return 0;
    if (root->data == value) return 1;
    if (value < root->data) return search(root->left, value);
    return search(root->right, value);
}

void inorder(struct node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node *root = NULL;
    int ch, value;

    while (1) {
        printf("\n1.Insert 2.Delete 3.Search 4.Exit\nEnter choice: ");
        scanf("%d", &ch);

        if (ch == 4) break;

        printf("Enter value: ");
        scanf("%d", &value);

        if (ch == 1) root = insert(root, value);
        else if (ch == 2) root = delete(root, value);
        else if (ch == 3) {
            if (search(root, value)) printf("Found\n");
            else printf("Not Found\n");
        }
        else printf("Invalid choice");

        printf("Inorder: ");
        inorder(root);
        printf("\n");
    }
    return 0;
}

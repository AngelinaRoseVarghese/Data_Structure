#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int main() {

    struct Node *root = NULL;
    struct Node *cur, *prev, *newNode, *succ, *succPrev;

    int choice, value;

    while (1) {

        printf("\n1.Insert  2.Search  3.Delete  4.Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 4) break;

        printf("Enter value: ");
        scanf("%d", &value);

        /* -------- INSERT -------- */
        if (choice == 1) {

            newNode = malloc(sizeof(struct Node));
            newNode->data = value;
            newNode->left = newNode->right = NULL;

            if (root == NULL) {
                root = newNode;
            } else {
                cur = root;

                while (cur != NULL) {
                    prev = cur;
                    if (value < cur->data)
                        cur = cur->left;
                    else
                        cur = cur->right;
                }

                if (value < prev->data)
                    prev->left = newNode;
                else
                    prev->right = newNode;
            }
        }

        /* -------- SEARCH -------- */
        else if (choice == 2) {

            cur = root;
            while (cur && cur->data != value) {
                if (value < cur->data)
                    cur = cur->left;
                else
                    cur = cur->right;
            }

            if (cur) printf("Found");
            else     printf("Not Found");
        }

        /* -------- DELETE -------- */
        else if (choice == 3) {

            cur = root;
            prev = NULL;

            /* Find node */
            while (cur && cur->data != value) {
                prev = cur;
                if (value < cur->data)
                    cur = cur->left;
                else
                    cur = cur->right;
            }

            if (!cur) {
                printf("Not Found");
                continue;
            }

            /* Case 1: No children */
            if (!cur->left && !cur->right) {

                if (prev == NULL)
                    root = NULL;
                else if (prev->left == cur)
                    prev->left = NULL;
                else
                    prev->right = NULL;

                free(cur);
            }

            /* Case 2: One child */
            else if (!cur->left || !cur->right) {

                struct Node *child = cur->left ? cur->left : cur->right;

                if (prev == NULL)
                    root = child;
                else if (prev->left == cur)
                    prev->left = child;
                else
                    prev->right = child;

                free(cur);
            }

            /* Case 3: Two children */
            else {

                succPrev = cur;
                succ = cur->right;

                while (succ->left != NULL) {
                    succPrev = succ;
                    succ = succ->left;
                }

                cur->data = succ->data;

                if (succPrev->left == succ)
                    succPrev->left = succ->right;
                else
                    succPrev->right = succ->right;

                free(succ);
            }
        }

        /* -------- INORDER PRINT -------- */
        printf("\nInorder: ");
        struct Node *stack[50];
        int top = -1;

        cur = root;

        while (cur || top != -1) {

            while (cur) {
                stack[++top] = cur;
                cur = cur->left;
            }

            cur = stack[top--];
            printf("%d ", cur->data);
            cur = cur->right;
        }
    }

    return 0;
}

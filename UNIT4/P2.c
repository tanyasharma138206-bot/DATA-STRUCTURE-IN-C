#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int data)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
struct Node* insert(struct Node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        printf("Duplicate values are not allowed!\n");

    return root;
}
struct Node* findMin(struct Node *root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}
struct Node* deleteNode(struct Node *root, int data)
{
    struct Node *temp;

    if (root == NULL)
    {
        printf("Value not found in the tree!\n");
        return NULL;
    }

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}
int height(struct Node *root)
{
    int leftHeight, rightHeight;

    if (root == NULL)
        return 0;

    leftHeight = height(root->left);
    rightHeight = height(root->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}
int countNodes(struct Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left)
             + countNodes(root->right);
}
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void freeTree(struct Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main()
{
    struct Node *root = NULL;
    int choice, value;

    do
    {
        printf("\n\n--- BINARY SEARCH TREE MENU ---\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Height of Tree\n");
        printf("4. Total Number of Nodes\n");
        printf("5. Display Tree (Inorder)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            freeTree(root);
            return 1;
        }

        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                if (scanf("%d", &value) != 1)
                {
                    printf("Invalid input!\n");
                    freeTree(root);
                    return 1;
                }

                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                if (scanf("%d", &value) != 1)
                {
                    printf("Invalid input!\n");
                    freeTree(root);
                    return 1;
                }

                if (root == NULL)
                    printf("Tree is empty!\n");
                else
                    root = deleteNode(root, value);
                break;

            case 3:
                printf("Height of the tree: %d\n", height(root));
                break;

            case 4:
                printf("Total number of nodes: %d\n",
                       countNodes(root));
                break;

            case 5:
                if (root == NULL)
                    printf("Tree is empty!\n");
                else
                {
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 6);

    freeTree(root);

    return 0;
}



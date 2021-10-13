#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root, int value)
{
    struct node *temp;
    if (root == NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = value;
        temp->left = NULL;
        temp->right = NULL;
        root = temp;
    }
    else
    {
        //printf("%d", root->data);
        if (value < root->data)
            root->left = insert(root->left, value);
        else
            root->right = insert(root->right, value);
    }
    return root;
}

struct node *search(struct node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data == value)
    {
        return root;
    }
    else
    {
        if (value < root->data)
        {
            return search(root->left, value);
        }
        else
        {
            return search(root->right, value);
        }
    }
}

/**
 * Given a node, find out node with minimum value in left sub-tree
 */
struct node *minLeft(struct node *node)
{
    struct node *current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

struct node *delete (struct node *root, int value)
{
    if (root == NULL)
    {
        printf("Element to be deleted is not found");
        return root;
    }
    if (value < root->data)
    {
        root->left = delete (root->left, value);
    }
    else if (value > root->data)
    {
        root->right = delete (root->right, value);
    }
    else
    {
        //element found at root
        if (root->left == NULL)
        {
            //left is null, therefor right child will take position of root node
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            //right is null, therefore left child will take position of root node
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        //both children exists,
        //Get the inorder successor in right subtree
        struct node *temp = minLeft(root->right);
        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    }
    return root;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d, ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d, ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d, ", root->data);
    }
}

int main()
{
    int choice, value;
    struct node *root, *temp;
    root = (struct node *)malloc(sizeof(struct node));
    root = NULL;
    while (1)
    {
        printf("\n Menu : \n\t 1. Insert \n\t 2. Inorder \n\t 3. Preorder \n\t 4. Postorder \n\t 5. Search \n\t 6. Delete \n\t 7. Exit \n Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            //insert
            printf("Enter value to be inserted : ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            //inorder
            printf("Inorder traversal : ");
            inorder(root);
            break;
        case 3:
            //preorder
            printf("Preorder traversal : ");
            preorder(root);
            break;
        case 4:
            //postorder
            printf("Postorder traversal : ");
            postorder(root);
            break;
        case 5:
            //search
            printf("Enter value to be searched : ");
            scanf("%d", &value);
            temp = search(root, value);
            if (temp == NULL)
            {
                printf("Element not found");
            }
            else
            {
                printf("Element found");
            }
            break;
        case 6:
            //delete
            printf("Enter element to be deleted :");
            scanf("%d", &value);
            root = delete (root, value);
            break;
        case 7:
            //exit
            return 0;
        default:
            printf("Invalid choice, Try again");
        }
    }
}
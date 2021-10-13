#include <stdio.h>
#include <stdlib.h>

int count = 0;

struct node
{
    int value;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root, int value)
{
    struct node *temp;

    if (root == NULL)
    {
        //null tree, so assign root to temp
        temp = (struct node *)malloc(sizeof(struct node) * 1);
        temp->value = value;
        temp->left = NULL;
        temp->right = NULL;
        count = count + 1;
        root = temp;
    }
    else
    {
        if (root->left == NULL)
        {
            root->left = insert(root->left, value);
        }
        else
        {
            root->right = insert(root->right, value);
        }
        /*
        else
        {
            if (count % 2 != 0)
            {
                //insert at the left
                root->left = insert(root->left, value);
            }
            else
            {
                //insert at the right
                root->right = insert(root->right, value);
            }
        }
        */
    }
    return root;
}

void inorder(struct node *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d -> ", node->value);
        inorder(node->right);
    }
}

void preorder(struct node *node)
{
    if (node != NULL)
    {
        printf("%d -> ", node->value);
        inorder(node->left);
        inorder(node->right);
    }
}

void postorder(struct node *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        inorder(node->right);
        printf("%d -> ", node->value);
    }
}

int main(int argc, char const *argv[])
{
    struct node *root;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);
    printf("Inorder traversl \n");
    inorder(root);
    printf("\n################ \n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *left;
    struct node *right;
    struct node *parent;
};
struct node *traversal[10];
int count = 0;

struct node *insert(struct node *parent, struct node *root, int newValue)
{
    if (root == NULL)
    {
        //tree is blank
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node) * 1);
        temp->value = newValue;
        temp->left = NULL;
        temp->right = NULL;
        temp->parent = parent;
        root = temp;
    }
    else
    {
        //tree is not empty
        if (newValue <= root->value)
        {
            //insert at left of root
            root->left = insert(root, root->left, newValue);
        }
        else
        {
            //insert at right of lef
            root->right = insert(root, root->right, newValue);
        }
    }
    return root;
}

void inorder(struct node *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d ->", node->value);
        traversal[count++] = node;
        inorder(node->right);
    }
}

int search(struct node *root, int key)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        if (root->value == key)
        {
            return 1;
        }
        else
        {
            if (key < root->value)
            {
                // may be on left
                return search(root->left, key);
            }
            else
            {
                // search on right
                return search(root->right, key);
            }
        }
    }
}

int degree(struct node *node)
{
    if (node->left == NULL && node->right == NULL)
    {
        return 0;
    }
    else
    {
        if (node->left != NULL && node->right != NULL)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
}
struct node *n_search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        if (root->value == key)
        {
            return root;
        }
        else
        {
            if (key < root->value)
            {
                // may be on left
                return n_search(root->left, key);
            }
            else
            {
                // search on right
                return n_search(root->right, key);
            }
        }
    }
}

struct node *delete (struct node *root, int key)
{
    struct node *target;
    struct node *parent;
    struct node *candidate;
    int i;
    target = n_search(root, key);
    if (target == NULL)
    {
        printf("Element not found");
        return root;
    }
    switch (degree(target))
    {
    case 0:
        /* code */
        parent = target->parent;
        if (target->value <= parent->value)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
        free(target);
        break;
    case 1:
        parent = target->parent;
        if (target->value <= parent->value)
        {
            //set left of parent
            if (target->left != NULL)
            {
                parent->left = target->left;
            }
            else
            {
                parent->left = target->right;
            }
        }
        else
        {
            //set right of parent
            if (target->left != NULL)
            {
                parent->right = target->left;
            }
            else
            {
                parent->right = target->right;
            }
        }
        free(target);
        break;
    case 2:
        //find inorder pred of target node
        for (i = 0; i < count; i++)
        {
            if (traversal[i] == target)
            {
                break;
            }
        }
        if (i > 0)
        {
            candidate = traversal[i - 1];
            //update candidate parent
            if (candidate->value > candidate->parent->value)
            {
                candidate->parent->right = NULL;
            }
            else
            {
                candidate->parent->left = NULL;
            }

            //update candidate children
            candidate->left = target->left;
            candidate->right = target->right;
            candidate->parent = target->parent;
            //if target is root node
            if (candidate->parent == NULL)
            {
                root = candidate;
            }
        }
        free(target);
    default:
        break;
    }
    return root;
};

int main(int argc, char const *argv[])
{
    struct node *root;
    struct node *temp;
    root = insert(NULL, root, 13);
    root = insert(NULL, root, 12);
    root = insert(NULL, root, 5);
    root = insert(NULL, root, 23);
    root = insert(NULL, root, 36);
    root = insert(NULL, root, 48);
    root = insert(NULL, root, 19);
    printf("\n Inorder traversal ######### \n");
    inorder(root);
    //root = delete(root, 12);

    //inorder(root);
    root = delete (root, 13);
    printf("\n Inorder traversal ######### \n");
    count = 0;
    inorder(root);
    return 0;
}

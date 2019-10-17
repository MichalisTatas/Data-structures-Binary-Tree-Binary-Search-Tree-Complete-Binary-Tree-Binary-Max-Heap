#include "binary-tree.h"
#include "queues.h"

BTtree* BTCreate(int maxelem)
{
    BTtree* tree = malloc(sizeof(BTtree));
    tree->root = NULL;
    return tree;
}

int Height(BTnode* node, BTtree* tree)
{
    if(node == NULL || tree == NULL)
        return 0;
    else
    {
        int left = Height(node->left, tree);
        int right = Height(node->right, tree);
        if(left > right)
            return (left + 1);
        else 
            return (right + 1);
    }
}

int BTHeight(BTtree* tree)
{
    return Height(tree->root, tree);
}

int Size(BTnode* node, BTtree* tree)
{
    if(node == NULL || tree == NULL)
        return 0;
    else
        return (Size(node->left, tree) + Size(node->right, tree) + 1);
}

int BTSize(BTtree* tree)
{
        return Size(tree->root, tree);
}

BTnode* BTGetRoot(BTtree* tree)
{
    if(tree->root != NULL)
        return tree->root;
    else 
        return NULL;
}

BTnode* BTGetParent(BTtree* tree, BTnode* node)
{
    if(node->parent != NULL)
        return node->parent;
    else 
        return NULL;
}

BTnode* BTGetChildLeft(BTtree* tree, BTnode* node)
{
    if(node->left != NULL)
    {
        return node->left;
    }
    else
        return NULL;
}

BTnode* BTGetChildRight(BTtree* tree, BTnode* node)
{
    if(node->right != NULL)
    {
        return node->right;
    }
    else
        return NULL;
}

bool BTIsNil(BTnode* node)
{
    if(node == NULL)
        return true;
    else 
        return false;
}

BTItemType BTGetItem(BTtree* tree, BTnode* node)
{
        return node->data;
}

void BTInsertRoot(BTtree* tree, BTItemType item)
{
    if(tree->root == NULL)
    {
        tree->root = malloc(sizeof(BTnode));
        tree->root->data = item;
        tree->root->left = NULL;
        tree->root->right = NULL;
        tree->root->parent = NULL;
    }
    else 
    {
        printf("error tree isn't empty\n");
        return ;
    }
}

void BTInsertLeft(BTtree* tree, BTnode* node, BTItemType item)
{
    if(node->left == NULL)
    {
        node->left = malloc(sizeof(BTnode));
        node->left->data = item;
        node->left->right = NULL;
        node->left->left = NULL;
        node->left->parent = node;
    }
    else
    {
        printf("error left child isn't empty\n");
        return ;
    }
}

void BTInsertRight(BTtree* tree, BTnode* node, BTItemType item)
{
    if(node->right == NULL)
    {
        node->right = malloc(sizeof(BTnode));
        node->right->data = item;
        node->right->left = NULL;
        node->right->right = NULL;
        node->right->parent = node;
    }
    else
    {
        printf("error right child isn't empty\n");
        return ;
    }
}

BTnode* findSuccessor(BTnode* node)
{
    while(node && node->left != NULL)
        node = node->left;
    return node;
}

void BTRemove(BTtree* tree, BTnode* node)
{
    BTnode* temp = node->parent;
    if(node->right == NULL && node->left == NULL)       //node has no childs
    {
        if(temp->left == node)
        {
            free(temp->left);
            temp->left = NULL;
        }
        else 
        {
            free(temp->left);
            temp->right = NULL;
        }
    }
    else if(node->right == NULL && node->left != NULL)  //node has left child
    {
        if(temp->left == node)
        {
            temp->left = node->left;
            free(node);
        }
        else 
        {
            temp->right = node->left;
            free(node);
        }
    }
    else if(node->right != NULL && node->left == NULL)  //node has right child
    {
        if(temp->left == node)
        {
            temp->left = node->right;
            free(node);
        }
        else 
        {
            temp->right = node->right;
            free(node);
        }
    }
    else if(node->right != NULL && node->left != NULL)  //node has both childs
    {
        BTnode* temp = malloc(sizeof(BTnode)); 
        temp = findSuccessor(node->right);
        BTChange(tree, node, temp->data);
        free(temp);
    }
}

void BTChange(BTtree* tree, BTnode* node, BTItemType item)
{
    if(node != NULL)
        node->data = item;
    else printf("cannot change data node is empty\n");
}

void preorder(BTnode* node,BTtree* tree, void (*visit)(BTnode* node))
{
    if(node == NULL)
        return;
    visit(node);
    preorder(node->left, tree, visit);
    preorder(node->right, tree, visit);
}

void BTPreOrder(BTtree* tree, void (*visit)(BTnode* node))
{
    if(tree->root != NULL)
    {
        printf("Preorder traversal is : ");
        preorder(tree->root, tree, visit);
        printf("\n");
    }
    else printf("cannot traverse preorder since tree is empty\n");
}

void inorder(BTnode* node, BTtree* tree, void (*visit)(BTnode* node))
{
    if(node == NULL)
        return;
    inorder(node->left, tree, visit);
    visit(node);
    inorder(node->right, tree, visit);
}

void BTInOrder(BTtree* tree, void (*visit)(BTnode* node))
{
    if(tree->root != NULL)
    {
        printf("Inorder traversal is : ");
        inorder(tree->root, tree, visit);
        printf("\n");
    }
    else printf("cannot traverse inorder since tree is empty\n");
}

void postorder(BTnode* node, BTtree* tree, void (*visit)(BTnode* node))
{
    if(node == NULL)
        return;
    postorder(node->left, tree, visit);
    postorder(node->right, tree, visit);
    visit(node);
}


void BTPostOrder(BTtree* tree, void (*visit)(BTnode* node))
{
    if(tree->root != NULL)
    {
        printf("Postorder traversal is : ");
        postorder(tree->root, tree, visit);
        printf("\n");
    }
    else printf("cannot traverse postorder since tree is empty\n");
}

void BTLevelOrder(BTtree* tree, void (*visit)(BTnode* node))
{
    printf("Levelorder traversal is : ");
    if(tree->root == NULL)
        return;
    Queue Q;
    InitializeQueue(&Q);
    Insert(tree->root, &Q);
    while(!Empty(&Q))
    {
        BTnode* temp = Remove(&Q);
        visit(temp);
        if(temp->left!=NULL) 
            Insert(temp->left, &Q);
        if(temp->right!=NULL)
            Insert(temp->right, &Q);
    }
    printf("\n");
}

void destroy(BTnode* node, BTtree* tree)
{
    if(node != NULL)
    {
        destroy(node->right, tree);
        destroy(node->left, tree);
        free(node);
    }
}

void BTDestroy(BTtree* tree)
{
    destroy(tree->root, tree);
    free(tree);
}
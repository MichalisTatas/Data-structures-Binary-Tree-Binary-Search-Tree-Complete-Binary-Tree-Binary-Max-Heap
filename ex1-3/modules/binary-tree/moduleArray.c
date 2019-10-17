#include "modules.h"
#include "queues.h"

void print(BTnode* node)
{
    printf("%d ",node->data);
}

BTtree* BTCreate(int maxelem)
{
    BTtree* tree = malloc(sizeof(BTtree));
    tree->arraySize = maxelem;
    tree->root = malloc((maxelem+1)*sizeof(BTnode*));
    for(int i=0; i<=maxelem; i++)
    {
        tree->root[i] = malloc(sizeof(BTnode));
        tree->root[i] = NULL;
    }    
    return tree;
}

int Height(BTnode* node, BTtree* tree)
{
    if(node == NULL || 2*node->position > tree->arraySize || (2*node->position+1) > tree->arraySize)
            return 0;
        else
        {
            int left = Height(tree->root[2*node->position], tree);
            int right = Height(tree->root[2*node->position + 1], tree);
            if(left > right)
                return (left + 1);
            else 
                return (right + 1);
        }
}

int BTHeight(BTtree* tree)
{
    if(tree->root != NULL)
        return Height(tree->root[1], tree);
    else 
    {
        printf("cannot print height tree is empty\n");
        return 0;
    }
}

int Size(BTnode* node, BTtree* tree)
{
    if(node == NULL || 2*node->position > tree->arraySize || (2*node->position+1) > tree->arraySize)
        return 0;
    else
        return (Size(tree->root[2*node->position], tree) + Size(tree->root[2*node->position+1], tree) + 1);
}

int BTSize(BTtree* tree)
{
    if(tree->root != NULL)
        return Size(tree->root[1], tree);
    else
        return 0;
    
}

BTnode* BTGetRoot(BTtree* tree)
{
    return tree->root[1];
}

BTnode* BTGetParent(BTtree* tree, BTnode* node)
{
    if(tree->root[node->position/2] != NULL)
        return tree->root[node->position/2];
    else
    {
        printf("node has no parent\n");
        return NULL;
    }
}

BTnode* BTGetChildLeft(BTtree* tree, BTnode* node)
{
    if(tree->root[2*(node->position)] != NULL)
        return tree->root[2*(node->position)];
    else
        return NULL;
}

BTnode* BTGetChildRight(BTtree* tree, BTnode* node)
{
    if(tree->root[2*(node->position)+1] != NULL)
        return tree->root[2*(node->position)+1];
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
    if(node != NULL)
        return tree->root[node->position]->data;
    else
    {
        printf("cannot get item bcz node is empty\n");
        return 0;
    }
}

void BTInsertRoot(BTtree* tree, BTItemType item)
{
    if((tree->root[1]) == NULL)
    {
        BTnode* temp = malloc(sizeof(BTnode));
        temp->data = item;
        temp->position = 1;
        tree->root[1] = temp; 
    }
    else printf("error cannot insert root since it's already filled\n");
}

void BTInsertLeft(BTtree* tree, BTnode* node, BTItemType item)
{
    if(tree->root[2*(node->position)] == NULL)
    {
        BTnode* temp = malloc(sizeof(BTnode));
        temp->data = item;
        temp->position = 2*(node->position);
        tree->root[2*(node->position)] = temp;
    }
    else printf("error cannot insert left child since it's already fille\n");
}

void BTInsertRight(BTtree* tree, BTnode* node, BTItemType item)
{
    if(tree->root[2*(node->position)+1] == NULL)
    {
        BTnode* temp = malloc(sizeof(BTnode));
        temp->data = item;
        temp->position = 2*(node->position) + 1;
        tree->root[2*(node->position)+1] = temp;
    }
    else printf("error cannot insert right child since it's already filled\n");
}

void BTRemove(BTtree* tree, BTnode* node)
{
    if(tree->root[2*node->position] == NULL && tree->root[2*node->position+1] == NULL) //if childs are null
    {
        tree->root[node->position] = NULL;
    }
    else printf("cannot remove node bcz it has at least a child \n");
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
    preorder(tree->root[2*node->position], tree, visit);
    preorder(tree->root[2*node->position+1], tree, visit);
}

void BTPreOrder(BTtree* tree, void (*visit)(BTnode* node))
{
    if(tree->root != NULL)
    {
        printf("Preorder traversal is : ");
        preorder(tree->root[1], tree, visit);
        printf("\n");
    }
    else printf("cannot traverse preorder since tree is empty\n");
}

void inorder(BTnode* node,BTtree* tree, void (*visit)(BTnode* node))
{
    if(node == NULL)
            return;
        inorder(tree->root[2*node->position], tree, visit);
        visit(node);
        inorder(tree->root[2*node->position+1], tree, visit);
}

void BTInOrder(BTtree* tree, void (*visit)(BTnode* node))
{
    if(tree->root != NULL)
    {
        printf("Inorder traversal is : ");
        inorder(tree->root[1], tree, visit);
        printf("\n");
    }
    else printf("cannot traverse inorder since tree is empty\n");
}

void postorder(BTnode* node, BTtree* tree, void (*visit)(BTnode* node))
{
    if(node == NULL)
            return;
        preorder(tree->root[2*node->position], tree, visit);
        preorder(tree->root[2*node->position+1], tree, visit);
        visit(node);
}

void BTPostOrder(BTtree* tree, void (*visit)(BTnode* node))
{
    if(tree->root != NULL)
    {
        printf("Postorder traversal is : ");
        postorder(tree->root[1], tree, visit);
        printf("\n");
    }
    else printf("cannot traverse postorder since tree is empty\n");
}

void BTLevelOrder(BTtree* tree, void (*visit)(BTnode* node))
{
    printf("Levelorder traversal is : ");
    if(tree->root[1] == NULL)
        return;
    Queue Q;
    InitializeQueue(&Q);
    Insert(tree->root[1], &Q);
    while(!Empty(&Q))
    {
        BTnode* temp = Remove(&Q);
        visit(temp);
        if(tree->root[2*temp->position]!=NULL) 
            Insert(tree->root[2*temp->position], &Q);
        if(tree->root[2*temp->position+1]!=NULL)
            Insert(tree->root[2*temp->position+1], &Q);
    }
    printf("\n");
}


void destroy(BTnode* node, BTtree* tree)
{
    // if(node != NULL || 2*node->position > tree->arraySize || (2*node->position+1) > tree->arraySize)
    // {
    //     destroy(tree->root[2*node->position+1], tree);
    //     free(node);
    //     destroy(tree->root[2*node->position], tree);
    //     free(node);
    // }
}

void BTDestroy(BTtree* tree)
{
    // destroy(tree->root[1], tree);
    free(tree->root[0]);
    for(int i=0; i<tree->arraySize; i++)
        free(tree->root[i]);
    free(tree);
}
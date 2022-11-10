#include <stdio.h>
#include <stdlib.h>

struct Node {

    int value;
    struct Node* Left;
    struct Node* Right;
};
typedef struct Node Node;

static void Display_Inorder(Node *node);

int main(int argc, char* argv[])
{
    Node *root = (Node*)malloc(sizeof(Node));
    Node *new_node1 = (Node*)malloc(sizeof(Node));
    Node *new_node2 = (Node*)malloc(sizeof(Node));

    root->value = 50;
    root->Left  = new_node1;
    root->Right = new_node2;

    root->Left->value  = 20;
    root->Right->value = 60;

    root->Left->Left   = NULL;
    root->Left->Right  = NULL;
    root->Right->Right = NULL;
    root->Right->Left  = NULL;

    Display_Inorder(root);

    return 0;
}


static void new_node(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->value = data;
    temp->Left = NULL;
    temp->Right = NULL;
}


static void Display_Inorder(Node *node)
{   
    /*left-root-right*/

    if (node == NULL)
        return;
    
    Display_Inorder(node->Left);

    printf("%d\n", node->value);

    Display_Inorder(node->Right);
}   
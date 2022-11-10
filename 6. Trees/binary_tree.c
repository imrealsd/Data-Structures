#include <stdio.h>
#include <stdlib.h>

/*structure of single node*/
struct Node {

    int value;
    struct Node* Left;
    struct Node* Right;
};
typedef struct Node Node;


/*static function prototypes*/
static void Display_Inorder(Node *node);
static Node* new_node(int data);


/**
 * @brief program entry point
 * @retval int
 */
int main(int argc, char* argv[])
{
    Node *root = new_node(50);
    root->Left = new_node(30);
    root->Right = new_node(60);
    root->Left->Left  = new_node(40);
    root->Left->Right = new_node(45);
    root->Right->Left  = new_node(55);
    root->Right->Right = new_node(65);
    
    Display_Inorder(root);
    return 0;
}

/**
 * @brief  function that create new node
 * @retval Node* [structuture pointer]
 */
static Node* new_node(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->value = data;
    temp->Left = NULL;
    temp->Right = NULL;
    return temp;
}


/**
 * @brief  function for inorder travarsal
 * @retval node
 */
static void Display_Inorder(Node *node)
{   
    if (node == NULL)
        return;
    
    /*visit left nodes*/
    Display_Inorder(node->Left);

    /*print data of node*/
    printf("%d\n", node->value);

    /*visit right nodes*/
    Display_Inorder(node->Right);
}   
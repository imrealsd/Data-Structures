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
static Node* new_node(int data);
static void Display_Inorder(Node *node);
static void Display_Preorder(Node *node);
static void Display_Postorder(Node *node);
static void insert_node(Node* root, int data);



/**
 * @brief program entry point
 * @retval int
 */
int main(int argc, char* argv[])
{
    Node *root  = new_node(0);
    root->Left  = new_node(-5);
    root->Right = new_node(+5);
    
    root->Left->Left   = new_node(-10);
    root->Left->Right  = new_node(-2);
    root->Right->Left  = new_node(+2);
    root->Right->Right = new_node(+10);
    
    printf("\nInorder  :");
    Display_Inorder(root);

    // printf("\nPreorder :");
    // Display_Preorder(root);
    // printf("\nPostorder:");
    // Display_Postorder(root);

    insert_node(root, 12);
    insert_node(root, -1);

    printf("\nInorder  :");
    Display_Inorder(root);

    return 0;
}

/**
 *  Tree Structure used:
 * 
 *                            0
 *                            |
 *                ------------------------
 *               -5                     +5
 *                |                      |
 *      ------------------        ----------------
 *      |                |        |              |
 *     -10              -2       +2             +10
 * 
 */


/**
 * @brief  function that create new node
 * @retval Node* [structure pointer]
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
    printf("%d ", node->value);

    /*visit right nodes*/
    Display_Inorder(node->Right);
}   


/**
 * @brief  function for preorder travarsal
 * @retval node
 */
static void Display_Preorder(Node *node)
{
    if (node == NULL)
        return;

    /*print data of node*/
    printf("%d ", node->value);

    /*visit left nodes*/
    Display_Preorder(node->Left);

    /*visit right nodes*/
    Display_Preorder(node->Right);
}


/**
 * @brief  function for postorder travarsal
 * @retval node
 */
static void Display_Postorder(Node *node)
{
    if (node == NULL)
        return;

    /*visit left nodes*/
    Display_Postorder(node->Left);

    /*visit right nodes*/
    Display_Postorder(node->Right);

    /*print data of node*/
    printf("%d ", node->value);
}


/**
 * @brief  function for inserting node
 * @retval node
 */
static void insert_node(Node* root, int data)
{
    Node *ptr, *nodeptr, *parentptr;
    ptr = (Node *)malloc(sizeof(Node));

    /*if ptr is empty return [memory full]*/
    if (ptr == NULL){
        printf("Can't Insert\n");

    /*else start inserting*/
    } else {

        ptr->value = data;
        ptr->Left = NULL;
        ptr->Right = NULL;
    
        /*if inserting first node: root = first node = ptr*/
        if (root == NULL){
            root = ptr;

        /*else travarse and find the insertion position*/
        } else {
            parentptr = NULL;
            nodeptr = root;

            while (nodeptr != NULL){
                parentptr = nodeptr;

                if (data < nodeptr->value){
                    nodeptr = nodeptr->Left;
                } else {
                    nodeptr = nodeptr->Right;
                }
            }
        }

        /* if new data is less than parent_node , insert at left pos*/
        if (data < parentptr->value){
            parentptr->Left = ptr;
        /*else insert at right pos*/
        } else {
            parentptr->Right = ptr;
        }
    }
}
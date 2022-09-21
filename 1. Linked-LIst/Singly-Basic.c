/* Basic Singly linked list operations:
 * Insert @ begining
 * Insert @ end
 * Insert after a node [val]
 * Delete @ begining
 * Delete @ end
 * Delete a node with a value 
 * Printing Values
*/


#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
} *head;

void insert_at_begining (int data);
void insert_at_end (int data);
void insert_after_node_val (int prev_node_data, int data);
void delete_at_begining (void);
void delete_at_end (void);
void delete_node_of_value (int data);
void display_linked_list (void);

int main()
{
    insert_at_begining(10);
    insert_at_end(20);
    insert_after_node_val(10,34);
    display_linked_list();
    delete_at_begining();
    display_linked_list();
    delete_at_end();
    display_linked_list();
    delete_at_end();
    display_linked_list();
    insert_at_begining(0);
    display_linked_list();
    return 0;
}

void insert_at_begining (int data)
{   
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->val = data;
    temp->next = NULL;

    if (head == NULL){
        head = temp;
    } else{
        temp->next = head;
        head = temp;
    }
}

void insert_at_end (int data)
{   

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    temp->val = data;
    temp->next = NULL;

    if (head == NULL){head = temp; return;}
   
    while (ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void insert_after_node_val (int prev_node_data, int data)
{   
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *ptr  = head;
    temp->val = data;
    temp->next = NULL;

    while (ptr->val != prev_node_data){
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}

void delete_at_begining (void)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    ptr = NULL;       // not necessary
}

void delete_at_end (void)
{   
    if (head->next == NULL){
        free(head);
        head = NULL;
        return;
    }
    struct node *ptr2 = head;
    struct node *ptr1 = head->next;

    while (ptr1->next != NULL){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr2->next = NULL;
    free(ptr1);
}

void delete_node_of_value (int data)
{   
    struct node *ptr2 = head;
    struct node *ptr1 = head->next;

    if (head->val == data){head = head->next; free(ptr2);}

    while (ptr1->val != data){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr2->next = ptr1->next;
    free(ptr1);
}

void display_linked_list (void)
{
    struct node *ptr = head;

    printf("Current List: ");
    while (ptr != NULL){
        printf("%d-->", ptr->val);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
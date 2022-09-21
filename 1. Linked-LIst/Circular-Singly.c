#include <stdio.h>
#include <stdlib.h>
int node_count = 0;

struct node {
    int val;
    struct node* next;
} *head;

void insert_at_begining (int data);
void insert_after_node_of_val (int prev_node_data, int data);
void display_list (void);

int main()
{
    insert_at_begining(10);
    insert_after_node_of_val(10,34);
    insert_at_begining(21);
    insert_at_begining(44);
    display_list();
    return 0;
}

void insert_at_begining (int data)                     // begining and end is equal
{   
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *ptr = head;
    int temp_node_count = node_count-1;
    temp->val = data;
    temp->next = NULL;

    if (head == NULL){head = temp; node_count++; return;}
    temp->next = head;

    /* Reach to last node and update "next" pointer */
    while (temp_node_count--){
        ptr = ptr->next;
    }
    ptr->next = temp;
    head = temp;
    node_count++;
}

void insert_after_node_of_val (int prev_node_data, int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *ptr = head;
    temp->val = data;
    temp->next = NULL;

    while (ptr->val != prev_node_data){
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
    node_count++;
}

void display_list (void)
{
    struct node* ptr = head;
    int temp = node_count;
    printf("Current List: ");
    while (temp--){
        printf("%d --> ", ptr->val);
        ptr = ptr->next;
    }
    printf("begining\n");
}

void delete_at_begining (void)
{
    
}
void delete_node_of_val (int data)
{}
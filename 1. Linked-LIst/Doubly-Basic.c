#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int value;
    struct node* prev;
    struct node* next;
} *head;

void insert_at_begining (int val);
void insert_at_end (int val);
void insert_after_node_val (int prev_node_val, int val);
void delete_at_begining (void);
void delete_at_end (void);
void delete_node_of_val (int val);
void display_list (char* direction);


int main(int argc, int* argv[])
{   
    insert_at_begining(24);
    insert_at_end(90);
    insert_after_node_val(24,30);
    insert_at_begining(10);
    display_list("FORWORD");
    //display_list("BACKWORD");
    //delete_at_begining();
    //delete_at_end();
    delete_node_of_val(90);
    display_list("FORWORD");
    return 0;
}

void insert_at_begining (int val)
{   
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->value = val;
    temp->prev = NULL;
    temp->next = NULL;

    if (head == NULL){
        head = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insert_at_end (int val)
{   
    if (head == NULL){insert_at_begining(val);};
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    temp->value = val;
    temp->next = NULL;
    temp->prev = NULL;

    while (ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
}

void insert_after_node_val (int prev_node_val, int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    temp->value = val;
    temp->next = NULL;
    temp->prev = NULL;

    while (ptr->value != prev_node_val){
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    temp->prev = ptr;
    ptr->next = temp;

    ptr = ptr->next->next;
    ptr->prev = temp;
}

void delete_at_begining (void)
{   
    if (head == NULL){return;}
    struct node *ptr = head;
    head = head->next;
    head->prev = NULL;
    free(ptr);
    ptr = NULL;
}

void delete_at_end (void)
{   
    if (head == NULL){return;}
    if (head->next == NULL){free(head); head == NULL; return;}

    struct node *ptr1 = head;
    struct node *ptr2 = head->next;

    while (ptr2->next != NULL){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr1->next = NULL;
    free(ptr2);
    ptr2 = NULL;
}

void delete_node_of_val (int val)
{   
    if (head == NULL){return;}

    if (head->value == val){      // if first node
        delete_at_begining();
    }
    struct node* ptr1 = head;
    struct node* ptr2 = head->next;

    while (ptr2->value != val){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    if (!(ptr2->next == NULL)){   // if not the last node
        ptr1->next = ptr2->next;
        ptr1 = ptr1->next;
        ptr1->prev = ptr2->prev;
        free(ptr2);
        ptr2 = NULL;
    } else{                        // if last node
        delete_at_end();
    }
}

void display_list (char* direction) 
{  
    struct node* ptr = head;

    if (!strcmp(direction,"FORWORD")){
        while (ptr != NULL){
            printf("%d --> ", ptr->value);
            ptr = ptr->next;
        }
        printf("NULL\n");

    } else if (!strcmp(direction,"BACKWORD")){
        while (ptr->next != NULL){
            ptr = ptr->next;
        }
        while (ptr != NULL){
            printf("%d --> ", ptr->value);
            ptr = ptr->prev;
        }
        printf("NULL\n");
    }
}
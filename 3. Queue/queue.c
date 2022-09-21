#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node* next;
} *head;

void enqueue (int);
void dequeue (void);
void display (void);

int main (int argc, char* argv[])
{
	enqueue(10);
	enqueue(17);
	enqueue(45);
	display();
	dequeue();
	display();
	dequeue();
	display();
	return 0;
}

void enqueue (int data)
{	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	struct node* ptr = head;
	temp->val = data;
	temp->next = NULL;

	if (head == NULL){
		head = temp;
		printf("Enqueued: %d\n", data);
		return;
	}
	while (ptr->next != NULL){
		ptr = ptr->next;
	}
	ptr->next = temp;
	printf("Enqueued: %d\n", data);
}

void dequeue (void)
{	
	if (head == NULL){return;}
	struct node* ptr = head;
	head = head->next;
	printf("Dequeued: %d\n",ptr->val);
	free(ptr);
	ptr = NULL;
}

void display (void)
{	
	if (head == NULL){printf("Empty\n");return;}
	struct node* ptr = head;
	while (ptr != NULL){
		printf("%d->", ptr->val);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

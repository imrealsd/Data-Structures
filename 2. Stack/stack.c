#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
} *head;

void push (int);
void pop (void);
void display (void);

int main(int argc, char* arvg[])
{
	push(3);
	push(4);
	push(45);
	display();
	pop();
	display();
	pop();
	display();
	return 0;
}

void push (int val)
{	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	struct node* ptr = head;
	temp->data = val;
	temp->next = NULL;

	if (head == NULL){
		head = temp;
		printf("pushed:%d\n",val);
		return;
	}
	temp->next = head;
	head = temp;
	printf("Pushed:%d\n",val);
}

void pop (void)
{
	if (head == NULL){return;}
	struct node* ptr = head;
	head = head->next;
	int temp = ptr->data;
	free(ptr);
	ptr = NULL;
	printf("poped:%d\n",temp);
}

void display (void)
{
	struct node* ptr = head;
	printf("Current Stack:\n");
	while (ptr != NULL){
		printf("%d\n",ptr->data);
		ptr = ptr->next;
	}
}




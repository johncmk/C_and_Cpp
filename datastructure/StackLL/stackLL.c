#include<stdio.h>
#include<stdlib.h>

/**
 * stack node
 */
typedef struct _node{
	int data;
	struct _node *next;
}node;

/**
 * stack implemented by L.L.
 */
typedef struct _stack{
	int size;
	node* top;
}stack;

/**
 * return true if stack is empty
 */
int isEmpty(stack* li){
	return (li->top == NULL);
}

/**
 * return size of stack
 */
int getInputSize(stack* li){
	return li->size;
}

/**
 * initialize stack; This must be called before
 * proceeding any stack operations
 */
void init(stack *li){
	li->size = 0;
	li->top = NULL;
}

/**
 * push data into stack; Append
 */
void push(stack *li, int num){
	node *temp = (node*)malloc(sizeof(node));
	temp->data = num;
	temp->next = li->top;
	li->top = temp;
	li->size++;
}

/**
 * pop the data from stack; then remove the top
 */
int pop(stack* li){
	if(isEmpty(li))
		return 0;
	node *temp = li->top;
	int data = temp->data;
	li->top = temp->next;
	free(temp);
	li->size--;
	return data;
}

/**
 * display top element of stack
 */
int top(stack *li){
	if(isEmpty(li))
		return 0;
	return li->top->data;
}

/**
 * main function
 */
int main(){

	srand(time(NULL));

	stack *li = (stack*)malloc(sizeof(stack));
	init(li);

	int i;
	for(i = 0;i < 10;++i)
		push(li,i+1);

	while(!isEmpty(li))
		printf("%d \n",pop(li));

	return 0;
}

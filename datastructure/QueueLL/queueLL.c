/**
 * Queue implemented Linked List
 */
#include<stdio.h>
#include<stdlib.h>

/**
 * node data structure
 */
typedef struct _node{
	int data;
	struct _node *next;
}node;

/**
 * Queue implemented by linked list data structure
 */
typedef struct _queueLL{
	int size;
	node *front;
	node *rear;
}queueLL;

/**
 * Initialize list; this must be executed before
 * processing any DLL operations
 */
void init(queueLL *li){
	li->size = 0;
	li->front = NULL;
	li->rear = NULL;
}

/**
 * declare node in heap
 */
node* declareNode(node* el, int num){
	el = (node*)malloc(sizeof(node));
	el->data = num;
	el->next = NULL;
	return el;
}

/**
 * completely remove node from heap
 */
void freeNode(node *el){
	free(el);
	el = NULL;
}

/**
 * return true if queue is empty
 */
int isEmpty(queueLL *li){
	return (li->size == 0);
}

/**
 * return total number of element in queue
 */
int getSize(queueLL *li){
	return li->size;
}

/**
 * add node to queue LL
 */
void enqueue(queueLL *li, int num){
	node *newNode = declareNode(newNode,num);
	if(isEmpty(li)){
		li->front = newNode;
		li->rear = newNode;
	}else{
		li->rear->next = newNode;
		li->rear = newNode;
	}
	li->size++;
}

/**
 * pop the first element from queue LL
 */
int dequeue(queueLL *li){
	if(isEmpty(li))
		return 0;
	int data = li->front->data;
	node* pop = li->front;
	li->front = li->front->next;
	freeNode(pop);
	li->size--;
	return data;
}

/**
 * main function
 */
int main(){

	queueLL *li = (queueLL*)malloc(sizeof(queueLL));
	init(li);

	int i;
	for(i = 0; i < 10; i++)
		enqueue(li,i+1);

	printf("getSize %d \n",getSize(li));

	while(!isEmpty(li))
		printf("%d \n",dequeue(li));

	printf("getSize %d \n",getSize(li));

	return 0;
}

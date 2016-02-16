/**
 * circular queue
 */
#include<stdio.h>
#include<stdlib.h>

/**
 * queue data structure
 */
typedef struct _queue{
	int *arr;
	int front;
	int rear;
	int size;
}queue;

/**
 * initialize queue; This must be executed before
 * processing any queue operations
 */
void init(queue *li, int size){
	li->arr = (int*)malloc(size*sizeof(int));
	li->front = -1;
	li->rear = -1;
	li->size = size;
}

/**
 * return true if queue is empty
 */
int isEmpty(queue *li){
	return (li->front == -1 && li->rear == -1);
}

/**
 * return fixed size of queue
 */
int getSize(queue *li){
	return li->size;
}

/**
 * return inputed elements size of queue
 */
int getInputSize(queue *li){
	return (isEmpty(li))? 0: (li->rear+1) - li->front;
}

/**
 * return true if queue is full;
 * if rear index and front index are equal it's full
 */
int isFull(queue *li){
	return (((li->rear+1) % li->size) == li->front);
}

/**
 * insert the data in front of the queue FIFO
 */
void enqueue(queue *li, int num){
	if(isFull(li))
		return;
	else if(isEmpty(li)){
		li->front = 0;
		li->rear = 0;
	}else
		li->rear = (li->rear+1) % li->size;
	li->arr[li->rear] = num;
}

/**
 * if queue contains only one element
 */
int hasOnlyOneElement(queue *li){
	return (!isEmpty(li) &&( li->front == li->rear));
}

/**
 * output the front data of queue list
 */
int dequeue(queue* li){
	int pos = li->front;
	if(isEmpty(li))
		return 0;
	else if(hasOnlyOneElement(li)){
		li->front = -1;
		li->rear = -1;
	}else
		li->front = (li->front+1) % li->size;
	return li->arr[pos];
}

/**
 * display the top element of queue
 */
int top(queue *li){
	if(isEmpty(li))
		return 0;
	return li->arr[li->front];
}

/**
 * main function
 */
int main(){

	srand(time(NULL));
	int size = 10;

	queue *li = (queue*)malloc(sizeof(queue));
	init(li,size);

	int i;
	for(i = 0; i < size;++i){
		enqueue(li,i+1);
	}

	printf("B/F size: %d \n",getInputSize(li));
	while(!isEmpty(li)){
			printf("dequeue: %d \n",dequeue(li));
		}
	if(isEmpty(li))
		printf("empty \n");
	else
		printf("not empty \n");


	printf("A/F size: %d \n",getInputSize(li));

	return 0;
}

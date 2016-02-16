#include<stdio.h>
#include<stdlib.h>

/**
 * stack array implement structure
 */
typedef struct _stack{
	int size;
	int ptr;
	int *arr;
}stack;

/**
 * initialize stack values; this must be
 * execute first before proceed any stack operations
 */
void init(stack *obj, int size){
	obj->size = size;
	obj->ptr = -1;
	obj->arr = (int*)malloc(size*sizeof(int));
}

/**
 * return true if stack is empty
 */
int isEmpty(stack *obj){
	return (obj->ptr == -1);
}

/**
 * return true if stack is full
 */
int isFull(stack* obj){
	return (obj->size == obj->ptr+1);
}

/**
 * push value to stack;
 */
void push(stack *obj, int num){
	obj->arr[++obj->ptr] = num;
}

/**
 * pop the last element of stack
 */
int pop(stack *obj){
	return obj->arr[obj->ptr--];
}

/**
 * return size of stack
 */
int getInputSize(stack *obj){
	return obj->ptr+1;
}

/**
 * display top item
 */
int top(stack* obj){
	return obj->arr[obj->ptr];
}

/**
 * main function
 */
int main(){
	srand(time(NULL));

	stack *li = (stack*)malloc(sizeof(stack));
	init(li,10);


	int i;
	for(i = 0; i < 10;i++)
		push(li,i+1);

//	while(!isFull(li)){
//		push(li,rand());
//	}

	printf("getSize = %d \n",getInputSize(li));

	printf("top item is %d \n", top(li));

	while(!isEmpty(li)){
		printf("%d \n",pop(li));
	}

	printf("getSize = %d \n",getInputSize(li));

	return 0;
}

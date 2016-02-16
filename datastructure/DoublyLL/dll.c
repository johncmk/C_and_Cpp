/**
 * doubly linked list
 */
#include<stdio.h>
#include<stdlib.h>

/**
 * doubly LL node
 */
typedef struct _node{
	int data;
	struct _node *prev;
	struct _node *next;
}node;

/**
 * doubly linked list; contains head and tail
 */
typedef struct _dlist{
	int size;
	node *head;
	node *tail;
}dlist;

/**
 * Initialize list; this must be executed before
 * processing any DLL operations
 */
void init(dlist *li){
	li->head = NULL;
	li->size = 0;
}

/**
 * return total number of elements in DLL.
 */
int getSize(dlist *li){
	return li->size;
}

/**
 * return true if DLL is empty
 */
int isEmpty(dlist *li){
	return (li->size == 0);
}

/**
 * create node object in heap with default values
 */
node* declareNode(node *el, int num){
	el = (node*)malloc(sizeof(node));
	el->prev = NULL;
	el->next = NULL;
	el->data = num;
	return el;
}

/**
 * insert node at the head of the list
 */
void insert(dlist* li, int num){
	node *newNode = declareNode(newNode,num);
	if(isEmpty(li)){
		li->head = newNode;
		li->tail = newNode;
	}else{
		li->head->prev = newNode;
		newNode->next = li->head;
		li->head = newNode;
	}
	li->size++;
	return;
}

/**
 * insert node at the tail of the list
 */
void insertAtTail(dlist* li, int num){
	node *newNode = declareNode(newNode,num);
	if(isEmpty(li)){
		li->head = newNode;
		li->tail = newNode;
	}else{
		li->tail->next = newNode;
		newNode->prev = li->tail;
		li->tail = newNode;
	}
	li->size++;
	return;
}

/**
 * print orderly
 */
void printList(dlist *li){
	node *current = li->head;
	while(current != NULL){
		printf("%d \n",current->data);
		current = current->next;
	}
}

/**
 * print reversely
 */
void printReverse(dlist *li){
	node *current = li->tail;
	while(current != NULL){
		printf("%d \n",current->data);
		current = current->prev;
	}
}

/**
 * search the data in the DLL and return the node if the
 * data exists in DLL else return NULL
 */
node* search(dlist* li, int num){
	if(isEmpty(li))
		return NULL;
	node *current = li->head;
	while(current != NULL){
		if(current->data == num)
			return current;
		current = current->next;
	}
	return NULL;
}

/**
 * free node from heap
 */
void freeNode(node* el){
	free(el);
	el = NULL;
}

/**
 * if selected node is in the head of the list
 */
void deleteCase1(dlist *li, node *ptr){
	li->head = li->head->next;
	li->head->prev = NULL;
	freeNode(ptr);
}

/**
 * if selected node is in the tail of the list
 */
void deleteCase2(dlist *li, node *ptr){
	li->tail = li->tail->prev;
	li->tail->next = NULL;
	freeNode(ptr);
}

/**
 * if selected node is in the middle of the list
 */
void deleteCase3(dlist *li, node *ptr){
	node *prev = ptr->prev;
	node *next = ptr->next;
	prev->next = next;
	next->prev = prev;
	freeNode(ptr);
}

/**
 * delete selected number in the list
 */
void delete(dlist *li, int num){
	node *found = search(li,num);
	if(found == NULL)
		return;
	else if(found == li->head)
		deleteCase1(li,found);
	else if(found == li->tail)
		deleteCase2(li,found);
	else
		deleteCase3(li,found);
	li->size--;
}

/**
 * main function
 */
int main(){

	dlist *li = (dlist*)malloc(sizeof(dlist));
	init(li);

	int i;
	for(i = 0; i < 10; i++)
		insertAtTail(li,i+1);

	printList(li);
	printf("size: %d \n",getSize(li));

	printReverse(li);

	if(search(li,1) == NULL)
		printf("number is not in list \n");
	else
		printf("number is in list \n");

	delete(li,10);
	delete(li,1);
	delete(li,5);

	printList(li);
	printf("reverse print \n");
	printReverse(li);

	printf("size: %d \n",getSize(li));

	insertAtTail(li,100);
	printList(li);

	insert(li,-1);
	printList(li);
	return 0;
}

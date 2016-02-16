/**
 * circular linked list
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
 * circular linked list data structure
 */
typedef struct _clist{
	int size;
	node *tail;
}clist;

/**
 * Initialize list; this must be executed before
 * processing any DLL operations
 */
void init(clist *li){
	li->size = 0;
	li->tail = NULL;
}

/**
 * return True if list size is 0
 */
int isEmpty(clist *li){
	return (li->size == 0);
}

/*
 * return total number of element in the CLL
 */
int getSize(clist *li){
	return li->size;
}

/**
 * print elements in CLL; runs 1 cycle from head to tail
 * where head is tail->next
 */
void printList(clist *li){
	node* current = li->tail->next;
	do{
		printf("%d \n",current->data);
		current = current->next;
	}while(current != li->tail->next);
}

/**
 * declare node in heap
 */
node* declareNode(node *el, int num){
	el = (node*)malloc(sizeof(node));
	el->data = num;
	el->next = NULL;
	return el;
}

/**
 * Add first node into CLL
 */
void insertCase1(clist* li, node *newNode){
	li->tail = newNode;
	li->tail->next = li->tail;
}

/**
 * Add node to tail of the CLL
 */
void insertCase2(clist* li, node *newNode){
	node *head = li->tail->next;
	li->tail->next = newNode;
	li->tail = newNode;
	li->tail->next = head;
}

/**
 * add node to CLL
 */
void insert(clist *li, int num){
	node* newNode = declareNode(newNode,num);
	if(isEmpty(li))
		insertCase1(li,newNode);
	insertCase2(li,newNode);
	li->size++;
}

/**
 * Search helpful function; iterates O(n)
 */
node* _search(int data, node* previous){
	node* current = previous->next;
	return (current->data == data)? previous: (current == NULL)? NULL: _search(data,current);
}

/**
 * Search the data from CLL and return it
 */
node* search(clist* li, int data){
	if(isEmpty(li))
		return NULL;
	node *previous = li->tail->next; //head of the list
	node *current = previous->next;
	if(previous->data == data || current->data == data)
		return previous;
	return _search(data,current);
}

/**
 * Completely delete the node from heap
 */
void freeNode(node* el){
	free(el);
	el = NULL;
}

/**
 * return true if data is not found in CLL or
 * CLL is empty
 */
int deleteCase1(clist* li, node * found){
	return (found == NULL || isEmpty(li));
}

/**
 * case where found node is in the head
 */
int deleteCase2(clist *li, node *found){
	return (li->tail->next == found);
}

/**
 * case where found node is in the tail of the list
 * or found node is in middle of the list
 */

void deleteCase3(clist *li, node *previous, node *current){
	previous->next = current->next;
	if(current == li->tail)
		li->tail = previous;
	freeNode(current);
}

/**
 * delete node from L.L O(n + 1) = o(n)
 * found->next is found current node
 * found is previous of found->next node
 */
void delete(clist *li, int data){
	node *found = search(li,data);
	if(deleteCase1(li,found->next))
		return;
	else if(deleteCase2(li,found)){
		li->tail->next = found->next;
		freeNode(found);
	}else
		deleteCase3(li, found, found->next);
	li->size--;
}

/**
 * main function
 */
int main(){

	clist *li = (clist*)malloc(sizeof(clist));
	init(li);

	int i;
	for(i = 0; i < 10;i++)
		insert(li,i+1);

	printList(li);

	delete(li,1);
	delete(li,5);
	delete(li,10);
	printList(li);


	return 0;
}

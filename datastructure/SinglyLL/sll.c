/**
 * Singly linked list
 */
#include<stdio.h>
#include<stdlib.h> //random

/**
 * node structure
 */
typedef struct _Node{
	int data;
	struct _Node *next;
}node;

/**
 * list structure
 */
typedef struct _list{
	int count;
	node* head;
}list;

/**
 * initialize head node in list
 */
void init(list* li){
	li->count = 0;
	li->head = NULL;
}

/**
 * Check, if list is empty; 1 is true, 0 is false
 */
int empty(list* li){return (li->head == NULL);}

/**
 * return size of L.L.
 */
int getInputSize(list* li){return li->count;}

/**
 * return data from node
 */
int getData(node* node){return node->data;}

/**
 * print nodes in linked list
 */
void printList(list *li){
	int count = 0;
	node* current = li->head;
	while(current != NULL){
		printf("%d. %d \n",++count,current->data);
		current = current->next;}
}

/**
 * Search helpful function; iterates O(n)
 */
node* _search(int data, node* previous){
	node* current = previous->next;
	return (current->data == data)? previous: (current == NULL)? NULL: _search(data,current);
}

/**
 * Search the data from L.L and return the previous node
 */
node* search(list *li, int data){
	if(empty(li))
		return NULL;
	node* previous = li->head;
	node* current = previous->next;
	if(previous->data == data || current->data == data)
		return previous;
	return _search(data,current);
}

/**
 * compare the newNode data return true if
 * pre->data <= new->data <= cur->data
 */
int lessThanEqualTo(node*pre, node*cur, node*newNode){
	return (pre->data <= newNode->data && newNode->data <= cur->data);
}

/**
 * LinkedList insert case1; add first node to head of the list
 */
void insertCase1(list* li, node* newNode){li->head = newNode;}

/**
 * LinkedList insert case2; prepend node to head
 */
void insertCase2(list* li, node* newNode){
	newNode->next = li->head;
	li->head = newNode;
}

/**
 * LinkedList insert case3; append node in middle/end O(n)
 */
void insertCase3(node* newNode, node* previous, node* current){
	if(current == NULL || lessThanEqualTo(previous,current,newNode)){
		previous->next = newNode;
		if(current != NULL)
			newNode->next = current;
		return;
	}
	insertCase3(newNode,previous->next,current->next);
}

/**
 * insert node to LinkedList by sorted
 */
void insert(list* li, int data){
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;
	if(empty(li))
		insertCase1(li,newNode);
	else if(li->head->data > newNode->data)
		insertCase2(li,newNode);
	else
		insertCase3(newNode,li->head,li->head->next);
	li->count++;
}

/**
 * free memory from heap;set selected node points to NULL
 */
void freeNode(node* deleteNode){
	free(deleteNode);
	deleteNode = NULL;
}

/**
 * delete case1; if list is empty/data not found
 */
int deleteCase1(list *li, node *found){
	return (found == NULL || empty(li));
}

/**
 * delete case2; if node is in head of the list
 */
int deleteCase2(list *li, node *found{
	return (li->head == found);
}

/**
 * delete case3; if node is in the middle/end of the list
 */
void deleteCase3(node *previous, node *current){
	previous->next = (current->next != NULL)? current->next : NULL;
	freeNode(current);
}

/**
 * delete node from L.L O(n + 1) = o(n)
 * found->next is found current node
 * found is previous of found->next node
 */
void delete(list*li, int data){
	node* found = search(li,data);
	if(deleteCase1(li,found->next))
		return;
	else if(deleteCase2(li,found)){
		li->head = found->next;
		freeNode(found);
	}else
		deleteCase3(found, found->next);
	li->count--;
}

/**
 * free memory from heap;
 * set selected node points to NULL
 */
void freeList(list* li){
	free(li);
	li = NULL;
}

/**
 * emptyList helper function; iterates
 */
void _emptyList(list*li , node* ptr, int listSize){
	if(listSize == 0)
		return;
	node* temp = ptr;
	li->head = temp->next;
	freeNode(temp);
	_emptyList(li,li->head,--li->count);
}

/**
 * delete all node from list
 */
void emptyList(list *li){
	_emptyList(li,li->head,getInputSize(li));
}

/**
 * reverse the L.L.; iterative method
 */
void reverse(list **li){
	if(getInputSize(*li) <= 1)
		return;
	node *previous = NULL;
	node *next = NULL;
	node* current = ((*li)->head);
	while(current != NULL){
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
		}
		(*li)->head = previous;
}

/**
 * reverse the L.L help function;
 * points to the *node and reallocate head of L.L.
 */
void _reverseRecursive(node **hRef){
	node *first, *rest;
	first = *hRef;
	rest = first->next;
	if (rest == NULL)
		return;
	_reverseRecursive(&rest);
	first->next->next = first;
	first->next = NULL;
	*hRef = rest;
}

/**
 * reverse the L.L.; recursion method
 */
void reverseRecursive(list **li){
	if(getInputSize((*li)) <= 1)
		return;
	_reverseRecursive(&(*li)->head);
}

/**
 * main function
 */
int main(int argc, char **argv){


	list *li = (list*)malloc(sizeof(list));
	init(li);
	int i;
	for(i = 0; i < 10; ++i){
		insert(li,i+1);
	}

	printList(li);
	printf("before %d \n",getInputSize(li));
	delete(li,1);
	delete(li,10);
	delete(li,5);
	printf("after delete data the size is %d \n",getInputSize(li));
	printList(li);

	printf("\n After reverse list \n");
	reverse(&li);
	printList(li);
	printf("\n After reverse back the list recursively\n");
	reverseRecursive(&li);
	printList(li);

	printf("\n Delete all elements in the list\n");
	emptyList(li);

	printf("listSize %d \n",getInputSize(li));
	printList(li);

	if(empty(li))
		printf("empty \n");
	else
		printf("not empty \n");

	printf("listSize %d \n",getInputSize(li));

	return 0;
}

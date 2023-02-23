
#ifndef stack_h
#define stack_h
#include "node.h"
typedef struct {
	NodePtr top;
	int size;
}Stack;

typedef Stack * StackPtr;
void push(StackPtr s, char value);
char pop(StackPtr s);
void pop_all(StackPtr s);

void push(StackPtr s, char value){
	//create new node
	NodePtr new_node = (NodePtr)malloc(sizeof(Node));
	//if new node completely create 
	if(new_node){
		//assign new node value and pointer
		new_node->data = value;
		new_node->nextPtr = s->top;
		//update stack top ptr and value
		s->top = new_node;
		s->size++;
	}
}

char pop(StackPtr s){
	//temp point to top
	NodePtr temp = s->top;
	char value = temp->data;
	//top change to next node and decreasing size
	s->top = s->top->nextPtr;
	s->size--;
	//free temp
	free(temp);
	return value;
}

void pop_all(StackPtr s){
	NodePtr temp;
	while(s->top!=NULL){
		temp = s->top;
		s->top = s->top->nextPtr;
		s->size--;
		free(temp);
	}
}
#endif



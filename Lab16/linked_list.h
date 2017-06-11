#pragma once
// linked_list.h
#include <stddef.h>
#include <stdio.h>
#include "iterator.h"
typedef struct _linked_list LinkedList;
typedef struct _list_node ListNode;

LinkedList *newLinkedList(size_t);
void deleteLinkedList(LinkedList*);
void deleteIterator(Iterator*);


typedef struct _list_node{
	void *data;
	ListNode* next;
};

struct _linked_list {
	size_t sizeOfElement;
	size_t numOfElements;
	ListNode *head;

	void(*add)(LinkedList*, void*);
	void(*insert)(LinkedList*, int, void*);
	void *(*remove)(LinkedList*, int);
	void(*delete)(LinkedList *);
	size_t(*size)(LinkedList*);
	void *(*get)(LinkedList*, int);

	void(*writeObject)(LinkedList*, FILE *);
	void(*readObject)(LinkedList*, FILE *);
	
	Iterator* (*iterator)(LinkedList*);
};

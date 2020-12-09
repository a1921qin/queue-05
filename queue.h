#ifndef queue_h
#define queue_h
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int dataType;
typedef struct node{
	                dataType data;
			 struct node *left, *right;
}Deque,node;
typedef struct{
	struct node *front, *rear;
} queue;
void initqueue(queue *q);
Deque* createDeque();
int size(Deque *dq);
int emrty(Deque *dq);
dataType front(Deque *dq);
dataType back(Deque *dq);
void push_front(Deque *dq,dataType x);
void push_back(Deque *dq,dataType x);
void pop_front(Deque *dq);
void pop_back(Deque *dq);
void clear(Deque *dq);
void print(Deque *dq);
#endif

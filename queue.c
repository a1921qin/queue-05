#include"queue.h"

//创建双端队列
Deque* createDeque(){
	Deque *head;
	head =(Deque*)malloc(sizeof(Deque));
	head->left=head->right=head;
	return head;
}
//初始化
void initqueue(queue *q){
	q->front = (node*)malloc(sizeof(node));
	q->rear =q->front;
}
//求双端队列的元素个数
int size(Deque *dq){
	node *p = dq->right;
	int k=0;
	while (p!=dq){
		k++;
		p=p->right;
	}
	return k;
}
//判断双端队列是否为空
int empty(Deque *dq){
	return dq->right==dq;
}
//取队头元素
dataType front(Deque *dq){
	if (empty(dq)) exit(1);
	 return dq->right->data;
	 }
//取队尾元素
dataType back(Deque *dq){
	if (empty(dq)) exit (1);
	return dq->left->data;
}
//在队头插入元素x
void push_front(Deque *dq,dataType x){
	Deque *s=(node*)malloc(sizeof(node));
	s->data=x;
	s->left=dq;
	s->right=dq->right;
	dq->right->left=s;
	dq->right =s;
}
//在队尾插入元素x
void push_back(Deque *dq,dataType x){
	Deque *s =(node*)malloc(sizeof(node));
	s->data=x;
	s->left=dq->left;
	s->right=dq;
	dq->left->right=s;
	dq->left=s;
}
//删除队头元素
void pop_front(Deque *dq){
    if(empty(dq))exit(1);
    Deque *p=dq->right;
    p->right->left=dq;
    dq->right=p->right;
    free(p);
}
//删除队尾元素
void pop_back(Deque *dq){
	if (empty(dq)) exit(1);
	Deque *p=dq->left;
	p->left->right=dq;
	dq->left=p->left;
	free(p);
}
//清除双端队列的所有元素
void clear(Deque *dq){
	Deque *p,*q;
	p=dq->right;
	while(p!=dq){
		q=p;
		p=p->right;
		free(q);
	}
	dq->left=dq->right=dq;
}
//输出双端队列的所有元素
void print(Deque *dq){
   Deque *p=dq->right;
   while(p!=dq){
   printf("%d",p->data);
   p=p->right;
}
printf("\n");
}




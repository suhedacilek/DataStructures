#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 40
#define QUEUE_SIZE 40


typedef struct{
	int data[STACK_SIZE];
	int top;
}stack;

typedef struct{
	int cnt;
	int front,rear;
	int data[QUEUE_SIZE];
}queue;

void initialize_s(stack *stk){
	stk->top = -1;
}

void push(stack *stk, int x){
	stk->data[++stk->top] = x;
}

int pop(stack *stk){
	return stk->data[stk->top--];
}


void initialize_q(queue *q){
	q->cnt =0;
	q->front=0;
	q->rear = -1;
	
}
int isfull_q(queue *q){
	if(q->cnt == QUEUE_SIZE)
		return 1;
	else
		return 0;
}

int isempty_q(queue *q){
	if(q->cnt==0)
		return 1;
	else
		return 0;
}
void enqueue(queue *q,int x){
	if(isfull_q(q) == 1)
		printf("Full \n");
	else{
		q->rear++;
		q->cnt++;
		if(q->rear==QUEUE_SIZE)
			q->rear=0;
		q->data[q->rear] =x;
	}
}
int dequeue(queue *q){
	if(isempty_q(q) == 1)
		printf("Empty \n");
	else{
		int x = q->data[q->front];
		q->cnt--;
		q->front++;
		if(q->front==QUEUE_SIZE)
			q->front=0;
		return x;
	}
}

int main(){
	char str[40];
	queue q;
	stack s;
	initialize_s(&s);
	initialize_q(&q);
	int i=0, mismatch=0;
	printf("Enter a string:");
	scanf("%s",str);
	while(i < strlen(str)){
		if(isalnum(str[i])){
			push(&s, tolower(str[i]));
			enqueue(&q,tolower(str[i]));
		}
	i++;
	}
	while(!isempty_q(&q)){
		if(pop(&s)!=dequeue(&q)){
			mismatch =1;
			break;
		}
	}
	
	if(mismatch == 0)
		printf("Polindrome");
	else{
		printf("Not polindrome\n");
	}
	
}





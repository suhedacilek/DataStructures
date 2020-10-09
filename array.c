#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 4

typedef struct{
	int data[STACK_SIZE];
	int top;
}stack;

void initialize(stack *stk){
	stk -> top = -1;
}

void push(stack *stk, int c){
	if(stk -> top == STACK_SIZE -1)
		printf("Stack is full..\n");
	else{
		stk->data[++stk->top] = c;
	}
}

int pop(stack *stk){
	if(stk->top == -1){
		printf("\nStack is empty..\n");
		return -1;
	}
	else{
		return stk->data[stk->top--];
	}
}

main(){
	stack s;
	initialize(&s);
	push(&s,3);
	push(&s,2);
	push(&s,17);
	push(&s,21);
	push(&s,5);
	printf("%d \t", pop(&s));
	printf("%d \t", pop(&s));
	printf("%d \t", pop(&s));
	printf("%d \t", pop(&s));
	printf("%d \t", pop(&s));

}

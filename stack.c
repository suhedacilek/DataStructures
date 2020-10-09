#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 4

struct node{
	int data;
	struct node *next;
};

typedef struct{
	int cnt;
	struct node *top;
}stack;

void initialize(stack *stk){
	stk -> cnt = 0;
	stk -> top = NULL;
}

void push(stack *stk, int c){
	if(stk -> cnt == STACK_SIZE)
		printf("Stack is full... \n\n");
	else{
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp -> data = c;
		temp -> next = stk -> top;
		stk -> top = temp;
		stk -> cnt++;
	}
}

int pop(stack *stk){
	if(stk -> cnt == 0){
		printf("\n\n\nStack is empty..\n\n");
		return -1;
	}
	else{
		struct node *temp = stk -> top;
		stk -> top = stk -> top -> next;
		int x = temp -> data;
		free(temp);
		stk -> cnt--;
		return x;
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











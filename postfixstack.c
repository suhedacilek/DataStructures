#include <stdio.h>
#define STACK_SIZE 20

typedef struct{
	int data[STACK_SIZE];
	int top;
}stack;

void initialize(stack *stk){
	stk->top = -1;
}

void push(stack *stk, int x){
	stk->data[++stk->top] = x;
}

int pop(stack *stk){
	return stk->data[stk->top--];
}

int main(){
	stack s;
	initialize(&s);
	char exp[20], *e;
	int n1,n2,num;
	
	printf("Enter the expression: ");
	scanf("%s", exp);
	e = exp;
	
	while(*e != '\0'){
		if(isdigit(*e)){
			num = *e -48;
			push(&s,num);
		}
		else{
			n1 = pop(&s);
			n2 = pop(&s);
			
			switch(*e){
				case '+':{
					push(&s,n1+n2);
					break;
				}
				case '-':{
					push(&s,n1-n2);
					break;
				}
				case '*':{
					push(&s,n1*n2);
					break;
				}
				case '/':{
					push(&s,n1/n2);
					break;
				}
			}
		}
		e++;
	}
	printf("\nThe result of expression %s  =  %d\n\n",exp,pop(&s));
    return 0;
}


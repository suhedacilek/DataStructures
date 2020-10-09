#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

struct minheap{
	int cnt;
	int data[SIZE];
};

void init(struct minheap *q){
	q->cnt=0;
}
void swap(int *q, int *p){
	int temp;
	temp = *q;
	*q = *p;
	*p = temp;
}


void insert(struct minheap *q,int key){
	if(q->cnt != SIZE){
		int  index = ++q->cnt;
		q->data[index]=key;
		
		while(index!=1 && q->data[index]<q->data[index/2]){
			swap(&q->data[index],&q->data[index/2]);
			index/=2;
		}
	}
}

int dequeue(struct minheap *q){
	if(q->cnt!=0){
		int key = q->data[1];
		int index = 1;
		q->data[1] = q->data[q->cnt--];
		
		while(2*index > q->cnt && q->data[index]>q->data[2*index] || q->data[index]>q->data[2*index+1]){
			if(q->data[2*index]<q->data[2*index+1]){
				swap(&q->data[index],&q->data[2*index]);
				index = 2*index;
			}
			else{
				swap(&q->data[index],&q->data[2*index+1]);
				index = 2*index+1;
			}
		}
		return key;
	}
}


void print(struct minheap *p){
	int i;
	if(p->cnt==0)
		printf("Empty \n");
	else{
		for(i=1; i<=p->cnt; i++)
			printf("%d\t", p->data[i]);
	}
		
}

int main(){
	struct minheap q;
	int key;
	init(&q);
	insert(&q,10);
	insert(&q,20);
	insert(&q,15);
	insert(&q,22);
	insert(&q,40);
	insert(&q,19);
	insert(&q,16);
	insert(&q,60);
	insert(&q,100);	
	insert(&q,44);
	print(&q);

}

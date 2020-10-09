#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *right;
	struct node *left;	
};
 
typedef struct node *BTREE;
 
BTREE new_node (int data){
	BTREE p;
	p = (BTREE)malloc(sizeof(struct node));
 	p->data = data;
 	p->left = NULL;
 	p->right = NULL;
 	return p;
}
 
void inorder(BTREE root){
 	if(root!=NULL){
 		inorder(root->left);
 		printf("%d \t", root->data);
 		inorder(root->right);
	}
}
 
BTREE insert(BTREE root, int data){
 	if(root!= NULL){
 		if(data < root->data)
 			root->left = insert(root->left,data);
 		else
 			root->right = insert(root->right,data);
	}
	else
		root = new_node(data);
		return root;
}
 
int size(BTREE root){
 	
 	if(root==NULL)
 		return 0;
 	else
 		return 1+size(root->left) + size(root->right);
}
 
int leaves(BTREE root){
 	if(root == NULL)
 		return 0;
 		
 	else if(root->left == NULL && root->right == NULL){
 		return 1;
	}
	else
		return leaves(root->left) + leaves(root->right);
}
 
int min_ite(BTREE root){
	if(root!= NULL){
 		while(root->left != NULL)
 			root = root->left;
 		return root->data;
	}
}
// iki çocuðu varsa yer deðiþtirecek.

BTREE mirror(BTREE root){
 
    if (root== NULL)  
    	return;
    else
    { 
        BTREE temp; 
        
        mirror(root->left); 
        mirror(root->right); 
      
        temp= root->left; 
        root->left = root->right; 
        root->right = temp; 
    } 
}  
	
main(){
	
	BTREE myroot = NULL;
	int i;
	scanf("%d", &i);
	
	while(i!= -1){
 		myroot = insert(myroot,i);
 		scanf("%d", &i);	}
	inorder(myroot);
	printf("\n");
	printf("Your min_ite %d\n",min_ite(myroot));
	printf("Your leaves %d\n",leaves(myroot));
	printf("Your size %d\n",size(myroot));
	mirror(myroot); 
	inorder(myroot);
}
 
 
 
 
 

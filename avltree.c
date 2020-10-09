#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	int height;
	struct node *left;
	struct node *right;
};
typedef struct node AVLTREE;

AVLTREE *new_node (int data){
	AVLTREE *p;
	p = (AVLTREE*)malloc(sizeof(AVLTREE));
 	p->data = data;
 	p->left = NULL;
 	p->right = NULL;
 	p->height=0;
 	return p;
}
int maxValue(int x, int y){
	return(x>y ?x:y);
}

AVLTREE *rightRotate(AVLTREE *z){
	AVLTREE *temp = z->left;
	z->left = temp->right;
	temp->right = z;
	z->height = maxValue(z->left==NULL?-1: z->left->height, z->right == NULL ?-1: z->right->height)+1;
	temp->height = maxValue(temp->left==NULL?-1: temp->left->height, temp->right == NULL ?-1: temp->right->height)+1;
	return temp;
}
AVLTREE *leftRotate(AVLTREE *z){
	AVLTREE *temp = z->right;
	z->right = temp->left;
	temp->left = z;
	z->height = maxValue(z->left==NULL?-1: z->left->height, z->right == NULL ?-1: z->right->height)+1;
	temp->height = maxValue(temp->left==NULL?-1: temp->left->height, temp->right == NULL ?-1: temp->right->height)+1;
	return temp;
}

AVLTREE *leftRightRotate(AVLTREE *z){
	z->left = leftRotate(z->left);
	return rightRotate(z);
}
AVLTREE *rightLeftRotate(AVLTREE *z){
	z->right = rightRotate(z->left);
	return leftRotate(z);
}

int height(AVLTREE *root){
	if(root==NULL)
		return -1;
	else{
		int lheight,rheight;
		rheight=height(root->right);
		lheight=height(root->left);
		if(rheight>lheight)
			return rheight+1;
		else
			return lheight+1;
	}
}
void inorder(AVLTREE *root){
 	if(root!=NULL){
 		inorder(root->left);
 		printf("%d \t", root -> data);
 		inorder(root->right);
	}
}

AVLTREE *insertToAVL(int x, AVLTREE *tree) {
	if(tree!=NULL)
	{
		if(x<tree->data)
		 tree->left=insertToAVL(x, tree->left);
		else
		 tree->right=insertToAVL(x,  tree->right);

		tree->height=maxValue(height(tree->left), height(tree->right))+1;
		if((height(tree->left)-height(tree->right))>1 && x< tree->left->data)
		 return rightRotate(tree);

		if((height(tree->left)-height(tree->right))>1 && x> tree->left->data)
		 return leftRightRotate(tree);

		if((height(tree->left)-height(tree->right))< -1 && x> tree->right->data)
		 return leftRotate(tree);

		if((height(tree->left)-height(tree->right))< -1 && x< tree->right->data)
		 return rightLeftRotate(tree);
	}
	else
	  tree=new_node(x);
	return tree;
}

int main(){
	AVLTREE *myroot=NULL;
	int key,secim;
	printf("Veri giriniz... Cikis icin -1 basiniz..");
	scanf("%d",&key);
	while(key!=-1){
		myroot=insertToAVL(key,myroot);
		scanf("%d",&key);
	}
	
	do{
		printf("\n1-Insert\n2-Height\n3 Inorder\n4-Exit\nSeciminiz..?");
		scanf("%d",&secim);
		
		switch(secim){
			case 1:
				printf("Veri giriniz..");
				scanf("%d",&key);
				myroot=insertToAVL(key,myroot);
				printf("Veri Eklendi...");
				break;
			case 2:
				//printf("Height=%d",height(agac));
				printf("Height=%d",myroot->height);
				break;
			case 3:
				inorder(myroot);
				break;
			case 4:
				exit(1);
			default:
				printf("Hatali Secim...");
				break;
		}
	}while(1);
	return 0;
}
	


	

#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node*left;
	struct node*right;
};
struct node*createnode(){
	int n;
	struct node*newnode= NULL;
	printf("enter the data (if you want no node enter -1) =");
	scanf("%d",&n);
	if(n!=-1)
	{
		newnode= (struct node*)malloc(sizeof(struct node));
		newnode->data=n;
		printf("enter left node data of %d\n ",n);
		newnode->left=createnode();
		printf("enter right node data of %d\n ",n);
		newnode->right=createnode();	
	}
	return newnode;
}
void preorder(struct node* root)
{
	if(root!=NULL)
	{
		printf("%d ,",root->data);
		preorder(root->left);	
		preorder(root->right);	
	}
}

int main(){
	struct node*root;
	root=createnode();
	printf("\nPreorder binary tree :");
	preorder(root);	
}

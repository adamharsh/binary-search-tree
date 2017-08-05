#include <iostream>
#include<stdlib.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct node{
	int data;
	node *left;
	node *right;

};
node *root=NULL;
node* create(node*);
void preorder(node*);
void inorder(node*);
void postorder(node*);
int main(int argc, char** argv) {
	root=create(root);
	postorder(root);
	return 0;
}
node* create(node* root){
	int data;
	cout<<"\nEnter data:";cin>>data;
	while(data!=-1)
	{
		if(root==NULL){
			root=new node;
			root->data=data;
			root->left=NULL;
			root->right=NULL;
		}
		else{
			node *temp=root;
			for(;temp!=NULL;){
				if(temp->data>=data){
					if(temp->left==NULL){
						node *new_node=new node;
						new_node->data=data;
						new_node->left=NULL;
						new_node->right=NULL;
						temp->left=new_node;
						break;
					}
					temp=temp->left;
				}
				else{
					if(temp->right==NULL){
						node *new_node=new node;
						new_node->data=data;
						new_node->left=new_node->right=NULL;
						temp->right=new_node;
						break;
					}
					temp=temp->right;
				}
				
			}
		}
		cout<<"\nEnter data:";cin>>data;
	}
	return root;
}
void preorder(node *root){
	if(root!=NULL){
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(node *root){
	if(root!=NULL){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
void postorder(node *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}


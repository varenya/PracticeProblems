#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <stack>

struct node {
	int data;
	struct node * left,*right;
	
};
using namespace std;

bool isBalanced(node * root);
void printLevelOrder(node * root){

	if(root == NULL) return;

	queue<node *> q;
	q.push(root);
	while(q.empty() == false){
		node *n = q.front();
		cout << n->data << " ";
		q.pop();
		if(n->left !=NULL)
			q.push(n->left);
		if(n->right !=NULL)
			q.push(n->right);

	}

	cout << endl;
	
}

int getHeight(node * root){
	if ( root == NULL) return 0;
	else
		return max(getHeight(root->left),getHeight(root->right))+1;
}

bool isBalanced(node * root){
	if(root == NULL) return true;

	else{
		int diff = getHeight(root->left)-getHeight(root->right);
		if( abs(diff) > 1){
			return false;
		}
		else{
			return (isBalanced(root->left) && isBalanced(root->right));
		}
	}
}

void printSpiral(node * root){
	if(root == NULL) return;

	stack<node *> s1;
	stack<node *> s2;

	s1.push(root);

	//cout << root->data << " ";

	while(!s1.empty() || !s2.empty()){

		while(!s1.empty()){
			node * top = s1.top();
			cout << top->data << " ";
			s1.pop();

			if(top->right)
				s2.push(top->right);
			if(top->left)
				s2.push(top->left);
		}

		while(!s2.empty()){

			node * top = s2.top();
			cout << top->data << " ";

			s2.pop();
			if(top->left)
				s1.push(top->left);
			if(top->right)
				s1.push(top->right);
		}

	}

	cout << endl;
}

node * newNode(int data){
	node * temp = new node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

int main()
{
	// Let us create binary tree shown in above diagram
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Level Order traversal of binary tree is \n" << endl;
	printLevelOrder(root);

	node * root1 = newNode(1);
	root1->left        = newNode(2);
	root1->right       = newNode(3);
	root1->left->left  = newNode(7);
	root1->left->right = newNode(6);
	root1->right->left  = newNode(5);
	root1->right->right = newNode(4);
	cout << "Spiral Order traversal of binary tree is \n" << endl;
	printLevelOrder(root1);
	printSpiral(root1);

	if( isBalanced(root1) )
		cout << "Tree is Balanced!" << endl;
	return 0;
}

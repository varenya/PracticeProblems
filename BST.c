#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
	int data;
	int lCount;
	struct node * left,*right;
};

typedef struct node node;


node* newNode(int data){

	node * temp = (node *) malloc(sizeof(node));
	temp ->data = data;
	temp ->lCount = 0;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;
}

node * insertNode(node * root,int data){
	if(root == NULL){
		return newNode(data);
	}
	else if(root->data <  data){
		root->right = insertNode(root->right,data);
	}
	else{
		root->left = insertNode(root->left,data);
	}

	return root;
}

node * search ( node * root ,int key){
	if(root == NULL || root->data == key) 
		return root;
	else if( root->data < key)
		return search(root->right,key);
	return search(root->left,key);
}

node * minValue(node * root)
{
	while(root->left!=NULL)
		root = root->left;
	return root;

}


node * deleteNode(node * root , int key){

	if ( root == NULL ) return root;

	else if ( key > root->data ){
		root->right = deleteNode(root->right,key);
	}
	else if(key < root->data){
		root->left = deleteNode(root->left,key);
	}
	else{

		if(root->right == NULL){
			node * temp = root->left;
			free(root);
			return temp;
		}
		else if(root->left == NULL){
			node * temp = root->right;
			free(root);
			return temp;
		}
		node * minNode = minValue(root->right);
		root->data = minNode->data;
		root->right = deleteNode(root->right,minNode->data);
	}
	return root;
}

void inorder(node * root)
{
		if (root == NULL) return;
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
}

node * lca(node * root,int n1,int n2){
	if (root == NULL) return NULL;
	else if( n1 > root->data && n2 > root->data){
		return lca(root->right,n1,n2);
	}
	else if(n2 < root->data && n1 < root->data){
		return lca(root->left,n1,n2);
	}

	return root;
}


node * sortedArraytoBST(int a[],int start,int end){

	if ( start > end )
		return NULL;

	int mid = (start+end)/2;
	node * root = newNode(a[mid]);

	root->left = sortedArraytoBST(a,start,mid-1);
	root->right = sortedArraytoBST(a,mid+1,end);
	return root;
}

/*
node* findPre(node * root,int key){
	node * temp = search(root,key);
	if (temp == NULL) return temp
	
	else {
	}
}
*/

void findPreSuc(node * root,node ** suc,node ** pre,int key){
	if( root == NULL ) return;

	if(root->data == key){
		if(root->right !=NULL){
			node * temp = root->right;
			while(temp->left!= NULL)
				temp = temp->left;
			*suc = temp;
		}
		if(root->left!=NULL){
			node * temp = root->left;
			while(temp->right!=NULL)
				temp = temp->right;
			*pre = temp;
		}
	}
	else if(key > root->data){
		*pre = root;
	 	findPreSuc(root->right,suc,pre,key);
	}
	else{
		*suc = root;
	 	 findPreSuc(root->left,suc,pre,key);
	}
}


int isBST(node * root){

	return isBSTUtil(root,INT_MIN,INT_MAX);
}

int isBSTUtil(node * root,int min,int max){
	if(root == NULL) return 1;

	else if(root->data < min || root->data > max)
		return 0;
	else
		return (isBSTUtil(root->left,min,root->data-1) && isBSTUtil(root->right,root->data+1,max));
}


node * insert_node(node * root,node * new_node){
	node * currentParent = root;
	node * pTraverse = root;
	while(pTraverse){
		currentParent = pTraverse;
		if(new_node->data > pTraverse->data ){
			pTraverse = pTraverse->right;

		}
		else{
			pTraverse->lCount++;
			pTraverse = pTraverse->left;
		}

	}
	if(!root){
		root = new_node;
	}
	else if(new_node->data > currentParent->data){
		currentParent->right = new_node;
	}
	else{
		currentParent->left = new_node;
	}
}

int k_smallest_node(node * root,int k){

	int ret = -1;
	if(root){
		if(k == (root->lCount+1)){
			ret = root->data;
			return ret;
		}
		else if(k > root->lCount){
			k = k-(root->lCount+1);
			return k_smallest_node(root->right,k);
		}
		else{
			return k_smallest_node(root->left,k);
		}
	}

	return ret;
}

void printInRange(node * root,int n1,int n2){

	if( root == NULL ) return;

	if(n1 < root->data)
		printInRange(root->left,n1,n2);

	if(n1 <= root->data && n2 >= root->data)
		printf("%d ",root->data);	

	if(n2 > root->data)	
		printInRange(root->right,n1,n2);
}



int main(void)
{
	int a[] = {50,30,20,40,60,70,80};
	node * root = NULL;
	root = insertNode(root,a[0]);
	int i=1;
	for(i=1;i<7;i++)
		insertNode(root,a[i]);
	inorder(root);
	node * s = search(root,40);
	printf("\n");
	printf("left child : %d\n",s->left);
	//printf("right child : %d",s->right->data);
	//node * d = deleteNode(root,5);
	printf("\n");
	node * suc = NULL,*pre = NULL;
	findPreSuc(root,&suc,&pre,50);
	inorder(root);
	printf("\n");
	printf("Successor %d\n",suc->data);
	printf("Predecessor %d\n",pre->data);
	inorder(root);
	if(isBST(root))
		printf("Given tree is a BST!!!!!");
	node * newroot = newNode(10);
	newroot->left = newNode(11);
	newroot->right = newNode(12);
	printf("\n");
	if(isBST(newroot) == 1)
		printf("is a bst");
	else
		printf("its not a bst");
	node * la = lca(root,20,40);
	printf("\n %d",la->data);



	printf("\nKth Smallest Key\n");
	node * newTree = newNode(a[0]);
	for(i=1;i<7;i++)
		insert_node(newTree,newNode(a[i]));
	inorder(newTree);
	printf("\n%d \n",k_smallest_node(newTree,3));
	inorder(root);
	printf("\n");
	printInRange(root,10,50);


	int arr[] = {1,2,3,4,5,6};
	int n = sizeof(arr)/sizeof(arr[0]);
	node * sortedroot = sortedArraytoBST(arr,0,n-1);
	printf("\n");
	inorder(sortedroot);
	return 0;

}

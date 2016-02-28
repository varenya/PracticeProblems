#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * left,*right;
};

typedef struct node node;
node * newNode(int data);
node* constructTreeUtil(int pre[],int* preIndex,int low,int high,int size);
node * constructTree(int pre[],int size);
int findIndex(char arr[],int low,int high,int num);
node * constructBinaryTree(char pre[],char inorder[],int low,int high,int* preIndex,int size);
void printLevelOrder(node * root);
void printGivenLevel(node * root,int level);
int height(node *root);

node* constructTreeUtil(int pre[],int* preIndex,int low,int high,int size){

	if( *preIndex >= size || low > high)
		return NULL;

	
	node * root = newNode(pre[*preIndex]);
	*preIndex = *preIndex + 1;

	if(low == high)
		return root;

	int i;
	for(i=low;i<=high;i++){
		if(pre[i]>root->data)
			break;
	}
	root->left = constructTreeUtil(pre,preIndex,*preIndex,i-1,size);
	root->right = constructTreeUtil(pre,preIndex,i,high,size);
	return root;
}


void printLevelOrder(node * root){
	int i=0;
	int h = height(root);
	for(i=1;i<=h;i++)
		printGivenLevel(root,i);
}


void printGivenLevel(node * root,int level){
	if(root == NULL) return;

	else if(level == 1){
		printf("%d ",root->data);
	}
	else{
		printGivenLevel(root->left,level-1);
		printGivenLevel(root->right,level-1);
	}
}


int height(node *root){
	if(root == NULL) return 0;

	int lheight = height(root->left);
	int rheight = height(root->right);

	if(lheight > rheight)
		return lheight+1;
	else
		return rheight+1;
}

node * constructTree(int pre[],int size){
	int preIndex=0;
	return constructTreeUtil(pre,&preIndex,0,size-1,size);
}

node * newNode(int data){
	node * temp = (node *) malloc(sizeof(node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void printInorder(node * root){
	if(root == NULL) return;
	printInorder(root->left);
	printf("%d ",root->data);
	printInorder(root->right);
}
void printInorderChar(node * root){
	if(root == NULL) return;
	printInorder(root->left);
	printf("%c ",root->data);
	printInorder(root->right);
}

node * constructBinaryTree(char pre[],char inorder[],int low,int high,int* preIndex,int size){
	printf("%d \n",size);
	printf("%c \n",pre[*preIndex]);
	printf("low %d\n",low);
	printf("high %d\n",high);
	printf("\n");
	if(low > high) return NULL;
	node * root = newNode(pre[*preIndex]);
	*preIndex = *preIndex + 1;


	int i = findIndex(inorder,low,high,root->data);

	root->left = constructBinaryTree(pre,inorder,low,i-1,preIndex,5); 
	root->right = constructBinaryTree(pre,inorder,i+1,high,preIndex,-5);
	return root;
}

int findIndex(char arr[],int low,int high,int num){
	int i;
	for(i=low;i<=high;i++)
	{
		if(arr[i] == num)
			return i;
	}
	return -1;

}



int main(void){

	int pre[] = {10, 5, 1, 7, 40, 50};
	int size = sizeof( pre ) / sizeof( pre[0] );
	node * root = constructTree(pre,size);
	printInorder(root);

	char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
	char pre1[] = {'A', 'B', 'D', 'E', 'C', 'F'};
	int len = sizeof(in)/sizeof(in[0]);
	printf("\n");
	int preIndex = 0;
	node * root1 = constructBinaryTree(pre1, in, 0, len - 1,&preIndex,len);
	int i;
	for(i=0;i<len;i++)
		printf("%d ",in[i]);
	printf("\n");
	//printInorderChar(root1);
	root = newNode(1);
	root->left        = newNode(2);
	root->right       = newNode(3);
	root->left->left  = newNode(4);
	root->left->right = newNode(5);

	printf("Level Order traversal of binary tree is \n");
	printLevelOrder(root);


	return 0;
}

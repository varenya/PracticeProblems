#include <stdio.h>
#include <stdlib.h>
#define MARKER -1
struct node {
	int data;
	struct node * left,*right;
};

typedef struct node node;
void serialize(node * root,FILE * fp);
void deserialize(node ** root,FILE * fp);
void InOrder(node * root);
node * newNode(int data);

void serialize(node * root,FILE * fp){
	if( root == NULL){
		fprintf(fp,"%d ",MARKER);
		return;
	}
	fprintf(fp,"%d ",root->data);
	serialize(root->left,fp);
	serialize(root->right,fp);
}

void deserialize(node ** root,FILE * fp){
	int val;
	if( !fscanf(fp,"%d ",val) && val == MARKER)
		return;
	printf("%d \n",val);
	*root = newNode(val);
	//printf("%d \n",(*root)->data);
	deserialize((&(*root)->left),fp);
	deserialize((&(*root)->right),fp);

}
void deserialize(node *& root,FILE * fp){
	int val;
	if( !fscanf(fp,"%d ",val) && val == MARKER)
		return;
	printf("%d \n",val);
	root = newNode(val);
	//printf("%d \n",(*root)->data);
	deserialize(root->left,fp);
	deserialize(root->right,fp);

}

node * newNode(int data){

	node * temp = (node *) malloc(sizeof(node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void InOrder(node * root){
	if(root == NULL) return;
	InOrder(root->left);
	printf("%d ",root->data);
	InOrder(root->right);
}

int main()
{
    // Let us construct a tree shown in the above figure
    node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
 
    InOrder(root);
    // Let us open a file and serialize the tree into the file
    FILE *fp = fopen("tree.txt", "w");
    if (fp == NULL)
    {
        puts("Could not open file");
        return 0;
    }
    serialize(root, fp);
    fclose(fp);
 
    // Let us deserialize the storeed tree into root1
    node *root1 = NULL;
    fp = fopen("tree.txt", "r");
    deserialize(&root1, fp);
 
    printf("Inorder Traversal of the tree constructed from file:\n");
    InOrder(root1);
 
    return 0;
}


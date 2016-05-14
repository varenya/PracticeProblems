#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * next;
};



typedef struct node node;

node * addLists(node * list1,node * list2);
void addCarrytoFront(node * list1,node* list2,int * carry,node ** result);
node * addSameSize(node * list1,node* list2,int * carry);
void swapAddress(node ** a , node ** b);

void push(node ** head_ref,int data){
	node * newNode = (node *) malloc(sizeof(node));
	newNode->data = data;
	newNode->next = *head_ref;
	*head_ref = newNode;
}

node * addLists(node * list1,node * list2){

	int carry = 0;

	int size1 = size(list1);
	int size2 = size(list2);

	if(size1 == size2){
		node * result =  addSameSize(list1,list2,&carry);
		return result;
	}
	else{
		if(size1 < size2)
			swapAddress(&list1,&list2);
		int diff = abs(size1-size2);
		node * curr = list1;

		while(diff!=0){
			curr = curr->next;
			diff--;
		}
		printf("%d \n",curr->data);
		printf("%d \n",list2->data);
		node * result = addSameSize(curr,list2,&carry);
		addCarrytoFront(list1,curr,&carry,&result);
		if(carry)
			push(&result,carry);

		return result;
	}
}

void addCarrytoFront(node * list1,node* list2,int * carry,node ** result){

	int sum;
	if(list1 != list2){
		addCarrytoFront(list1->next,list2,carry,result);
		sum = list1->data + *carry;
		*carry = sum/10;
		sum = sum % 10;
		push(result,sum);
	}
}

void swapAddress(node ** a , node ** b){
	node * temp = *a;
	*a = *b;
	*b = temp;
}

node * addSameSize(node * list1,node* list2,int * carry){

	if(list1 == NULL)
		return NULL;

	int sum=0;
	node * result = (node*) malloc(sizeof(node));
	result->next = addSameSize(list1->next,list2->next,carry);
	sum = list1->data + list2->data +*carry;
	*carry = sum/10;
	sum = sum%10;
	result->data = sum;
	return result;
}

int size(node * list){
	int count = 0;
	while(list!=NULL){
		list = list->next;
		count++;
	}
	return count;
}

void traversal(node * head_ref){
	node * temp = head_ref;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}

	printf("\n");
}

void reverse(node ** head_ref){
	node * current = *head_ref;
	node * prev = NULL;
	node * next;
	while(current!=NULL){

		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

void deleteDuplicates(node ** head_ref){
	node * ptr = *(head_ref);
	node * prev;
	node * temp;
	while(ptr!=NULL){
		temp = ptr->next;
		prev = ptr;
		while(temp!=NULL){
			if( ptr->data == temp->data){
				prev->next = temp->next;
				free(temp);
			}
			prev = temp;
			temp = temp->next;
		}
		ptr = ptr->next;
	}
}

node * lastKElement(node * head_ref,int k){

	if( k < 0) return NULL;

	node * ptr1 = head_ref;
	node * ptr2 = head_ref;
	int i = 0;

	for(i=0;i<k-1;i++){
		if(ptr2 == NULL) return NULL;
		else 
			ptr2 = ptr2->next;
	}

	if(ptr2 == NULL) return NULL;

	while(ptr2->next != NULL){
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return ptr1;
	
}

int main(void)
{

	int a[] = {5,4,3,2,1};
	int b[] =   {6,6,3,3,2,1};
	int i=0;
	node * list1 = NULL,*list2 = NULL;
	for(i=0;i<5;i++)
		push(&list1,a[i]);
	for(i=0;i<6;i++)
		push(&list2,b[i]);

	traversal(list1);
	traversal(list2);
	node * result = NULL;
	result = addLists(list2,list1);
	traversal(result);

	reverse(&result);
	traversal(result);

	deleteDuplicates(&list2);
	traversal(list2);

	node * element = lastKElement(list1,2);
	printf("The kth element from last is %d\n",element->data);

}

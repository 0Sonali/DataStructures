#include <iostream>

using namespace std;

struct node
{
	int data;
	node *next;
};

//add first node
void initNode(struct node * head, int n)
{
	head->data = n;
	head->next = NULL;
}

//append a node
void addNode(struct node * head, int n)
{
	struct node *cur = head;
	struct node * newNode = new node;
	newNode->data = n;
	newNode->next = NULL;
	
	while(cur)
	{
		if (cur->next == NULL)
		{
			cur->next = newNode;
			return;
		}
		cur = cur->next;	
	}
}

//insert node in the list at front
void insertNodeAtFront(struct node **head, int n) 
{
	struct node *newNode = new node;
	newNode->data = n;
	newNode->next = *head;
	*head = newNode;
}

//search specific node 
struct node *searchNode(struct node *head, int n) 
{
	node *cur = head;
	while(cur) {
		if(cur->data == n) return cur;
		cur = cur->next;
	}
	cout << "No Node " << n << " in list.\n";
}

//delete node
bool deleteNode(struct node **head, int n) 
{
	node *ptrNode= *head;
	node *ptrDel = searchNode(ptrNode,n);

	node *cur = *head;
	if(ptrDel == *head) {
		*head = cur->next;
		delete ptrDel;
		return true;
	}
	
	while(cur) {
		if(cur->next == ptrDel) {
			cur->next = ptrDel->next;
			delete ptrDel;
			return true;
		}
		cur = cur->next;
	}
	return false;
}

//reverse the list
struct node* reverse(struct node** head) 
{
	struct node *parent = *head;
	struct node *cur = parent->next;
	struct node *child = cur->next;

	parent->next = NULL;
	while(child) {
		cur->next = parent;
		parent = cur;
		cur = child;
		child = child->next;
	}
	cur->next = parent;
	*head = cur;
	return *head;
}

// create copy of lisked list 
void copyLinkedList(struct node *pNode, struct node **pNew)
{
	if(pNode != NULL) {
		*pNew = new node;
		(*pNew)->data = pNode->data;
		(*pNew)->next = NULL;
		copyLinkedList(pNode->next, &((*pNew)->next));
	}
}

//get node at specific position
int getNode(struct node * head, int index)
{
    struct node* cur = head;
    int count = 0; 
    while (cur != NULL)
    {
       if (count == index)
          return(cur->data);
       count++;
       cur = cur->next;
    }          
}

//get size of list
int getSizeOfList(struct node * head)
{
	int size = 0;
	struct node *cur = head;
	while(cur)
	{
		size++;
		cur =  cur->next;
	}
	cout << "count	:"<<size;
	return size;
}

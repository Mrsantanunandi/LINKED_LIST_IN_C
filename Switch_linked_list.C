#include<stdio.h>
#include<stdlib.h>
#define N 50
typedef struct node{
	int data;
	struct node* next;
}Node;

Node* head=NULL;
Node* createnode(int item)
{
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->data=item;
	newnode->next=NULL;
	return newnode;
}

void insert_at_beg(int item)
{
	Node* newnode=createnode(item);
	newnode->next=head;
	head=newnode;
	return;
}

void insert_at_last(int item)
{
	Node* newnode=createnode(item);
	Node* temp=head;
	if(head==NULL)
	{
		head=newnode;
		return;
	}
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	return;
}

void insert_after(int item,int after)
{
	if(head==NULL)
	{
		printf("The Linked list is empty");
		return;
	}
	Node* temp=head;
	while(temp!=NULL)
	{
		if(temp->data==after)
		{
			Node* newnode=createnode(item);
			newnode->next=temp->next;
			temp->next=newnode;
			return;
		}
		temp=temp->next;
	}
	printf("The after element is not found");
}

void insert_before(int item,int before)
{
	if(head==NULL)
	{
		printf("The Linked list is empty");
		return;
	}
	if(head->data==before)
	{
		Node* newnode=createnode(item);
		newnode->next=head;
		head=newnode;
	}
	else
	{
		Node* temp=head;
		while(temp->next!=NULL)
		{
			if(temp->next->data==before)
			{
				Node* newnode=createnode(item);
				newnode->next=temp->next;
				temp->next=newnode;
				return;
			}
			temp=temp->next;
		}
		printf("The BEFORE item is not present");
	}
}

void delete_at_beg()
{
	if(head==NULL)
	{
		printf("Nothing to delete , list is empty");
		return;
	}
	Node* del=head;
	head=head->next;
	free(del);
	return;
}

void delete_at_last()
{
	if(head==NULL)
	{
		printf("Nothing to delete, list is already empty");
		return;
	}
	else if(head->next==NULL)
	{
		free(head);
		head=NULL;
	}
	else
	{
		Node* temp=head;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		Node* del=temp->next;
		temp->next=NULL;
		free(del);
	}
}

void delete_after(int after)
{
	if(head==NULL)
	{
		printf("Link list is alraedy empty, nothing to delete");
		return;
	}
	else
	{
		Node* temp=head;
		while(temp->next!=NULL)
		{
			if(temp->data==after)
			{
				Node* del=temp->next;
				temp->next=temp->next->next;
				free(del);
				return;		
			}
			temp=temp->next;
		}
		if(temp->data!=after)
		{
			printf("The after element is not present");
			return;
		}
	}
}

void delete_before(int before)
{
	if(head==NULL)
	{
		printf("\nLink list is already empty..nothing to delete");
		return;
	}
	else if(head->data==before)
	{
		printf("\nNo list is before the select node");
		return;
	}
	else if(head->next!=NULL && head->next->data==before)
	{
		Node* del=head;
		head=head->next;
		free(del);
	}
	else
	{
		Node* temp=head;
		while(temp->next!=NULL && temp->next->next!=NULL)
		{
			if(temp->next->next->data==before)
			{
				Node* del=temp->next;
				temp->next=temp->next->next;
				free(del);
				return;
			}
			temp=temp->next;
		}
		printf("\nBefore value not found");
	}
}

void delete_particular_node(int item)
{
	if(head==NULL)
	{
		printf("Link list is alraedy empty, nothing to delete");
		return;
	}
	else if(head->next==NULL && head->data==item)
	{
		Node* del1=head;
		head=NULL;
		free(del1);
		return;
	}
	else if(head->next!=NULL && head->data==item)
	{
		Node* temp=head;
		Node* del3=temp;
		head=temp->next;
		free(del3);
		return;
	}
	else
	{
		Node* temp=head;
		while(temp->next!=NULL)
		{
			if(temp->next->data==item)
			{
				Node* del=temp->next;
				temp->next=temp->next->next;
				free(del);
				return;		
			}
			temp=temp->next;
		}
		if(temp->data!=item)
		{
			printf("The after element is not present");
			return;
		}
	}
}

int count_node()
{
	int count=0;
	Node* temp=head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}

void reverse()
{
	Node* ptr=head;
	int stack[N],x;
	int top=-1;
	while(ptr!=NULL)
	{
		if(top==N-1)
		{
			printf("The stack is overflow");
		}
		else
		{
			top++;
			stack[top]=ptr->data;
		}
		ptr=ptr->next;
	}
	while(top!=-1)
	{
		if(top==-1)
		{
			printf("List is empty...");	
		}
		else
		{
			x=stack[top];
			top--;
			printf("%d\t",x);
		}
	}
	
}

void display()
{
	Node* temp=head;
	if(head==NULL)
	{
		printf("The list is empty");
		return;
	}
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}

int main()
{
	int ch,term,term2;
	printf("\nMENU\n1.Insert at first\n2.Insert at last\n3.Insert after a node\n4.Insert before a node\n5.Delete at first\n6.Delete at last\n7.Display\n8.Delete after a node\n9.Delete before a node\n10.Delete a particular node\n11.Count Node\n12.Reverse List\n13.Exit\n");
	while(1){
	printf("\nEnter your choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1:
				printf("Enter the element you want to insert: ");
				scanf("%d",&term);
				insert_at_beg(term);
				break;
			case 2:
				printf("Enter the element you want to insert: ");
				scanf("%d",&term);
				insert_at_last(term);
				break;
			case 3:
				printf("Enter the node item after which you want to insert: ");
				scanf("%d",&term);
				printf("Enter the element you want to insert: ");
				scanf("%d",&term2);
				insert_after(term2,term);
				break;
			case 4:
				printf("Enter the node item after which you want to insert: ");
				scanf("%d",&term);
				printf("Enter the element you want to insert: ");
				scanf("%d",&term2);
				insert_before(term2,term);
				break;
			case 5:
				delete_at_beg();
				break;
			case 6:
				delete_at_last();
				break;
			case 7:
				display();
				printf("\n");
				break;
			case 8:
				printf("Enter the after value for delete its after node: ");
				scanf("%d",&term);
				delete_after(term);
				break;
			case 9:
				printf("Enter the before value for delete its before node: ");
				scanf("%d",&term);
				delete_before(term);
				break;
			case 10:
				printf("Enter the node element you want to delete: ");
				scanf("%d",&term);
				delete_particular_node(term);
				break;
			case 11:
				term=count_node();
				printf("The No of nodes is %d",term);
				break;
			case 12:
				printf("\nThe reverse list is: ");
				reverse();
				break;
			case 13:
				printf("EXIT\n");
				return 0;
			default:
				printf("Invalid Choice\n");
		}
	}
	return 0;
}

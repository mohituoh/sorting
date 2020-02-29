#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;

};
struct node* head1=NULL;
struct node* head2=NULL;
struct node* t;
struct node* create_node(int data)
{
	struct node* t= malloc(sizeof(struct node));
	t->data=data;
	t->next=NULL;
	return t;

}
create_linked_list(struct node** head,int data)
{
	if(*head==NULL)	
	{
		*head=create_node(data);
		t=*head;
		
	}
	else
	{
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=create_node(data);


	}


}
struct node* sorted_list(struct node* a,struct node* b)
{

	struct node* result=NULL;

	if(a==NULL)
	{
		return b;
	}
	else if(b==NULL)
	{
		return a;
	}
	if(a->data<=b->data)
	{
		result=a;
		result->next=sorted_list(a->next,b);
	}
	else
	{
		result=b;
		result->next=sorted_list(a,b->next);
	}
	return(result);
	
	

}

void main()
{
	create_linked_list(&head1,1);
	create_linked_list(&head1,3);
	create_linked_list(&head1,7);
	create_linked_list(&head1,8);
	create_linked_list(&head1,12);
	create_linked_list(&head2,45);
	create_linked_list(&head2,47);
	create_linked_list(&head2,50);
	create_linked_list(&head2,60);
	create_linked_list(&head2,70);
	create_linked_list(&head2,80);
	printf("\nlist 1 data  is ");
	printf("\n%d",head1->data);
	printf("\n%d",head1->next->data);
	printf("\n%d",head1->next->next->data);
	printf("\nlist 2 data  is ");
	printf("\n%d",head2->data);
	printf("\n%d",head2->next->data);
	printf("\n%d",head2->next->next->data);
	struct node* p=sorted_list(head1,head2);
	printf("\nthis is sorted list\n");
	while(p!=NULL)
	{
		printf("%d",p->data);
		p=p->next;
		printf("\n");
	}
}



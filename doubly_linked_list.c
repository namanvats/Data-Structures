#include<stdio.h>
#include<stdlib.h>
struct list{
	int data;
	struct list *next;
	struct list *prev;
};
typedef struct list node;
node* head=NULL;
node* last=NULL;
node* create()
	{
		node *temp;
		temp=(node*)malloc(sizeof(node));
		temp->next=NULL;
		temp->prev=NULL;
		return temp;
	}
node* add(int element)
	{
		node *temp,*p;
		temp=create();
		temp->data=element;
		if(head==NULL)
			{
				head=last=temp;
			}
		else
			{
				p=head;
				while(p->next!=NULL)
					{
						p=p->next;
					}
				p->next=temp;
				temp->prev=p;
				last=temp;
			}
	}
void display()
	{
		node *p,*q;
		p=head;
		q=last;
		while(p->next!=NULL)
			{
				printf("%d->",p->data);
				p=p->next;
			}
		printf("%d",p->data);
		printf("\n");
		while(q->prev!=NULL)
			{
				printf("%d->",q->data);
				q=q->prev;
			}
			printf("%d",q->data);
	}
int main()
{
	printf("type -1 to print and terminate \n");
	while(1)
	{
		int value;
		scanf("%d",&value);
		if(value==-1)
			{
				display();
				break;
			}
		else
			{
				add(value);
			}
	}
	return 0;
}

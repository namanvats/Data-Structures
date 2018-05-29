#include<stdio.h>
#include<stdlib.h>
struct list{
	int data;
	struct list *next;
};
typedef struct list node;
node* head=NULL;
node* create()
	{
		node *temp;
		temp=(node*)malloc(sizeof(node));
		temp->next=NULL;
		return temp;	
	}
node *add(int value)//addition in front;
	{
		node *temp,*p;
		temp=create();
		temp->data=value;
		if(head==NULL)
			{
				head=temp;
			}
		else
			{
				p=head;
				head=temp;
				head->next=p;
			}
	}
void delete(int key)
	{
		node *p,*temp,*p2;
		p=head;
		while(p->next->data!=key)
			{
				p=p->next;
			}
			p2=p->next->next;
			temp=p;
			temp=NULL;
			p->next=p2;
	}
void display()
	{
		node *p;
		p=head;
		while(p->next!=NULL)
			{
				printf("%d->",p->data);
				p=p->next;
			}
		printf("%d",p->data);
	}
int main()
	{
		while(1)
			{
				int ch;
				scanf("%d",&ch);
						if(ch==1)
							{
								int element;
								scanf("%d",&element);
								add(element);
							}
						if(ch==2)
							{
								int key;
								scanf("%d",&key);
								delete(key);
							}
						if(ch==3)
							{
								display();
							}
						if(ch==4)
							{
								break;
							}
			}
		return 0;
	}

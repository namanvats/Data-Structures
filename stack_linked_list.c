#include<stdio.h>
#include<stdlib.h>
int cnt=0;
struct list{
	int data;
	struct list *next;
};
typedef struct list node;
node *head=NULL;
node *create()
	{
		node *temp;
		temp=(node*)malloc(sizeof(node));
		temp->next=NULL;
		return temp;
	}
node *push(int value)
	{
		node *temp,*p;
		temp=create();
		temp->data=value;
		if(head==NULL)
			{
				head=temp;
				cnt++;
			}
		else
			{
				p=head;
				while(p->next!=NULL)
					{
						p=p->next;
					}
					p->next=temp;
				cnt++;
			}
	}
node *del()
	{
		node *p;
		if(cnt==0)
			{
				printf("Stack is empty\n");
			}
		else
			{
				p=head;
				if(cnt!=1)
					{
						while(p->next->next!=NULL)
					{
						p=p->next;
					}
						printf("popped elenment is %d",p->next->data);
						p->next->data=NULL;
						p->next=NULL;
						cnt--;
					}
				else
					{
						printf("popped elenment is %d",p->data);
						p=NULL;
						free(p);
						cnt--;
					}
			}
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
				printf("Press\n1.Push\n2.POP\n3.Display\n4.end\n5.Size of stack");
				int ch;
				scanf("%d",&ch);
					if(ch==1)
						{
							int value;
							scanf("%d",&value);
							push(value);
						}
					if(ch==2)
						{
							del();
						}
					if(ch==3)
						{
							display();
						}
					if(ch==4)
						{
							break;
						}
					if(ch==5)
						{
							printf("%d",cnt);
						}
			}
	}

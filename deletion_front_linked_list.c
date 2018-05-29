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
node *add(int value)
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
				while(p->next!=NULL)
					{
						p=p->next;
					}
					p->next=temp;
			}
	}
void delete()
	{
		node *p;
		p=head;
		printf("Deleted value is %d",p->data);
		p=NULL;
		head=head->next;	
	}
void display()
	{
		node *p;
		p=head;
		while(p->next!=NULL)
			{
				printf("%d-->",p->data);
				p=p->next;
			}
			printf("%d",p->data);
	}
int main()
{
	while(1)
	{
		printf("\nPress\n1.Add value\n2.delete\n3.display\n4.end\n");
		int ch;
		scanf("%d",&ch);
		if(ch==1)
		{
			int element1;
			scanf("%d",&element1);
			add(element1);
		}
		if(ch==2)
			{
				delete();
			}
		if(ch==3)
			{
				display();
			}
		if(ch==4)
			break;
	}
		
}

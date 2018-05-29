#include<stdio.h>
#include<stdlib.h>
int count=0;
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
node *add(int value)
	{
		node *temp,*p;
		temp=create();
		temp->data=value;
		if(head==NULL)
			{
				head=temp;
				count++;
			}
		else
			{
				p=head;
				while(p->next!=NULL)
					{
						p=p->next;
					}
				p->next=temp;
				count++;
			}
		
	}
node *add_mid(int value)
	{
		int location=1;
		node *temp,*p,*p2;
		temp=create();
		temp->data=value;
		if(count==0 || count==1)
			{
				printf("Error\n");
			}
		else
			{
				p=head;
				if(count%2==0)
					{
						while(location<(count/2))
							{
								p=p->next;
								location++;
							}
							p2=p;
							p2=p2->next;
							p->next=temp;
							temp->next=p2;	
							count++;
					}
				if(count%2!=0)
					{
						while(location<((count+1)/2))
							{
								p=p->next;
								location++;
							}
							p2=p;
							p2=p2->next;
							p->next=temp;
							temp->next=p2;
							count++;	
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
	printf("Enter -1 to end the program\n");
	while(1)
	{
		printf("Press\n1.Add value\n2.Add value at middle\n3.display\n4.end\n");
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
				int element;
				scanf("%d",&element);
				add_mid(element);
			}
		if(ch==3)
			{
				display();
			}
		if(ch==4)
			break;
	}
return 0;
}

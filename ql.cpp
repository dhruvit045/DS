#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start;
void insertfirst(struct node*);
void insertlast(struct node*);
void deletefirst(struct node*);
void deletelast(struct node*);
void display(struct node*);
void main()
{
	int ch;
	clrscr();
	start=NULL;
	do
	{
		printf("\n\t1.Insert first");
		printf("\n\t2.Insert last");
        printf("\n\t3.Delete first");
		printf("\n\t4.Delete last");
		printf("\n\t5.Display");;
		printf("\n\tEnter your choice=>");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insertfirst(start);
				break;
			case 2:
				insertlast(start);
				break;
            case 3:
				deletefirst(start);
				break;
			case 4:
				deletelast(start);
				break;
			case 5:
				display(start);
				break;	
			case 0:
				printf("\n\tExit");
				break;
			default:
				printf("\n\tEnter 0 to 5 only");
		}
	}while(ch!=0);
	getch();
}
void insertfirst(struct node *p)
{
	int no;
	printf("\n\t Enter any number=>");
	scanf("%d",&no);
	start=(struct node*)malloc(sizeof(struct node));
	start->data=no;
	start->next=p;
}
void insertlast(struct node *p)
{
	int no;
	printf("\n\tEnter any number=>");
	scanf("%d",&no);
	if(start==NULL)
	{
		start=(struct node*)malloc(sizeof(struct node));
		start->data=no;
		start->next=NULL;
	}
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=(struct node*)malloc(sizeof(struct node));
		p->next->data=no;
		p->next->next=NULL;
	}

}
void deletefirst(struct node *p)
{
	printf("\n\tDelete element is=>%d",p->data);
	start=start->next;
	free(p);
}
void deletelast(struct node *p)
{
	struct node *temp;
	while(p->next->next!=NULL)
	{
		p=p->next;
	}	
	temp=p->next;
	p->next=NULL;
	printf("\n\tDelete Elemmment is=>%d",temp->data);
	free(temp);
}
void display(struct node *p)
{
	if(start==NULL)
	{
		printf("\n\tlinked is empty");
	}
	else
	{
		while(p!=NULL)
		{
			printf("\t%d",p->data);
			p=p->next;
		}
	}
}
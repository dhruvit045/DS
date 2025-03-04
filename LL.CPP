#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start;
void insertfirst(struct node*);
void insertlast(struct node*);
void insertspecific(struct node*);
void display(struct node*);
void deletefirst(struct node*);
void deletelast(struct node*);
void deletespecific(struct node*);
void search(struct node*);
void sort(struct node*);
void main()
{
	int ch;
	clrscr();
	start=NULL;
	do{
		printf("\n\t1. INSERT FIRST");
		printf("\n\t2. INSERT LAST");
		printf("\n\t3. INSERT SPECIFIC");
		printf("\n\t4. DISPLAY");
		printf("\n\t5. DELETE FIRST");
		printf("\n\t6. DELETE LAST");
		printf("\n\t7. DELETE SPECIFIC");
		printf("\n\t8. SEARCH");
		printf("\n\t9. SORT");
		printf("\n\t0. EXIT");
		printf("\n\tENTER YOUR CHOICE :: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :
				insertfirst(start);
				break;
			case 2 :
				insertlast(start);
				break;
			case 3 :
				insertspecific(start);
				break;
			case 4 :
				display(start);
				break;
			case 5 :
				deletefirst(start);
				break;
			case 6 :
				deletelast(start);
				break;
			case 7 :
				deletespecific(start);
				break;
			case 8 :
				search(start);
				break;
			case 9 :
				sort(start);
				break;
			case 0 :
				printf("\n\tEND OF PROGRAM");
				break;
			default :
				printf("\n\tPLZ ENTER 0 TO 9 DIGIT");
			}
	}while(ch!=0);
getch();
}
void insertfirst(struct node*p)
{
	int no ;
	printf("\n ENTER ANY NUMBER :: ");
	scanf("%d",&no);
	start=(struct node*)malloc(sizeof(struct node));
	start->data=no;
	start->next=p;
}
void insertlast(struct node*p)
{
	int no ;
	printf("\n\tENTER ANY NUMBER ::");
	scanf("%d",&no);
	if(start==NULL)
	{
		start=(struct node*)malloc(sizeof(struct node));
		start->data=no;
		start->next=NULL;
	}
	else{
		while(p->next!=NULL)
		{
			p=p->next;

		}
		p->next=(struct node*)malloc(sizeof(struct node));
		p->next->data=no;
		p->next->next=NULL;
	}
}
void insertspecific(struct node*p)
{
		int i , pos ,no ;
		struct node*temp;
		printf("\n\tENTER POSITION ::");
		scanf("%d",&pos);
		printf("\n\tENTER ANY NUMBER ::");
		scanf("%d",&no);
		for(i=1;i<=pos;i++)
		{
			p=p->next;
			if(p==NULL)
			{
				printf("\n\tENTER PROPER POSITION ::");
				break;
			}
		}
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=no;
		temp->next=p->next;
		p->next=temp;
}
void display(struct node*p)
{
	if(start==NULL)
	{
		printf("\n\tLINKED IS EMPTY");
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
void deletefirst(struct node*p)
{
	printf("\n\tDELETE ELEMENT IS ::%d",p->data);
	start=start->next;
	free(p);
}
void deletelast(struct node*p)
{
	struct node *temp;
	while(p->next->next!=NULL)
	{
		p=p->next ;

	}
	temp=p->next;
	p->next=NULL;
	printf("\n\tDELETE ELEMENT IS :: %d",temp->data);
	free(temp);
}
void deletespecific(struct node*p)
{
	int pos , i ;
	struct node *temp ;
	printf("\n\tENTER POSITION ::");
	scanf("%d",&pos);
	for(i=1;i<=pos;i++)
	{
		p=p->next;
	}
	temp=p->next;
	printf("\n\tDELETE ELEMENT IS :: %d",temp->data);
	p->next=p->next->next ;
	free(temp);
}
void search(struct node*p)
{
	int key , count=0, pos=1 ;
	if(start==NULL)
	{
		printf("\n\tLINKED LIST IS EMPTY .......");
	}
	else
	{
		printf("\n\tENTER SEARCH ELEMENT :: ");
		scanf("%d",&key);
		while(p!=NULL)
		{
			if(p->data==key)
			{
				printf("\n\t%d IS FOUND %d POSITION",key ,pos);
				count=1;
			}
			p=p->next;
			pos++;
		}
	}
}

void sort(struct node *p)
{
	int no ;
	struct node *temp;
	if(start==NULL)
	{
		printf("\n\tLINKED LIST IS EMPTY.......");

	}
	else{
		while(p->next!=NULL)
		{
			temp=p->next;
			while(temp!=NULL)
			{
				if(p->data>temp->data)
				{
					no=temp->data;
					temp->data=p->data;
					p->data=no;
				}
				temp=temp->next;
			}
			p=p->next;
		}
	}
}


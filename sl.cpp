#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data ;
    struct node *next ;
};
struct node *start ;
void insert( struct node *);
void Delete( struct node *);
void display ( struct node *);
void main ()
{
    int ch ;
    start=NULL;
    do{
	printf("\n\t1. INSERT ");
	printf("\n\t2. DELETE ");
	printf("\n\t3. DISPLAY ");
	printf("\n\tENTER YOUR CHOICE :: ");
	scanf("%d",&ch);
	switch(ch)
	{
	    case 1 :
		    insert(start);
		    break;
	    case 2 :
		    Delete(start);
		    break;
	    case 3  :
		    display(start);
		    break;
	    case 0  :
		    printf("\n\tEND OF PROGRAM  ............");
	    default :
		    printf("\n\tPLZ ENTER 0 TO 4 DIGIT ........");
	}
    }while(ch!=0);
    getch();
}
void insert(struct node*p)
{
	int no ;
	printf("\n\tENTER ANY NUMBER ::");
	scanf("%d",&no);
	if(start==NULL)
	{
		start=(struct node*)malloc(sizeof(struct node));
		start->data=no;
		start->next=p;
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

void Delete(struct node*p)
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
void display(struct node*p)
{
	if(start==NULL)
	{
		printf("\n\tSTACK LINKED IS EMPTY");
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
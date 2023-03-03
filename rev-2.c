#include <stdio.h>
#include <stdlib.h>

struct node
{
	int num;
	struct node * next;
};


struct node* createNode(int k)
{
	struct node* p = NULL; 
	p = (struct node*)malloc(sizeof(struct node));
	p-> num = k;
	p->next = NULL;
	return(p);
}

struct node * insertLast(struct node* h, int k)
{
	struct node* p = createNode(k);
	if (h==NULL)
	{
		return(p);
	}
	struct node * t = h;
	while(h->next!=NULL)
		h= h->next;
	h->next= p;	
	return(t);
}

void printList(struct node* h)
{
	while(h!=NULL)
	{
		printf("%d\n",h->num);
		h= h->next;
	}
}
void clearList(struct node *h)
{
	struct node *t = NULL;
	while (h!=NULL)
	{
		t=h->next;
		free(h);
		h=t;
	}
}

int main()
{
	int num = 0, j=0, k=0;
	struct node *pres= NULL, *prev=NULL, *new= NULL, *h=NULL;
	
		printf("Enter no. of elements:");
		scanf("%d",&num);
		printf("Enter the element:");
		scanf("%d",&j);
		h= insertLast(h, j);
		for (int i = 1; i < num; i++)
		{
			printf("Enter the element:");
			scanf("%d",&j);
			insertLast(h, j);	
		}
		pres= h;
		
		while(pres!=NULL)
		{
			new = pres->next;
			pres->next = prev;
			prev= pres;
			pres= new;
		}
		h= prev;
	printf("Reversed list\n");
	printList(h);
	clearList(h);
		

}

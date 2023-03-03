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

void swapFunc(struct node * h1, struct node *h2)
{
	int t=0;
	t = h1->num;
	h1->num= h2->num;
	h2->num = t;
}

int main()
{
	int num = 0, j=0, k=1;
	struct node* h = NULL, *t1=NULL, *t2= NULL;

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
		t1=h;
		t2=NULL;


		for(int i=1; i<=num ; i++)
		{	
			t2=t1;
			for(j=i; j<num; j++)
			{
				t2=t2->next;
			}
			swapFunc(t1, t2);
			num= num-1;
			t1=t1->next;
		}

	printf("New list:\n");
	
	printList(h);
	clearList(h);
}

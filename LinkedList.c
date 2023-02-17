#include<stdio.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node *prev, *next;
};

struct node* createNode(int k)
{
	struct node *p =NULL;
	p = (struct node*)malloc(sizeof(struct node));
	p->num= k;
	p->prev= NULL;
	p->next= NULL;
	return(p);
}

struct node* insertfirst(struct node*h, int k)
{
	struct node* p = createNode(k);
	p->next = h ;
	if(h!=NULL)
		h->prev = p;
	return(p);
}

void insertLast(struct node*h, int k)
{
	struct node*p = createNode(k);
	while(h->next!=NULL)
		h= h->next;
	h->next = p ;
	p->prev = h;
}

void printList(struct node*h)
{
	while(h!=NULL)
	{	
		printf("%d\n",h->num);
		h= h->next; 
	}
}

struct node* insertBefore(struct node*h, int x, int k)
{
	struct node* t= h;
	struct node*p = createNode(k);
	if(h->num==x)
	{
		h->prev= p;
		p->next = h;
		return(p);
	}
	
	while(t->num!=x)
	{
		t = t->next;
	}
	p->prev = t->prev;
	t->prev->next = p;
	p->next = t;
	t->prev = p;
	return(h);
}

void insertAfter(struct node*h, int x, int k)
{
	struct node *p = createNode(k);
	while(h->num != x)
		h=h->next;
	p->prev= h;
	p->next = h->next;
	h->next = p;
}

struct node * removeElement(struct node *h, int x)
{
	struct node *t= NULL;
	if(h->num==x)
	{
		t= h->next;
		free(h);
		return(t);
	}
	t=h;
	while(t->num !=x)
	{
		t=t->next;
	}
	if(t->next!=NULL)
	{
		t->prev->next = t->next;
		t->next->prev = t-> prev;
		free(t);
		return(h);
	}
	
	t->prev->next= NULL;
	free(t);
	return(h);	
}

void clearList(struct node* h)
{
	struct node *t= NULL;
	
	while(h!=NULL)
	{
		t= h;
		h=h->next;
		free(t);
	}
	return;
}

void selectionFunc(struct node *head)
{
		char sel[3];
		int j,x,a;

	printf("What do you want to do with the list?\n1.Print the List\n2.Insert Before a given number\n3.Insert after a given number\n4.Remove an Element\n5.Clear the List\n");
	printf("Choose your option:");
	scanf("%d",&a);
	switch (a)
	{
		case 1: 
			printList(head);
			break;

		case 2:
			printf("Enter the element that you want to insert before:\n");
			scanf("%d", &j);
			printf("Enter the new element:\n");
			scanf("%d",&x);
			head = insertBefore(head, j, x);
			printf("Do you want to print the new list?\n");
			scanf("%s", sel);
			if(sel[0]=='y')
			printList(head);
			break;

		case 3:
			printf("Enter the element that you want to insert after:\n");
			scanf("%d", &j);
			printf("Enter the new element:\n");
			scanf("%d",&x);
			insertAfter(head, j, x);
			printf("Do you want to print the new list?\n");
			scanf("%s", sel);
			if(sel[0]=='y')
			printList(head);
			break;

		case 4:
			printf("Enter the element that you want to remove:\n");
			scanf("%d", &j);
			head = removeElement(head, j);
			printf("Do you want to print the new list?\n");
			scanf("%s", sel);
			if(sel[0]=='y')
			printList(head);
			break;

		case 5:
			clearList(head);
	}

	printf("Do you want to continue?\n");
	scanf("%s", sel);
	if(sel[0]=='y')
		selectionFunc(head);
	else printf("Thank you for using. Sairam \n");

}

int main()
{
	int a, num, j, x;
	struct node* head =NULL;
	printf("What kind of Insertion method do you want to use?\n1.Insertfirst\n2.Insertlast\n");
	scanf("%d",&a);
	printf("Enter the number of element\n");
	scanf("%d", &num);

	switch(a)
	{
		case 1:
			for (int i = 0; i < num; i++)
			{
				printf("Enter the element:");
				scanf("%d",&j);
				head= insertfirst(head, j);
			}
			break;

		case 2: 
			printf("Enter the element:");
			scanf("%d",&j);
			head= createNode(j);
			for (int i = 1; i < num; i++)
			{
				printf("Enter the element:");
				scanf("%d",&j);
				insertLast(head, j);
			}
			break;		
	}
	
	selectionFunc(head);
}



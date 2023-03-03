#include <stdio.h>
#include <stdlib.h>

struct term
{
	int cf, exp;
	struct term *next;
};

struct term * createTerm(int cf, int exp)
{
	struct term * p = NULL;
	p = (struct term *)malloc(sizeof(struct term));
	p->cf = cf;
	p->exp = exp;
	p->next = NULL;
	return(p);
}

struct term* insertTerm(struct term* h, int cf, int exp)
{
	struct term* p;

	if (h==NULL)
	{
		return(createTerm(cf,exp));
	}
	
	if(exp > h->exp)
	{
		p= createTerm(cf, exp);
		p->next = h;
		return(p);
	}

	else if(exp == h->exp)
	{
		h->cf+=cf;
		return(h);
	}
	struct term * t= h;

	while(t->next!=NULL && t->next->exp>exp)
	{
		t= t->next;

	}
	if (t->next!=NULL && t->next->exp == exp)
	{
		t->next->cf+=cf;
		return(h);
	}
	p= createTerm(cf, exp);
	p->next = t->next;
	t->next = p;
	return(h);
}

struct term* addFunction(struct term*p1, struct term* p2)
{
	struct term *psum= NULL;
	while(p1!=NULL)
	{
		psum = insertTerm(psum, p1->cf, p1->exp);
		p1=p1->next;
	}
	
	while(p2!=NULL)
	{
		psum = insertTerm(psum, p2->cf, p2->exp);
		p2=p2->next;
	}
	return(psum);

}

void printPolynomial(struct term* h)
{
	if(h->exp!=0)
	{
		if(h->cf==1)
			printf("x^%d",h->exp);
		else if(h->cf ==-1)
			printf("-x^%d",h->exp);
		else
			printf("%dx^%d",h->cf,h->exp);
	}
	else
		printf("%d",h->cf);
	h=h->next;
	while(h!=NULL)
	{
		if(h->exp!=0)
		{
			if(h->cf==1)
				printf("+x^%d",h->exp);
			else if(h->cf ==-1)
				printf("-x^%d",h->exp);
			else if(h->cf>1)
				printf("+%dx^%d",h->cf,h->exp);
			else 
				printf("%dx^%d",h->cf,h->exp);
		}	
		else
		{
			if(h->cf>0)
				printf("+%d",h->cf);
			else
				printf("%d",h->cf);
		}		
		h=h->next;
	}
	printf("\n");
}

int main()
{
	struct term* p1=NULL, *p2=NULL, *psum=NULL;
	int exp = 0, cf=0;
	printf("Enter the first polynomial(exp=-1 indicates end of polynomial):\n");
	while(1)
	{
		printf("Enter coefficient & Exponent:");
		scanf("%d %d",&cf, &exp);
		if(exp!=-1)
			p1 = insertTerm(p1, cf, exp);
		else
		{
			break;
		}
	}
	exp = 0;
	
	printf("Enter the second polynomial(exp=-1 indicates end of polynomial):\n");
	while(1)
	{
		printf("Enter coefficient & Exponent:");
		scanf("%d %d",&cf, &exp);
		if(exp!=-1)
			p2 = insertTerm(p2, cf, exp);
		else
		{
			break;
		}
	}
	psum = addFunction(p1,p2);
	printPolynomial(psum);
}

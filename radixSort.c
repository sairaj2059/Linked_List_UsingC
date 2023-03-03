#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node* next;
};

struct node* createNode(int k)
{
	struct node* p = NULL; 
	p = (struct node*)malloc(sizeof(struct node));
	p-> val = k;
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

int main()
{
	int *arr= NULL,N=0, max =0, nd=0, p=1, k=0,d=0;
	struct node * buckets[10]= {}, *t=NULL;
	printf("Enter the size of the array:\n");
	scanf("%d",&N);
	arr = (int *)malloc(N*sizeof(int));
	printf("Enter the elements for the array:\n");
	for (int i = 0; i < N; i++)
	{
		scanf("%d",arr+i);
	}

	max= arr[0];
	for (int i = 1; i < N; i++)
	{
		if (arr[i]>max)
		{
			max = arr[i];
		}
	}

	while(max>0)
	{
		nd+=1;
		max/=10;
	}


	for (int i = 0; i < nd; i++)
	{
		k=0;
		for (int j = 0; j <N ; j++)
		{
			d= (arr[j]/p)%10;
			buckets[d]=insertLast(buckets[d],arr[j]);
		}

		for (int j = 0; j <10 ; j++)
		{
			while(buckets[j]!=NULL)
			{
				arr[k]= buckets[j]->val;
				t= buckets[j]->next;
				free(buckets[j]);
				buckets[j]= t;
				k++;
			}
		}
		p*=10;
	}
	printf("Sorted:\n");
	for (int i = 0; i < N; i++)
	{
		printf("%d\n",arr[i] );
	}


}

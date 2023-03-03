#include<stdio.h>
#include<stdlib.h>

struct node 
{
	char[5] val;
	struct node* next;
};
 struct first
 {
 	struct node* top;
 };
 
 struct node* createNode(char x)
 {
 	struct node * p =NULL;
 	p = (struct node*) malloc(sizeof(struct node));
 	p->val = x;
 	p->next = NULL;
 	return(p);
 }
 
void PUSH(struct node **h, char  k)
{
	struct node* n = createNode(k);
	if(*h==NULL)
	{
		*h= n;
		return;
	}
	n->next = *h;
	*h= n;
 	
}
 
char pop(struct node ** h)
 {
 	struct node *k=NULL;
 	char t[5] ={};
 	if(*h==NULL)
 	{
 		printf("Stack Underflow\n");
 		return(0);
 	}
 	
 	t= (*h)->val ;
 	k = *h;
 	*h = (*h)->next;
 	free(k);
 	return(t);

 }
 int main()
 {
 	struct first stack= {};
 	int p=0;
 	char sel[3]={}, oprinx[5]= {}, oprpox[50]={};
 	
 	while(1)
 	{
 		printf("->");
 		scanf("%s",oprinx);
 		if(oprinx[0]='0')
 			break;
 			
 		if(oprinx[0]=='*')
 		
 		
 	}
 	
 	while(oprinx[count]!='\0')
	{
		 count++;
	}
	
	for(int i= 0; i<count; i++)
	{
		if(oprinx[i]>='' && oprinx[i]<='9')
		{
			PUSH(&stack.top, oprinx[i])
		}
	
	}
 	
 		printf("Do you want to pop?\n");
		scanf("%s", sel);
		if(sel[0]=='y')		
			p= pop(&stack.top);
		if(p!=-1)
			printf("First element is the stack was %d\n", p);
 }
 

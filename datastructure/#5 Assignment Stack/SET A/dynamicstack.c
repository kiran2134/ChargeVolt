#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
   int data;
   struct node *next;
};
struct node *top=NULL;
void push();
void pop();
void peek();
void display();
void push(int item)
{
    struct node *nptr=malloc(sizeof(struct node));
    nptr->data=item;
    nptr->next=top;
    top=nptr;
}
void pop()
{
    if(top==NULL)
    {
	printf("Stack is empty");
    }
    else
    {
       struct node *temp;
       temp=top;
       top=top->next;
       printf("\nDeleted %d",temp->data);
       free(temp);
    }
}
void display()
{
    struct node *ptr;
    for(ptr=top;ptr!=NULL;ptr=ptr->next)
    printf("\n%d",ptr->data);
}
void peek()
{
    printf("\nPeeked %d",top->data);
}
void main()
{
    int n,ch;
    //clrscr();
    while(1)
    {
	printf("\n\nStack Menu\n1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. EXIT");
	printf("\nEnter the Choice:");
	scanf("%d",&ch);
	switch(ch)
	{
	   case 1:printf("Enter the number:");
		  scanf("%d",&n);
		  push(n);
		  break;
	   case 2:pop();break;
	   case 3:peek();break;
	   case 4:display();break;
	   case 5:exit(0);
	}
	getch();
    }
}
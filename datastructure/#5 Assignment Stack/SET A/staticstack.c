#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 5
int stack[size];
int top=-1;
void push()
{
   int n;
   if(top==size-1)
   {
       printf("\nStack is full");
   }
   else
   {
       printf("\nEnter item in stack");
       scanf("%d",&n);
       top=top+1;
       stack[top]=n;
   }
}
void pop()
{
    int item;
    if(top==-1)
    {
       printf("\nStack if empty");
    }
    else
    {
       item=stack[top];
       printf("\nItem popped is:%d",item);
       top--;
    }
}
void display()
{
    int i;
    printf("\nItem in stack are");
    for(i=top;i>=0;i--)
    printf("\n%d",stack[i]);
}
void peek()
{
   printf("\nPeeked %d",stack[top]);
}
void main()
{
    int ch;
    //clrscr();
    while(1)
    {
       printf("\n\nStack Menu\n1. push\n2. pop\n3. peek\n4. display\n5. exit");
       printf("\nEnter the choice:");
       scanf("%d",&ch);
       switch(ch)
       {
	   case 1:push();break;
	   case 2:pop();break;
	   case 3:peek();break;
	   case 4:display();break;
	   case 5:exit(0);
       }
       getch();
  }
}